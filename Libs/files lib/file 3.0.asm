#comentario aleatorio
labelaleatoria:
	add $s0, $s1, $zero
	add $s1, $s2, $s0
	labelrandom: add $s2, $s1, $s0

	qualquer1: #testando captura da string completa
		add $s0 $zero $zero