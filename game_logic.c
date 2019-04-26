#include "game_init.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int value;

    int row;

    int column;

    int minNumOfTokens= 0;
    
    int selectedSquare= 0;

    char col[7][7] = {"Red", "Blue", "Green", "Yellow", "Pink", "Orange", "\0"};

void printLine();

/*
 * Returns the first letter associated with the color of the token
 * 
 * Input: t - pointer to a token
 * Output: initial of the color of the token
 */
char print_token(token *t)
{
    if((*t).col== PINK) return 'P';
    if((*t).col== RED) return 'R';
    if((*t).col== BLUE) return 'B';
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
void print_board(square board[NUM_ROWS][NUM_COLUMNS])
{
    printf("                THE BOARD\n");
    for(int i =0; i < NUM_ROWS; i++){
       
        //prints a horizontal line
        printLine();
        //prints the row number
        printf(" %d ", i);
        char c = '\0' ;
        //if the square (i,j) is occupied,
        //c is assigned the initial of the color of the token that occupies the square
        for (int j = 0; j < NUM_COLUMNS; j++)
        {
            if(board[i][j].stack != NULL)
            {
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

void printLine()
{
  printf("   -------------------------------------\n");
}


struct token * push(square board[NUM_ROWS][NUM_COLUMNS], int value, int row, int column)
{
    struct token *curr = board[row][column].stack; //top is a pointer to the top of the stack
    board[row][column].stack = malloc(sizeof(token)); //creates a new node which top points to
    board[row][column].stack->col = value; //value is integer value of element to be pushed to stack!
    board[row][column].stack->next = curr; //current/original top goes to next value?
    board[selectedSquare][0].numTokens++;
    return board[row][column].stack; //return new top of stack
}

struct token * pop(square board[NUM_ROWS][NUM_COLUMNS], int value, int row, int column)
{
    struct token *curr = board[row][column].stack;
    if(curr!=NULL)
    {
        board[row][column].stack = curr->next;
        printf("Stack Data: %d\n", curr->col);
        free(curr);
        board[row][column].numTokens--;
    }
    return board[row][column].stack;
}

/*
 * Place tokens in the first column of the board
 * 
 * Input: board - a 6x9 array of squares that represents the board
 *        players - the array of the players
 *        numPlayers - the number of players  
 */
void place_tokens(square board[NUM_ROWS][NUM_COLUMNS], player players[], int numPlayers)
{
    
        /*  INSTRUCTIONS: (hi dan <3)
                Allow players to only put their token on the first column
                Ensure players do not put their token on top of a token of same colour
                Ensure playesr put their token in a square that has the minimum no. of tokens in it
                (Hint: Each square must keep track of how many tokens are in it, may require modification to struct square in game_init.h)
                
                minNumOfTokens should be incremented by ONE every time 6 (6=NUM_ROWS) or a mult of 6 tokens are placed in the squares of the first column.
    */

    //keeps track of the min no. of tokens placed on a square in the first column
    
    for(int i=0; i<4; i++)
    { //these for loops ensure each player places their tokens on the first column
        for(int j=0; j<numPlayers; j++)
        {

            HERE: printf("%s, your token colour is %s, please select a square of the leftmost column (squares numbered 0-5)\n",  players[j].name, col[j]);
            scanf("%d", &selectedSquare);

            /*TO BE IMPLEMENTED: if square contains min no. of tokens and does not have a token of the same color of the player.
              VERIFY whether the square selected has the min. no. and whether it does not contain a token of the same color selected by the player. */
            
            if(board[selectedSquare][0].numTokens == minNumOfTokens)
            {
                if(minNumOfTokens>=1 && board[selectedSquare][0].stack->col == players[j].col)
                {
                    printf("You cannot place on your own token!\n\n");
                    goto HERE;
                }
                //pointer to the top of the stack
                //board[row][column].stack = NULL; ************
                //pointer to the current element of the stack
                //struct token *curr = NULL; *******************************************************************************
                value = j;
                push(board, value, selectedSquare, 0);
                //initlialise location of specific coloured token on board
                //location = 0;
                //players[j].tokens[i].col[j].location;
                //eg. token colour red is specific to location 00

                //updates the minimum number of tokens
                if(((numPlayers*i) +j +1)% NUM_ROWS==0)
                {
                    minNumOfTokens++;
                }
            }

            else
            {
                printf("There is already a token on this square! You may only stack tokens when there are no more available squares on the first column.\n");
                goto HERE;
            }
        

            print_board(board);

        }
    }
}

void play_game(square board[NUM_ROWS][NUM_COLUMNS], player players[], int numPlayers)
{
    int colu = 0;
    //function should manage the turns of the game

    /* For each player this function should:
     * 1. Roll the dice
     * 2. Optionally ask player to move one of their tokens up or down
     * 3. Move right any token placed in a row number equal to the no. rolled with the dice
          If a player moves their own token to the last column, the numTokensLastCol of the...
          player should be incremented. If that is equal to 3 the game ends of the func...
          should return the no. of the winning player. */

    int dice=0;
    char option;
    int selectedSquare=0;
    char updown;
    
    srand(time(NULL)); //seeds rand to current time
    GAME: for(int i=0; i<numPlayers; i++)
    {
        //dice roll
        dice = rand() % 6;
         //eliminates possibility of dice rolling a zero

        printf("%s has rolled the dice and got %d\n", players[i].name, dice);
        printf("%s, would you like to move one of your tokens up or down?\n(Optional: Enter (y) for yes, (n) for no): ", players[i].name);
        scanf(" %c", &option);
        printf("\n");

        //moving token up or down on first column
        if(option == 'y')
        {
            CHOICE: printf("Which token would you like to move? (enter square number): ");
            scanf("%d", &selectedSquare);

            if(board[selectedSquare][0].stack->col != players[i].col)
                {
                    printf("You can only move your own token colour!\n\n");
                    goto CHOICE;
                }

            printf("Would you like to move the token up (enter u) or down (enter d)? : ");
            scanf(" %c", &updown);

            if(updown == 'u')
            {
                if(selectedSquare==0)
                {
                    printf("This token is at the top of the column and can only be moved down!\n\n");
                    goto CHOICE;
                }
                else if(minNumOfTokens>=1 && board[selectedSquare][0].stack->col == players[i].col)
                {
                    printf("You cannot stack on top of your own token colour!\n\n");
                    goto CHOICE;
                }
                else
                {
                    pop(board, value, selectedSquare, 0);
                    push(board, value, selectedSquare-1, 0);
                }   
            }
            else if(updown == 'd')
            {
                if(selectedSquare==5)
                {
                    printf("This token is at the bottom of the column and can only be moved up!\n\n");
                    goto CHOICE;
                }
                else if(minNumOfTokens>=1 && board[selectedSquare][0].stack->col == players[i].col)
                {
                    printf("You cannot stack on top of your own token colour!\n\n");
                    goto CHOICE;
                }
                else
                {
                    pop(board, value, selectedSquare, 0);
                    push(board, value, selectedSquare+1, 0);
                }
            }
            print_board(board); //prints board to show change in token position
        }


        //moving horizontally
        
        /*int location = 0;

        pop(board, value, dice, location);
        location++;
        push(board, value, dice, location);
        print_board(board);
        goto GAME;*/
    }
}
