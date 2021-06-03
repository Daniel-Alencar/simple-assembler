main:
	add $s0 $zero $zero
	add $s1 $zero $zero
	addi $t0 $zero 6
	addi $t1 $zero 12
	addi $t2 $zero 3
	
	volta:
		beq $t0 $zero exit
	
		add $s0 $s0 $t1
		add $t1 $t1 $t2
		addi $t0 $t0 -1
	j volta
exit:
