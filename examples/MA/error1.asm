# tests to see if assembler handles illegal labels
	ld	r1	negone	r0	# r1 = -1
loopestloopest	daddi	r1	r1	1	# r1 = r1 + 1 (label too long)
	beq	r1	r0	loopestloopest	# if r1 == 0 goto loopestloopest
	sd	r1	32	r0	# m[32] = r1
	halt
negone	.dfill	-1
result	.dfill	0
