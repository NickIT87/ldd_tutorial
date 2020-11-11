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
	6, 7, 8,
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
	char pceChars[] = "OX|-";
	printf("\n\nBoard:\n\n");
	for(index = 0; index < 9; ++index) {
		if(index!=0 && index%3==0) {
			printf("\n\n");
		}
		printf("%4c",pceChars[board[ConvertTo25[index]]]);
	}
	printf("\n\n");
}

/* les3 5 five function */
int HasEmpty(const int *board) {
	int index = 0;

	for(index = 0; index < 9; ++index) {
		if(board[ConvertTo25[index]] == EMPTY) return 1;
	}
	return 0;
}

/* les3 4 four function */
void MakeMove(int *board, const int sq, const side) {
	board[sq] = side;
}

/* les4 6 six function */
int GetHumanMove(const int *board) {
	
	char userInput[4];

	int moveOk = 0;
	int move = -1;

	while (moveOk == 0) {

		printf("Please enter a move from 1 to 9:");
		fgets(userInput, 3, stdin);
		fflush(stdin);
		
		if(strlen(userInput) != 2) {
			printf("Invalid strlen()\n");
			continue;
		}

		if(sscanf(userInput, "%d", &move) != 1) {
			move = -1;
			printf("Invalid sscanf()\n");
			continue;
		}

		if(move < 1 || move > 9) {
			move = -1;
			printf("Invalid range\n");
			continue;
		}
		
		move--; /* Zero indexing */

		if(board[ConvertTo25[move]]!=EMPTY) {
			move=-1;
			printf("Square not available\n");
			continue;
		} 
		moveOk = 1;
	}
	printf("Making Move...%d\n",(move+1));
	return ConvertTo25[move];
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
			GetHumanMove(&board[0]);
		} else {
		// get move from computer, make move on board, change side
			PrintBoard(&board[0]);
		}
		// if three in a row exists Game is over
		
		// if no more moves, game is a draw
		
		GameOver = 1; // REMOVE ME !!
	}
}

int main() {
	
	srand(time(NULL));
	RunGame();

	return 0;
}
