# missing tab and spaces
	ld	r1	negone	r0	# r1 = -1
loop	daddi	r1r1	1	# r1 = r1 + 1  (missing tab and spaces)
	beq	r1	r0	loop	# if r1 == 0 goto loop
	nop
	sdd	r1	32	r0	# m[32] = r1  (sdd instead of sd)
	halt
negone	.dfill	-1
result	.dfill	0
