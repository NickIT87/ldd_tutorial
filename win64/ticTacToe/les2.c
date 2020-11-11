#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int board [25] = {
	:,:,:,:,:,
	:,o,-,x,:,
	:,x,-,-,:,
	:,-,-,-,:,
	:,:,:,:,:,
}
*/

enum { NOUGHTS, CROSSES, BORDER, EMPTY };
enum { HUMANWIN, COMPWIN, DRAW };

const int ConvertTo25[9] = {
	6,7,8,
	11,12,13,
	16,17,18
};

/* les1 1 first function */
void InitialiseBoard(int *board) {
	int index = 0;
	for(index = 0; index < 25; ++index) {
		board[index] = BORDER;	
	}

	for(index = 0; index < 9; ++index) {
		board[ConvertTo25[index]] = EMPTY; 
	}
}
/* les1 2 second function */
void PrintBoard(const int *board) {
	int index = 0;
	printf("\nBoard:\n");
	for(index = 0; index < 25; ++index) {
		if(index!=0 && index%5==0) {
			printf("\n");
		}
		printf("%4d",board[index]);
	}
	printf("\n\n");
}
/* les2 3 third function */
void RunGame() {
	int GameOver = 0;
	int Side = NOUGHTS;
	int LastMoveMade = 0;
	int board[25];

	InitialiseBoard(&board[0]);
	PrintBoard(&board[0]);

	while(!GameOver) {
		if(Side==NOUGHTS) {
		// get move from human, make move on board, change side
		} else {
		// get move from computer, make move on board, change side
			PrintBoard(&board[0]);
		}
		// if three in a row exists Game is over
		// if no more moves, game is a draw
	}
}

int main() {
	
	srand(time(NULL));
	RunGame();

	return 0;
}
