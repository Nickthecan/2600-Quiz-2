//Tic Tac Toe game between two players or player vs. cpu
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
const char COMPUTER = 'O';

void singlePlayer();
void multiPlayer();
void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void player2Move();
void computerMove();
char checkWinner();
void printWinner(char);
void print2Winner(char);

int main() {
    int option = ' ';
    
    //prompt user if they want solo or multiplayer
    printf("Welcome to TicTacToe\nPlease choose an option\n--------------------------------------\nSingleplayer: Press 1\nMultiplayer : Press 2\n");
    //read information from console
    scanf("%d", option);

    if (option == 1) {
        singlePlayer();
    }

    if (option == 2) {
        multiPlayer();
    }

    return 0;
}

void singlePlayer() {
   //place holder for the winner
    char winner = ' ';

    //reset the board
    resetBoard();

    //for singleplayer
    while(winner == ' ' && checkFreeSpaces() != 0) {
        //show the board
        printBoard();   
        //allow player to choose which square they want
        //populate the square with x
        //update the board
        playerMove();
        winner = checkWinner(); //repeat until one person gets 3 in a row or all the squares fill up
        if (winner != ' ' || checkFreeSpaces() ==0) {
            break;
        }
        //the computer will choose a square by random (make sure it's empty tho)
        //populate the square with o
        //update the board
        computerMove();
        winner = checkWinner(); //repeat until one person gets 3 in a row or all the squares fill up
        if (winner != ' ' || checkFreeSpaces() ==0) {
            break;
        }
    }
    printBoard();
    printWinner(winner);
}

void multiPlayer() {
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

    //place holder for the winner
    char winner = ' ';

    //reset the board
    resetBoard();

    //for singleplayer
    while(winner == ' ' && checkFreeSpaces() != 0) {
        //show the board
        printBoard();   
        //allow player to choose which square they want
        //populate the square with x
        //update the board
        playerMove();
        winner = checkWinner(); //repeat until one person gets 3 in a row or all the squares fill up
        if (winner != ' ' || checkFreeSpaces() ==0) {
            break;
        }
        //the computer will choose a square by random (make sure it's empty tho)
        //populate the square with o
        //update the board
        player2Move();
        winner = checkWinner(); //repeat until one person gets 3 in a row or all the squares fill up
        if (winner != ' ' || checkFreeSpaces() ==0) {
            break;
        }
    }
    printBoard();
    print2Winner(winner);
}

void resetBoard() {
    //loop through the row
    for(int i = 0; i < 3; i++) {
        //loop through the column
        for (int j = 0; j < 3; j++) {
            //turn every x and o to an empty space
            board[i][j] = ' ';
        }
    }
}  //end resetBoard method

void printBoard() {
    //print out the board
    printf("\n %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}  //end printBoard method

int checkFreeSpaces() {
    //amount of spaces in the board
    int freeSpaces = 9;

    //loop through the row
    for(int i = 0; i < 3; i++) {
        //loop for the column
        for (int j = 0; j < 3; j++) {
            //test to see if the board has an empty space
            if (board[i][j] != ' ') {
                //decrement the amount of free spaces that are found on the board
                freeSpaces--;
            }
        }
    }
    //return the amount of free spaces 
    return freeSpaces;
}  //end checkFreeSpaces method

void playerMove() {
    //instantiating varaibles
    int x;
    int y;
    //do while loop to allow a player to enter their choice starting from row then column
    do {
        printf("Enter row number 1-3: ");
        scanf("%d", &x);
        x--;
        printf("Enter column number 1-3: ");
        scanf("%d", &y);
        y--;
        //if statement to make sure the user did not input their choice in a filled spot
        if(board[x][y] != ' ') {
            printf("Invalid Move!\n");
        }
        else {
            board[x][y] = PLAYER1;
            break;
        }
    }
    while (board[x][y] != ' ');
}  //end playerMove method

void player2Move() {
    //instantiating varaibles
    int x;
    int y;
    //do while loop to allow a player to enter their choice starting from row then column
    do {
        printf("Enter row number 1-3: ");
        scanf("%d", &x);
        x--;
        printf("Enter column number 1-3: ");
        scanf("%d", &y);
        y--;
        //if statement to make sure the user did not input their choice in a filled spot
        if(board[x][y] != ' ') {
            printf("Invalid Move!\n");
        }
        else {
            board[x][y] = PLAYER2;
            break;
        }
    }
    while (board[x][y] != ' ');
}  //end playerMove method

void computerMove() {
    //in order to generate random, use a seed based on current time
    srand(time(0));
    //instantiating variables
    int x;
    int y;
    //computer checks to see if the spaces are not all filled up
    if(checkFreeSpaces() > 0) {
        do {
            //random number in order to fill a row and column
            x = rand() % 3;
            y = rand() % 3;
        }
        while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
    }
    else {
        //no one wins yet
        printWinner(' ');
    }
}  //end computerMoves method

char checkWinner() {
    //check rows
    for(int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return board[i][0];
        }
    }
    //check columns
    for(int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[0][i];
        }
    }
    //check diagonals
     if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            return board[0][0];
        }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            return board[0][2];
        }
    return ' ';
} //end checkWinner method

void printWinner(char winner) {
    //if player 1 wins
    if (winner == PLAYER1) {
        printf("PLAYER 1 WINS!");
    }
    //if the computer wins
    else if (winner == COMPUTER) {
        printf("COMPUTER WINS!");
    }
    //if it is a tie
    else {
        printf("IT IS A TIE!");
    }
} //end printWinner method

void print2Winner(char winner) {
    //if player 1 wins
    if (winner == PLAYER1) {
        printf("PLAYER 1 WINS!");
    }
    //if player 2 wins
    else if (winner == PLAYER2) {
        printf("PLAYER 2 WINS!");
    }
    //if it is a tie
    else {
        printf("IT IS A TIE!");
    }
} //end print2Winner method

