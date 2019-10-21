// 2.11.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Jaakko Oksanen 1706835
//battleship size : 4 amount : 1
//submarine size : 3 amount : 2
//patrol boat size : 2 amount : 3
#define _CRT_SECURE_NO_DEPRECATE
//#include "pch.h"
//#include "stdafx.h"
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>	

void game(int(*a)[10], int(*b)[10]);
int placeShips();
void pause(int turn);
int shoot(int* row, int* column);


int main(void) {
	int k = 0;

	do {
		printf("	=========================	\n");
		printf("	== THE BATTLESHIP GAME ==\n");
		printf("	=========================	\n");
		printf("\n");
		printf("\n");
		printf("Press 1 to start a new game!	\n");
		printf("-------------------------	\n");
		printf("Press 2 to Exit	\n");
		scanf("%d", &k);
		if (k == 1) {
			system("CLS");
			placeShips();
		}
	} while (k != 2);

	return 0;
}

void pause(int turn) {
	int c;
	int	d;
	char cont = 0;

	for (c = 1; c <= 32767; c++) {
		for (d = 1; d <= 32767; d++) {}		//pieni tauko
	}
	for (c = 1; c <= 32767; c++) {
		for (d = 1; d <= 32767; d++) {}		//pieni tauko
	}

	fseek(stdin, 0, SEEK_END);		// tyhjennä input buffer
	system("CLS");
	printf("Player %d press Enter to continue\n", turn);
	while ((cont = getchar()) != '\n') {}
}

int shoot(int* row, int* column) {
	int j = 0;
	int i = 0;
	do {
		printf("\n");
		printf("Where do you want to shoot?\n");
		printf("Give Row and Column:");
		scanf("%d %d", &i, &j);
		if (i >= 11 || j >= 11 || i <= 0 || j <= 0) {
			printf("That spot is not in the gameboard.\n");
			printf("Please give a numbers between 1 and 10.\n");
			for (int c = 1; c <= 32767; c++) {
				for (int d = 1; d <= 32767; d++) {}		//pieni tauko
			}
		}
		else {
			break;
		}

	} while (1);
	*row = i - 1;
	*column = j - 1;
	return *row, * column;
}


int placeShips() {
	int gameBoard[10][10];
	int gameBoard2[10][10];
	int i;
	int j;
	int patrolBoat = 3;
	int submarine = 2;
	int battleship = 1;
	char direction;

	for (i = 0; i < 10; ++i) {	// pelikentän teko
		for (j = 0; j < 10; ++j) {
			gameBoard[i][j] = 0;
		}
	}
	printf("You have:\n3 Patrol Boats (size 2)\n2 Submarines (size 3)\n1 Battleship (size 4) \n");
	printf("\n");
	printf("\n");
	printf("  Player 1 Place your ships!\n");
	printf("  First place your Patrol Boats.\n");
	printf("\n");

	for (i = 0; i < 10; ++i) {		//Pelikentän tulostus
		for (j = 0; j < 10; ++j) {
			printf(" %d ", gameBoard[i][j]);
		}
		printf("\n");
	}

	while (patrolBoat != 0) {		// Patrol Boat laittaminen
		printf("Where do you want to place your Patrol Boat number %d  ?\n", patrolBoat);
		printf("Enter two numbers, Row and Column: ");
		scanf("%d %d", &i, &j);
		fseek(stdin, 0, SEEK_END);	// tyhjennä input buffer
		printf("Do you want your ship to be horizontal (h) or vertical (v):  ");
		scanf("%c", &direction);
		printf("\n");
		printf("\n");

		if (direction == 'v') {
			if (i >= 1 && i <= 10 && j >= 1 && j <= 9) {

				if (gameBoard[i - 1][j - 1] == 0 && gameBoard[i - 1][j] == 0) {
					gameBoard[i - 1][j - 1] = 2;
					gameBoard[i - 1][j] = 2;
					patrolBoat--;
				}
				else {
					printf("Spot is taken by another boat or is too close to one!\n");
					printf("Please choose another spot!\n");
				}

				for (i = 0; i < 10; ++i) {		//Pelikentän tulostus
					for (j = 0; j < 10; ++j) {
						printf(" %d ", gameBoard[i][j]);
					}
					printf("\n");
				}
			}
			else {
				printf("The row and column must be between 1 and 10. \n");
			}
		}
		if (direction == 'h') {
			if (i >= 1 && i <= 9 && j >= 1 && j <= 10) {

				if (gameBoard[i - 1][j - 1] == 0 && gameBoard[i][j - 1] == 0) {
					gameBoard[i - 1][j - 1] = 2;
					gameBoard[i][j - 1] = 2;
					patrolBoat--;
				}
				else {
					printf("Spot is taken by another boat! please select another spot.\n");
				}

				for (i = 0; i < 10; ++i) {		//Pelikentän tulostus
					for (j = 0; j < 10; ++j) {
						printf(" %d ", gameBoard[i][j]);
					}
					printf("\n");
				}
			}
			else {
				printf("The row and column must be between 1 and 10. \n");
			}
		}
	}

	printf("\n");
	printf("\n");
	printf("Next place your Submarines!\n");

	while (submarine != 0) {		// Submarine laittaminen
		printf("Where do you want to place your Submarine number %d  ?\n", submarine);
		printf("Enter two numbers, Row and Column: ");
		scanf("%d %d", &i, &j);
		fseek(stdin, 0, SEEK_END);	// tyhjennä input buffer
		printf("Do you want your ship to be horizontal (h) or vertical (v):  ");
		scanf("%c", &direction);
		printf("\n");
		printf("\n");

		if (direction == 'v') {
			if (i >= 1 && i <= 10 && j >= 1 && j <= 8) {

				if (gameBoard[i - 1][j - 1] == 0 && gameBoard[i - 1][j] == 0 && gameBoard[i - 1][j + 1] == 0) {
					gameBoard[i - 1][j - 1] = 3;
					gameBoard[i - 1][j] = 3;
					gameBoard[i - 1][j + 1] = 3;
					submarine--;
				}
				else {
					printf("Spot is taken by another boat! please select another spot.\n");
				}

				for (i = 0; i < 10; ++i) {		//Pelikentän tulostus
					for (j = 0; j < 10; ++j) {
						printf(" %d ", gameBoard[i][j]);
					}
					printf("\n");
				}
			}
			else {
				printf("The row and column must be between 1 and 10.\n");
			}
		}
		if (direction == 'h') {
			if (i >= 1 && i <= 8 && j >= 1 && j <= 10) {

				if (gameBoard[i - 1][j - 1] == 0 && gameBoard[i][j - 1] == 0 && gameBoard[i + 1][j - 1] == 0) {
					gameBoard[i - 1][j - 1] = 3;
					gameBoard[i][j - 1] = 3;
					gameBoard[i + 1][j - 1] = 3;
					submarine--;
				}
				else {
					printf("Spot is taken by another boat! please select another spot.\n");
				}

				for (i = 0; i < 10; ++i) {		//Pelikentän tulostus
					for (j = 0; j < 10; ++j) {
						printf(" %d ", gameBoard[i][j]);
					}
					printf("\n");
				}
			}
			else {
				printf("The row and column must be between 1 and 10.\n");
			}
		}
	}
	printf("\n");
	printf("\n");
	printf("Now place your Battleship!\n");

	while (battleship != 0) {		// Battleship laittaminen
		printf("Where do you want to place your Battleship?\n");
		printf("Enter two numbers, Row and Column: ");
		scanf("%d %d", &i, &j);
		fseek(stdin, 0, SEEK_END);	// tyhjennä input buffer
		printf("Do you want your ship to be horizontal (h) or vertical (v):  ");
		scanf("%c", &direction);
		printf("\n");
		printf("\n");
		if (direction == 'v') {
			if (i >= 1 && i <= 10 && j >= 1 && j <= 7) {

				if (gameBoard[i - 1][j - 1] == 0 && gameBoard[i - 1][j] == 0 && gameBoard[i - 1][j + 1] == 0 && gameBoard[i - 1][j + 2] == 0) {
					gameBoard[i - 1][j - 1] = 4;
					gameBoard[i - 1][j] = 4;
					gameBoard[i - 1][j + 1] = 4;
					gameBoard[i - 1][j + 2] = 4;
					battleship--;
				}
				else {
					printf("Spot is taken by another boat! please select another spot.\n");
				}

				for (i = 0; i < 10; ++i) {		//Pelikentän tulostus
					for (j = 0; j < 10; ++j) {
						printf(" %d ", gameBoard[i][j]);
					}
					printf("\n");
				}
			}
			else {
				printf("The row and column must be between 1 and 10.\n");
			}
		}
		if (direction == 'h') {
			if (i >= 1 && i <= 7 && j >= 1 && j <= 10) {

				if (gameBoard[i - 1][j - 1] == 0 && gameBoard[i][j - 1] == 0 && gameBoard[i + 1][j - 1] == 0 && gameBoard[i + 2][j - 1] == 0) {
					gameBoard[i - 1][j - 1] = 4;
					gameBoard[i][j - 1] = 4;
					gameBoard[i + 1][j - 1] = 4;
					gameBoard[i + 2][j - 1] = 4;
					battleship--;
				}
				else {
					printf("Spot is taken by another boat! please select another spot.\n");
				}

				for (i = 0; i < 10; ++i) {		//Pelikentän tulostus
					for (j = 0; j < 10; ++j) {
						printf(" %d ", gameBoard[i][j]);
					}
					printf("\n");
				}
			}
			else {
				printf("The row and column must be between 1 and 10.\n");
			}
		}

	}
	printf("Player 1 you have placed all your boats! \n");
	pause(2);
	patrolBoat = 3;
	submarine = 2;
	battleship = 1;

	for (i = 0; i < 10; ++i) {	// pelikentän teko
		for (j = 0; j < 10; ++j) {
			gameBoard2[i][j] = 0;
		}
	}
	printf("You have:\n3 Patrol Boats (size 2)\n2 Submarines (size 3)\n1 Battleship (size 4) \n");
	printf("\n");
	printf("\n");
	printf("  Player 2 Place your ships!\n");
	printf("  First place your Patrol Boats.\n");
	printf("\n");

	for (i = 0; i < 10; ++i) {		//Pelikentän tulostus
		for (j = 0; j < 10; ++j) {
			printf(" %d ", gameBoard2[i][j]);
		}
		printf("\n");
	}

	while (patrolBoat != 0) {		// Patrol Boat laittaminen
		printf("Where do you want to place your Patrol Boat number %d  ?\n", patrolBoat);
		printf("Enter two numbers, Row and Column: ");
		scanf("%d %d", &i, &j);
		fseek(stdin, 0, SEEK_END);	// tyhjennä input buffer
		printf("Do you want your ship to be horizontal (h) or vertical (v):  ");
		scanf("%c", &direction);
		printf("\n");
		printf("\n");

		if (direction == 'v') {
			if (i >= 1 && i <= 10 && j >= 1 && j <= 9) {

				if (gameBoard2[i - 1][j - 1] == 0 && gameBoard2[i - 1][j] == 0) {
					gameBoard2[i - 1][j - 1] = 2;
					gameBoard2[i - 1][j] = 2;
					patrolBoat--;
				}
				else {
					printf("Spot is taken by another boat or is too close to one!\n");
					printf("Please choose another spot!\n");
				}

				for (i = 0; i < 10; ++i) {		//Pelikentän tulostus
					for (j = 0; j < 10; ++j) {
						printf(" %d ", gameBoard2[i][j]);
					}
					printf("\n");
				}
			}
			else {
				printf("The row and column must be between 1 and 10. \n");
			}
		}
		if (direction == 'h') {
			if (i >= 1 && i <= 9 && j >= 1 && j <= 10) {

				if (gameBoard2[i - 1][j - 1] == 0 && gameBoard2[i][j - 1] == 0) {
					gameBoard2[i - 1][j - 1] = 2;
					gameBoard2[i][j - 1] = 2;
					patrolBoat--;
				}
				else {
					printf("Spot is taken by another boat! please select another spot.\n");
				}

				for (i = 0; i < 10; ++i) {		//Pelikentän tulostus
					for (j = 0; j < 10; ++j) {
						printf(" %d ", gameBoard2[i][j]);
					}
					printf("\n");
				}
			}
			else {
				printf("The row and column must be between 1 and 10. \n");
			}
		}
	}
	printf("\n");
	printf("\n");
	printf("Next place your Submarines!\n");

	while (submarine != 0) {		// Submarine laittaminen
		printf("Where do you want to place your Submarine number %d  ?\n", submarine);
		printf("Enter two numbers, Row and Column: ");
		scanf("%d %d", &i, &j);
		fseek(stdin, 0, SEEK_END);	// tyhjennä input buffer
		printf("Do you want your ship to be horizontal (h) or vertical (v):  ");
		scanf("%c", &direction);
		printf("\n");
		printf("\n");

		if (direction == 'v') {
			if (i >= 1 && i <= 10 && j >= 1 && j <= 8) {

				if (gameBoard2[i - 1][j - 1] == 0 && gameBoard2[i - 1][j] == 0 && gameBoard2[i - 1][j + 1] == 0) {
					gameBoard2[i - 1][j - 1] = 3;
					gameBoard2[i - 1][j] = 3;
					gameBoard2[i - 1][j + 1] = 3;
					submarine--;
				}
				else {
					printf("Spot is taken by another boat! please select another spot.\n");
				}

				for (i = 0; i < 10; ++i) {		//Pelikentän tulostus
					for (j = 0; j < 10; ++j) {
						printf(" %d ", gameBoard2[i][j]);
					}
					printf("\n");
				}
			}
			else {
				printf("The row and column must be between 1 and 10.\n");
			}
		}
		if (direction == 'h') {
			if (i >= 1 && i <= 8 && j >= 1 && j <= 10) {

				if (gameBoard2[i - 1][j - 1] == 0 && gameBoard2[i][j - 1] == 0 && gameBoard2[i + 1][j - 1] == 0) {
					gameBoard2[i - 1][j - 1] = 3;
					gameBoard2[i][j - 1] = 3;
					gameBoard2[i + 1][j - 1] = 3;
					submarine--;
				}
				else {
					printf("Spot is taken by another boat! please select another spot.\n");
				}

				for (i = 0; i < 10; ++i) {		//Pelikentän tulostus
					for (j = 0; j < 10; ++j) {
						printf(" %d ", gameBoard2[i][j]);
					}
					printf("\n");
				}
			}
			else {
				printf("The row and column must be between 1 and 10.\n");
			}
		}
	}
	printf("\n");
	printf("\n");
	printf("Now place your Battleship!\n");

	while (battleship != 0) {		// Battleship laittaminen laittaminen
		printf("Where do you want to place your Battleship?\n");
		printf("Enter two numbers, Row and Column: ");
		scanf("%d %d", &i, &j);
		fseek(stdin, 0, SEEK_END);	// tyhjennä input buffer
		printf("Do you want your ship to be horizontal (h) or vertical (v):  ");
		scanf("%c", &direction);
		printf("\n");
		printf("\n");
		if (direction == 'v') {
			if (i >= 1 && i <= 10 && j >= 1 && j <= 7) {

				if (gameBoard2[i - 1][j - 1] == 0 && gameBoard2[i - 1][j] == 0 && gameBoard2[i - 1][j + 1] == 0 && gameBoard2[i - 1][j + 2] == 0) {
					gameBoard2[i - 1][j - 1] = 4;
					gameBoard2[i - 1][j] = 4;
					gameBoard2[i - 1][j + 1] = 4;
					gameBoard2[i - 1][j + 2] = 4;
					battleship--;
				}
				else {
					printf("Spot is taken by another boat! please select another spot.\n");
				}

				for (i = 0; i < 10; ++i) {		//Pelikentän tulostus
					for (j = 0; j < 10; ++j) {
						printf(" %d ", gameBoard2[i][j]);
					}
					printf("\n");
				}
			}
			else {
				printf("The row and column must be between 1 and 10.\n");
			}
		}
		if (direction == 'h') {
			if (i >= 1 && i <= 7 && j >= 1 && j <= 10) {

				if (gameBoard2[i - 1][j - 1] == 0 && gameBoard2[i][j - 1] == 0 && gameBoard2[i + 1][j - 1] == 0 && gameBoard2[i + 2][j - 1] == 0) {
					gameBoard2[i - 1][j - 1] = 4;
					gameBoard2[i][j - 1] = 4;
					gameBoard2[i + 1][j - 1] = 4;
					gameBoard2[i + 2][j - 1] = 4;
					battleship--;
				}
				else {
					printf("Spot is taken by another boat! please select another spot.\n");
				}

				for (i = 0; i < 10; ++i) {		//Pelikentän tulostus
					for (j = 0; j < 10; ++j) {
						printf(" %d ", gameBoard2[i][j]);
					}
					printf("\n");
				}
			}
			else {
				printf("The row and column must be between 1 and 10.\n");
			}
		}

	}
	printf("Player 2 you have placed all your boats! \n");
	pause(1);

	game(gameBoard, gameBoard2);
	return 0;
}

void game(int(*gameBoard)[10], int(*gameBoard2)[10]) {
	int i;
	int j;
	int row = 0;
	int column = 0;
	int player = 1;
	int shots[10][10];
	int shots2[10][10];
	int hits = 0;
	int hits2 = 0;

	for (i = 0; i < 10; ++i) {	// pelikentän teko
		for (j = 0; j < 10; ++j) {
			shots[i][j] = 0;
		}
	}
	for (i = 0; i < 10; ++i) {	// pelikentän teko
		for (j = 0; j < 10; ++j) {
			shots2[i][j] = 0;
		}
	}

	do {
		if (player == 1) {
			printf("Enemy shots are indicated by the number 7\n");
			printf("your current ship status:\n");
			printf("\n");
			for (i = 0; i < 10; ++i) {		//Pelikentän tulostus
				for (j = 0; j < 10; ++j) {
					printf(" %d ", gameBoard[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			printf("Hits are indicated by the number 1\n");
			printf("Misses are indicated by the number 8\n");
			printf("your shots:\n");

			for (i = 0; i < 10; ++i) {		//Pelikentän tulostus
				for (j = 0; j < 10; ++j) {
					printf(" %d ", shots[i][j]);
				}
				printf("\n");
			}
			printf("\n");

			shoot(&row, &column);

			if (gameBoard2[row][column] == 7) {
				printf("You have already shot there! Choose another spot.\n\n");
				for (int c = 1; c <= 32767; c++) {
					for (int d = 1; d <= 32767; d++) {}		//pieni tauko
				}
			}

			if (gameBoard2[row][column] == 0) {
				printf("\n");
				printf("You Missed.\n");
				shots[row][column] = 8;
				gameBoard2[row][column] = 7;
				player++;
				pause(2);
			}

			if (gameBoard2[row][column] >= 2 && gameBoard2[row][column] <= 4) {
				printf("\n");
				printf("You Hit!\n");
				printf("You get to shoot again!\n");
				for (int c = 1; c <= 32767; c++) {
					for (int d = 1; d <= 32767; d++) {}		//pieni tauko
				}
				printf("\n");
				shots[row][column] = 1;
				gameBoard2[row][column] = 7;
			}
		} // Player 1 loppu

		if (player == 2) {
			printf("Enemy shots are indicated by the number 7\n");
			printf("your current ship status:\n");
			printf("\n");
			for (i = 0; i < 10; ++i) {		//Pelikentän tulostus
				for (j = 0; j < 10; ++j) {
					printf(" %d ", gameBoard2[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			printf("Hits are indicated by the number 1\n");
			printf("Misses are indicated by the number 8\n");
			printf("your shots:\n");

			for (i = 0; i < 10; ++i) {		//Pelikentän tulostus
				for (j = 0; j < 10; ++j) {
					printf(" %d ", shots2[i][j]);
				}
				printf("\n");
			}
			printf("\n");

			shoot(&row, &column);

			if (gameBoard[row][column] == 7) {
				printf("You have already shot there! Choose another spot.\n\n");
				for (int c = 1; c <= 32767; c++) {
					for (int d = 1; d <= 32767; d++) {}		//pieni tauko
				}
			}

			if (gameBoard[row][column] == 0) {
				printf("\n");
				printf("You Missed.\n");
				shots2[row][column] = 8;
				gameBoard[row][column] = 7;
				player--;
				pause(1);
			}

			if (gameBoard[row][column] >= 2 && gameBoard[row][column] <= 4) {
				printf("\n");
				printf("You Hit!\n");
				printf("You get to shoot again!\n");
				for (int c = 1; c <= 32767; c++) {
					for (int d = 1; d <= 32767; d++) {}		//pieni tauko
				}
				printf("\n");
				shots2[row][column] = 1;
				gameBoard[row][column] = 7;
			}
		}

		for (i = 0; i < 10; ++i) {			//tarkistetaan onko voittajaa
			for (j = 0; j < 10; ++j) {
				if (shots[i][j] == 1) {
					hits++;
				}
				if (shots2[i][j] == 1) {
					hits2++;
				}
			}
		}
		if (hits == 16) {		//jos pelaajalla on 16 osumaa shots taulussa hän on voittaja
			printf("\n");
			printf("============================\n");
			printf("========= Game over! ========\n");
			printf("   Player 1 is the Winner !\n");
			for (int c = 1; c <= 32767; c++) {
				for (int d = 1; d <= 32767; d++) {}		//pieni tauko
			}
			break;
		}
		if (hits2 == 16) {
			printf("\n");
			printf("============================\n");
			printf("========= Game over! ========\n");
			printf("   Player 2 is the Winner !\n");
			for (int c = 1; c <= 32767; c++) {
				for (int d = 1; d <= 32767; d++) {}		//pieni tauko
			}
			break;
		}
		hits = 0;
		hits2 = 0;
	} while (1);

}