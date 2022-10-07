//Tic Tac Toe game between two players or player vs. cpu
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main() {

    
    //prompt user if they want solo or multiplayer
    printf("Welcome to TicTacToe\nPlease choose an option\n--------------------------------------\nSingleplayer: Press 1\nMultiplayer : Press 2");
    //read information from console

    //play 

    /*for multiplayer
        show the board
        allow player one to choose which square they want.
        populate the square with x
        update the board
        allow player two to choose which square they want.
        populate the square with o
        update the board
        repeat until one person gets 3 in a row
        or all the squares fill up
    */

    /*for singleplayer
        show the board
        allow player to choose which square they want
        populate the square with x
        update the board
        the computer will choose a square by random (make sure it's empty tho)
        populate the square with o
        update the board
        repeat until one person gets 3 in a row
        or all the squares fill up
    */
    return 0;
}

void resetBoard() {
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}