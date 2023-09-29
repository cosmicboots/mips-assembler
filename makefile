SOURCES := $(wildcard *.cpp)
BUILD = build
OBJECTS := $(patsubst %.cpp,$(BUILD)/%.o,$(SOURCES))
CC = g++
CFLAGS = -g -c -Wall -Wextra -std=c++11

$(BUILD)/%.o: %.cpp
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) $< -o $@

build: $(OBJECTS)
	mkdir -p $(BUILD)
	$(CC) $(OBJECTS) -o $(BUILD)/main

run: build $(BUILD)/main
	@./$(BUILD)/main example.asm

fmt:
	clang-format -i $(SOURCES)

clean:
	rm -rf $(BUILD)

.PHONY: clean
