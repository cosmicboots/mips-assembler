#illegal register number
	ld	r2	num	r0	# r2 = 10
loop	daddi	r2	r32	-1	# r2 = r2 - 1  (register must be r0-r31)
	beq	r2	r0	end	# if r2 == 0 goto end
	nop
	j	loop	# goto loop
	nop
end	halt
num	.dfill	10
