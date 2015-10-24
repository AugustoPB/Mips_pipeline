	.text
	.globl  main
	
main:
	lui	$at,0x00001001
	nop
	ori	$t0,$at,0x00000000
	lui	$at,0x00001001
	nop
	ori	$t1,$at,0x00000004
		
	
	li 	$s1,5
	li	$s2,4
	li 	$s0,100
	li	$s3,32
	
	addu	$s4,$s1,$s2
	subu	$s5,$s0,$s4
	addu	$s6,$s4,$s5
loop:
	beq	$s2,$s3,loop2
	nop
	nop
	nop
	nop
	sll	$s2,$s2,1
	addiu	$s7,$s7,1
	j	loop
	nop
	nop
	nop
	nop
	
loop2:
	addiu	$s5,$s5,1
	nop
	nop
	bne	$s5,$s0,loop2
	nop
	nop
	nop
	nop

fim:
	lw	$t2,0($t0)
	nop
	nop
	sw	$t2,0($t1)
	lw	$t3,0($t1)
	nop
	addiu	$t3,$t3,8
	nop
	nop
	sw	$t3,0($t0)
end:
	j	end
	
	.data
	
A:	.word	30
B:	.word	5
	
	
	
	
