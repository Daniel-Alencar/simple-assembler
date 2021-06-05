qualquer1: add $s0 $zero $zero
qualquer2: add $s1 $zero $zero
qualquer3: addi $t0 $zero 6
qualquer4: addi $t1 $zero 12
qualquer5: addi $t2 $zero 3
qualquer6: beq $t0 $zero exit
qualquer7: add $s0 $s0 $t1
qualquer8: add $t1 $t1 $t2
qualquer9: addi $t0 $t0 -1
qualquer10:	j volta
