#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

enum { ROW = 3, COL = 3};

void print_board(char board[static 3][3]);
void computer_move(char board[static 3][3]);
void user_move(char board[static 3][3]);
bool there_is_a_winner(char board[static 3][3]);

int
main(void)
{
	srand((unsigned) time(NULL));
	char board[3][3];

	for(int i = 0; i < ROW; ++i)
		for(int j = 0; j < COL; ++j)
			board[i][j] = ' ';

	print_board(board);
	for(;;) {
		user_move(board);
		print_board(board);
		if(there_is_a_winner(board)) {
			puts("you win");
			break;
		}
		computer_move(board);
		print_board(board);
		if(there_is_a_winner(board)) {
			puts("computer win");
			break;
		}
	}
	return EXIT_SUCCESS;
}


void
print_board(char board[static 3][3])
{
	printf("\n%c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
	puts("--+---+--");
	printf("%c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
	puts("--+---+--");
	printf("%c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

void
user_move(char board[static 3][3])
{
	int row = 0;
	int col = 0;

	do {
		printf("Pick cell (1-9): ");
		int cell = getchar() - '0';
		getchar();
		row = (cell - 1) / 3;
		col = (cell - 1) % 3;
	} while(board[row][col] != ' ');
	board[row][col] = 'O';
}

void
computer_move(char board[static 3][3])
{

	/* row */
	for(int i = 0; i < ROW; ++i) {
		for(int j = 0; j < COL - 1; ++j) {
			if(board[i][j] != ' ' && board[i][j] == board[i][j+1]
			   && board[i][(j+2) % 3] == ' ') {
				board[i][(j+2) % 3] = 'X';
				return;
			}
		}

	}

	/* columns */
	for(int j = 0; j < COL; ++j) {
		for(int i = 0; i < ROW - 1; ++i) {
			if(board[i][j] != ' ' && board[i+1][j] == board[i][j]
			   && board[(i+2) % 3][j] == ' ') {
				board[(i+2)%3][j] = 'X';
				return;
			}
		}
	}

	/* first diagonal */
	for(int i = 0; i < ROW - 1; ++i) {
		if(board[i][i] == 'O' && board[i+1][i+1] == 'O'
		   && board[(i+2) % 3][(i+2) % 3] == ' ') {
			board[(i+2)%3][(i+2)%3] = 'X';
			return;
		}
	}

	/* second diagonal */
	for(int i = 0; i < ROW - 1; ++i) {
		if(board[i][2-i] == 'O' && board[i+1][2-i-1] == 'O'
		   && board[(i+2) % 3][(3-i) % 3] == ' ') {
			board[(i+2)%3][(3-i)%3] = 'X';
			return;
		}
	}

	int user_occupied_cell = 0;
	int computer_occupied_cell = 0;

	/* adiacent cell */
	for(int i = 0; i < ROW; ++i) {
		for(int j = 0; j < COL; ++j) {
			if(board[i][j] == ' ') {
				for(int k = i-1; k <= i+1; ++k) {
					for(int l = j-1; l <= j+1; ++l) {
						if(k >= 0 && k < ROW && l >= 0
						   && l < COL && board[k][l] == 'X')
							++computer_occupied_cell;
						else if(k >= 0 && k < ROW && l >= 0
							&& l < COL && board[k][l] == 'O')
							++user_occupied_cell;
					}
				}
			}

			if(computer_occupied_cell >= 2|| user_occupied_cell >= 2) {
				board[i][j] = 'X';
				return;
			}
		}
	}

	if(board[1][1] == ' ') {
		board[1][1] = 'X';
		return;
	}

	if(board[0][0] == '0') {
		board[2][2] = 'X';
		return;
	} else if(board[0][2] == 'O') {
		board[2][0] = 'X';
		return;
	} else if(board[2][0] == 'O') {
		board[0][2] = 'X';
		return;
	} else if(board[2][2] == 'O') {
		board[0][0] = 'X';
		return;
	} else if(board[0][0] == ' ') {
		board[0][0] = 'X';
		return;
	} else if(board[0][2] == ' ') {
		board[0][2] = 'X';
		return;
	} else if(board[2][0] == ' ') {
		board[2][0] = 'X';
		return;
	} else if(board[2][2] == ' ') {
		board[2][2] = 'X';
		return;
	}

	int cell = rand() % 9;
	int i = cell / 3;
	int j = cell % 3;
	while(board[i][j] != ' ') {
		cell = rand() % 9;
		i = cell / 3;
		j = cell % 3;
	}
}

bool
there_is_a_winner(char board[static 3][3])
{
	for(int i = 0; i < ROW; ++i) {
		if(board[i][0] != ' ' && board[i][0] == board[i][1]
		   && board[i][1] == board[i][2]) {
			return true;
		}
	}

	for(int i = 0; i < COL; ++i) {
		if(board[0][i] != ' ' && board[0][i] == board[1][i]
		   && board[1][i] == board[2][i]) {
			return true;
		}
	}

	if(board[0][0] != ' ' && board[0][0] == board[1][1]
	   && board[1][1] == board[2][2]) {
		return true;
	}

	if(board[2][0] != ' ' && board[2][0] == board[1][1]
	   && board[1][1] == board[2][0]) {
		return true;
	}

	return false;
}
