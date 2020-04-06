	
	.data			;
StarSong:
	.word 0

	.text			;
switch:	.word case0		;
	.word case1		;
	.word case2		;
	.word case3		;
	.word case4		;
	.word case6		;
	.word case8		;
	.word case5		;
	.word case7		;
	.word case9		;
	.word case10		;
	.word case11		;
	.word case12		;
	.word case13		;
	.word case15		;
	.word case17		;
	.word case16		;
	.word case14		;

	.global starTheme
starTheme:
	cmp #18, &starSong	
	jnc case0		
	mov &starSong, r12
	add r12, r12
	mov switch(r12), r0

case1:
case2:
case3:
case4:
case6:
case8:	mov #950, r12
	call buzzer_set_period
	add #1, &starTheme
	jmp end
case5:
case7:	mov #1130, r12
	call buzzer_set_period
	add #1, &starTheme
	jmp end
case9:
case10:
case11:
case12:
case13:
case15:
case17:	mov #1000, r12
	call buzzer_set_period
	add #1, &starTheme
	jmp end
case14:
case16:	mov #1270, r12
	call buzzer_set_period
	add #1, &starTheme
	jmp end
	
end: pop r0	

	
	
	
