addi $s0,$s1,18
beq $s0,$s1,exit
bne $s0,$s1,for
lw $s0,56($s1)
sw $s0,9($s2)