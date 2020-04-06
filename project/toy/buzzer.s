	        .data		;
starSong:	.word 0

	.text			;
jt:	.word case0		;
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
starTheme:	cmp #4, &starSong ;
	
	
	
	
