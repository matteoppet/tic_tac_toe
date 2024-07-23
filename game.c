#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>


// GLOBAL VARIABLE
char table[3][3];
int winner;
char sign_player;
char sign_bot;


void player_turn();
void bot_turn();
void display_table();
void check_win();
void game();
void choose_sign();
void show_game_winner();


int main() {
	char start_game;
	
	printf("Do you want to start? (Y,n): ");
	scanf("%c", &start_game);

	if (tolower(start_game) == 'y') {
		choose_sign();
	} else {
		printf("Exited the game\n");
	}

	return 0;
}


void player_turn() {	
	int input_row_player;
	int input_col_player;
	bool continue_loop = true;

	printf("\n> Your turn\n");
	
	do {
		printf("Row: ");
		scanf("%d", &input_row_player);

		printf("Col: ");
		scanf(" %d", &input_col_player);

		if (tolower(table[input_row_player][input_col_player]) == tolower(sign_bot) || tolower(table[input_row_player][input_col_player] == tolower(sign_player))) {
			printf("Position already taken, try again\n");
		} else if (input_row_player > sizeof(table[0])/sizeof(table[0][0])-1) {
			printf("This row doesn't exists, try again\n");		
		} else if (input_col_player > sizeof(table[0])/sizeof(table[0][0])-1) {
			printf("This  col doesn't exists, try again\n");
		} else {
			table[input_row_player][input_col_player] = toupper(sign_player);
			
			continue_loop = false; 
		}
	} while (continue_loop);
}


void bot_turn() {
	printf("\n> Bot turn\n");
	
	int row_choosen;
	int col_choosen;

	srand(time(NULL));

	do {
		row_choosen = rand() % 3;
		col_choosen = rand() % 3;
		
	} while (tolower(table[row_choosen][col_choosen]) == tolower(sign_player) || tolower(table[row_choosen][col_choosen]) == tolower(sign_bot));

	table[row_choosen][col_choosen] = toupper(sign_bot);
}


void display_table() {
	printf("\t%c\t|\t%c\t|\t%c", table[0][0], table[0][1], table[0][2]);
	printf("\n");
	
	printf("\t-\t\t-\t\t-");
	printf("\n");

	printf("\t%c\t|\t%c\t|\t%c", table[1][0], table[1][1], table[1][2]);
	printf("\n");

	printf("\t-\t\t-\t\t-");
	printf("\n");
	
	printf("\t%c\t|\t%c\t|\t%c", table[2][0], table[2][1], table[2][2]);
	printf("\n");
}


void check_win() {
	// check rows
	for (int row = 0; row < 3; row++) {
		if (table[row][0] == table[row][1] && table[row][0] == table[row][2]) {
			if (table[row][0] == 'X' || table[row][0] == 'O') {
				winner = table[row][0];
				show_game_winner();
			}
		}	
	}
	
	// check columns 
	for (int col = 0; col < 3; col++) {
		if (table[0][col] == table[1][col] && table[0][col] == table[2][col]) {
			if (table[0][col] == 'X' || table[0][col] == 'O') {
				winner = table[0][col];
				show_game_winner();
			}
		}
	}
	
	// check diagonals
	if (table[0][0] == table[1][1] && table[0][0] == table[2][2]) {
		if (table[0][0] == 'X' || table[0][0] == 'O') {
			winner = table[0][0];
			show_game_winner();
		}
	} else if (table[0][2] == table[1][1] && table[0][2] == table[2][0]) {
		if (table[0][2] == 'X' || table[0][2] == 'O') {
			winner = table[0][2];
			show_game_winner();
		}
	}

}


void game() {
	char turn_to_play = 'X';
	display_table();
	
	do {
		if (turn_to_play == sign_player) {
			player_turn();
			turn_to_play = toupper(sign_bot);
		} else {
			bot_turn();
			turn_to_play = toupper(sign_player);
		}
		
		display_table();	

		check_win();

	} while (winner != 'X' && winner != 'O');
}


void choose_sign() {
	// Choose which sign be
	printf("\nChoose your sign (X or O): ");
	scanf(" %c", &sign_player);
	
	if (tolower(sign_player) == 'x' || tolower(sign_player) == 'o')	{
		if (tolower(sign_player) == 'x') {
			sign_bot = 'O';
		} else {
			sign_bot = 'X';
		}
	} else {
		printf("Sign not available.\n");
		exit(0);
	}

	printf("\nStarted game\n");
	game(sign_bot, sign_player);
}


void show_game_winner() {
	if (winner == sign_bot) {
		printf("\n\nYou lost, try next time!\n");
	} else {
		printf("\n\nCongratulation, you won!\n");
	}
}
