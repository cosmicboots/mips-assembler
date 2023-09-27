#illegal label in instruction
	ld	r2	nu*m	r0	# r2 = 10	#* not allowed
loop	daddi	r2	r2	-1	# r2 = r2 - 1
	beq	r2	r0	end	# if r2 == 0 goto end
	nop
	j	loop	# goto loop
	nop
end	halt
num	.dfill	10
