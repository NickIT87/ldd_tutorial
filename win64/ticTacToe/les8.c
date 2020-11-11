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

	0, 1, 2, 3, 4,
	5, 6, 7, 8, 9,
	10,11,12,13,14,
	15,16,17,18,19,
	20,21,22,23,24
}
*/

enum { NOUGHTS, CROSSES, BORDER, EMPTY };
enum { HUMANWIN, COMPWIN, DRAW };

const int Directions[4] = { 1, 5, 4, 6 };

const int ConvertTo25[9] = {
	6, 7, 8,
	11,12,13,
	16,17,18
};

const int InMiddle = 4;
const int Corners[4] = { 0, 2, 6, 8 };

/* les6 8 eight function */
int GetNumForDir(int startSq, const int dir, const int *board, const int us) {
	int found = 0;
	while(board[startSq] != BORDER) {
		if(board[startSq] != us) {
			break;
		}
		found++;
		startSq += dir;
	}
	return found;
}

/* les6 9 nine function */
int FindThreeInARow(const int *board, const int ourindex, const int us) {
	
	int DirIndex = 0;
	int Dir = 0;
	int threeCount = 1;

	for(DirIndex = 0; DirIndex < 4; ++DirIndex) {
		Dir = Directions[DirIndex];
		threeCount += GetNumForDir(ourindex + Dir, Dir, board, us);
		threeCount += GetNumForDir(ourindex + Dir * -1, Dir * -1, board, us);
		if(threeCount == 3) {
			break;
		}
		threeCount = 1;
	}
	return threeCount;
}

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

int GetNextBest(const int *board) {

	int ourMove = ConvertTo25[InMiddle];
	if(board[ourMove] == EMPTY) {
		return ourMove;
	}
	
	int index = 0;
	ourMove = -1;

	for(index = 0; index < 4; index++) {
		ourMove = ConvertTo25[Corners[index]];
		if(board[ourMove] == EMPTY) {
			break;
		}
		ourMove = -1;
	}
	return ourMove;
}

/* les7 10 ten function */
int GetWinningMove(int *board, const int side) {
	int ourMove = -1;
	int winFound = 0;
	int index = 0;

	for(index = 0; index < 9; ++index) {
		if(board[ConvertTo25[index]] == EMPTY) {
			ourMove = ConvertTo25[index];
			board[ourMove] = side;

			if(FindThreeInARow(board, ourMove, side) == 3) {
				winFound = 1;
			}
			board[ourMove] = EMPTY;
			if(winFound == 1) {
				break;
			}
			ourMove = -1;
		};
	}
	return ourMove;
}

/* les5 7 seven function */
int GetComputerMove(int *board, const int side) {
	int index = 0;
	int numFree = 0;
	int availableMoves[9];
	int randMove = 0;

	randMove = GetWinningMove(board, side);
	if(randMove != -1) {
		return randMove;
	}

	randMove = GetWinningMove(board, side ^ 1);
	if(randMove != -1) {
		return randMove;
	}

	randMove = GetNextBest(board);
	if(randMove != -1) {
		return randMove;
	}	

	/* 2,4,8
		availableMoves[0] = 2 numFree++ -> 1;
		availableMoves[numFree] = 4 numFree++ -> 2;
		availableMoves[numFree] = 8 numFree++ -> 3;

		rand() % numFree gives 0 to 2
	
		rand from 0 to 2, return availableMoves[rand]
	*/
	
	randMove = 0;
	for(index = 0; index < 9; ++index) {
		if(board[ConvertTo25[index]] == EMPTY) {
			availableMoves[numFree++] = ConvertTo25[index];
		};
	}
	
	randMove = (rand() % numFree);
	return availableMoves[randMove];	
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
			LastMoveMade = GetHumanMove(&board[0]);
			MakeMove(&board[0],LastMoveMade,Side);
			Side=CROSSES;
		} else {
		// get move from computer, make move on board, change side
			LastMoveMade = GetComputerMove(&board[0], Side);
			MakeMove(&board[0],LastMoveMade,Side);
			Side=NOUGHTS;
			PrintBoard(&board[0]);
		}
		// if three in a row exists Game is over
		if(FindThreeInARow(board, LastMoveMade, Side ^ 1) == 3) {
			printf("Game over!\n");
			GameOver = 1;
			if(Side==NOUGHTS) {
				printf("Computer Wins!\n");
			} else {
				printf("Human Wins!\n");
			}
		}
		
		// if no more moves, game is a draw
		if(!HasEmpty(board)) {
			printf("Game over!\n");
			GameOver = 1;
			printf("It's a draw\n");
		}	
	}
	PrintBoard(&board[0]);
}

int main() {
	
	srand(time(NULL));
	RunGame();

	return 0;
}
