	.text
	.globl  main
	
main:
	la	$t0,A
	la	$t1,B
		
	li 	$s0,100
	li 	$s1,5
	li	$s2,4
	li	$s3,32
	
	addu	$s4,$s1,$s2
	subu	$s5,$s0,$s4
	addu	$s6,$s4,$s5
loop:
	beq	$s2,$s3,loop2
	sll	$s2,$s2,1
	addiu	$s7,$s7,1
	j	loop
	
loop2:
	addiu	$s5,$s5,1
	bne	$s5,$s0,loop2

fim:
	lw	$t2,0($t0)
	sw	$t2,0($t1)
	lw	$t3,0($t1)
	nop
	addiu	$t3,$t3,8
	sw	$t3,0($t0)
end:
	j	end
	
	.data
	
A:	.word	30
B:	.word	5
	
	
	
	