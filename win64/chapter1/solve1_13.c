#include <stdio.h>

#define MAXHIST 15
#define MAXWORD 11
#define IN 1
#define OUT 0

main() 
{
	int c, i, nc, state;
	int len; 
	int maxvalue; 			/* max value for wl[i] */
	int ovflow;				/* quantity of too long words */
	int wl[MAXWORD];		/* words length count */

	state = OUT;
	nc = 0;			/* number of characters in a word */
	ovflow = 0;		/* number of words >= MAXWORD */

	for (i=0; i<MAXWORD; ++i)
		wl[i] = 0;
	while ((c = getchar()) != EOF) {
		if (c==' '||c=='\n'||c=='\t') {
			state = OUT;
		if (nc > 0) {
			if (nc < MAXWORD)
				++wl[nc];
			else
				++ovflow;
				nc = 0;
		} else if (state==OUT) {
			state = IN;
			nc = 1;
		} else
			++ nc;
	}
	maxvalue = 0;
	for (i=1; i<MAXWORD; ++i) {
		if (wl[i] > maxvalue)
			maxvalue = wl[i];
	}
	for (i=1; i<MAXWORD; ++i) {
		printf("%5d - %5d: ", i, wl[i]);
		if (wl[i] > 0) {
			if ((len = wl[i] * MAXHIST / maxvalue) <= 0)
				len = 1;
		} else
			len = 0;
		while (len > 0) {
			putchar('*');
			--len;
		}
		putchar('\n');
	}
	if (ovflow > 0){
		printf("Обнаружено %d слов >= %d\n", ovflow, MAXWORD);
	}
}}

