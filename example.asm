 ld r1 sum r0
 ld r2 ten r0
 daddi r3 r0 0
loop dadd r1 r1 r3
 daddi r3 r3 1
 beq r3 r2 end
 j loop
end halt
sum .dfill 0
ten .dfill 10
