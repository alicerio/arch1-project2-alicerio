	.arch msp430g2553
	.p2align 1,0

	.text

jt:
	.word default		;
	.word case1		;
	.word case2		;
	.word case3		;
	.word case4		;

	.global next_state

next_state:
	mov #5, r13
	mov &switch_state, r12
	cmp r12, r13
	jnc default
	add r12, r12
	mov jt(r12), r0

default:

case1:
	call SecondTheme
	jmp out

case2:
	call ironManTheme
	jmp out

case3:
	call starTheme
	jmp out

case4:	call FirstTheme
	jmp out

out:	pop r0
	
