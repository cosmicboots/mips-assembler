# tests to see if assembler handles illegal labels
	ld	r1	negone	r0	# r1 = -1
loop:   daddi	r1	r1	1	# r1 = r1 + 1 (label has a colon)
	beq	r1	r0	loop	# if r1 == 0 goto loop
	nop
	sd	r1	32	r0	# m[32] = r1
	halt
negone	.dfill	-1
result	.dfill	0
