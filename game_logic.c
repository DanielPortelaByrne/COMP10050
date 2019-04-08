/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "game_init.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printLine();

/*
 * Returns the first letter associated with the color of the token
 * 
 * Input: t - pointer to a token
 * Output: initial of the color of the token
 */
char print_token(token *t){
    if((*t).col== PINK) return 'P';
    if((*t).col== RED) return 'R';
    if((*t).col== BLU) return 'B';
    if((*t).col== GREEN) return 'G';
    if((*t).col== ORANGE) return 'O';
    if((*t).col== YELLOW) return 'Y';
    return '\0';
}

/*
 * Prints the board
 * 
 * Input: the board to be printed. 
 */
void print_board(square board[NUM_ROWS][NUM_COLUMNS]){
    printf("                THE BOARD\n");
    for(int i =0; i < NUM_ROWS; i++){
       
        //prints an horizontal line
        printLine();
        //prints the row number
        printf(" %d ", i);
        char c = '\0' ;
        //if the square (i,j) is occupied,
        //c is assigned the initial of the color of the token that occupies the square
        for (int j = 0; j < NUM_COLUMNS; j++){
            if(board[i][j].stack != NULL){
                c = print_token(board[i][j].stack);
            }
            //if the square (i,j) is empty
            else{
                //c is assigned 'X' if the square represents an obstacle
                if(board[i][j].type == OBSTACLE)
                    c = 'X';
                //c is assigned an empty space otherwise
                else c = ' ';
            }
            printf("| %c ", c);
        }
        printf ("|\n");
    }
    printLine();
    //prints the number of the columns at the end of the board
    printf("     0   1   2   3   4   5   6   7   8\n");
}

void printLine(){
  printf("   -------------------------------------\n");  
}

/*
 * Place tokens in the first column of the board
 * 
 * Input: board - a 6x9 array of squares that represents the board
 *        players - the array of the players
 *        numPlayers - the number of players  
 */
void place_tokens(square board[NUM_ROWS][NUM_COLUMNS], player players[], int numPlayers){
    
        /*  INSTRUCTIONS: (hi dan <3) 
                Allow players to only put their token on the first column
                Ensure players do not put their token on top of a token of same colour
                Ensure playesr put their token in a square that has the minimum no. of tokens in it
                (Hint: Each square must keep track of how many tokens are in it, may require modification to struct square in game_init.h)
                
                minNumOfTokens should be incremented by ONE every time 6 (6=NUM_ROWS) or a mult of 6 tokens are placed in the squares of the first column.
    */

    //keeps track of the min no. of tokens placed on a square in the first column
    int minNumOfTokens= 0;
    int selectedSquare= 0;

    for(int i=0; i<4; i++){ //these for loops ensure each player places their tokens on the first column
        for(int j=1; j<numPlayers+1; j++){

            printf("Player %d please select a square\n", j);
            scanf("%d", &selectedSquare);

            /*TO BE IMPLEMENTED: if square contains min no. of tokens and does not have a token of the same color of the player.
              VERIFY whether the square selected has the min. no. and whether it does not contain a token of the same color selected by the player. */

            board[selectedSquare][0].stack = (token*) malloc(sizeof(token));
            board[selectedSquare][0].stack->col = players[j].col;
            board[selectedSquare][0].numTokens++; //example instructions to add token to square. Overwrites an already placed token (should not ultimately do this I think, simply an assumption)

            //updates the minimum number of tokens
            if(((numPlayers*i) +j +1)% NUM_ROWS==0)
                minNumOfTokens++;
        }
    }

}


/*
 * Place tokens in the first column of the board
 * 
 * Input: board - a 6x9 array of squares that represents the board
 *        players - the array of the players
 *        numPlayers - the number of players  
 */

void play_game(square board[NUM_ROWS][NUM_COLUMNS], player players[], int numPlayers){
    //function should manage the turns of the game

    /* For each player this func should:
     * 1. Roll the dice
     * 2. Optionally ask player to move one of their tokens up or down
     * 3. Move right any token placed in a row number equal to the no. rolled with the dice
          If a player moves their own token to the last column, the numTokensLastCol of the...
          player should be incremented. If that is equal to 3 the game ends of the func...
          should return the no. of the winning player. */

    int dice=0;
    char option;
    srand(time(NULL));

    for(int i=0; i<numPlayers; i++)
    {
    //dice roll
    dice = rand() % 6;
    dice++; //eliminates possibility of dice rolling a zero

    printf("\n%s has rolled the dice and got %d", players[i].name, dice);
    printf("\n%s, would you like to move one of your tokens up or down?\n(Optional: Enter (y) for yes, (n) for no): ", players[i].name);
    scanf(" %c", &option);
    }
}


