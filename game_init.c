//game_init.c contains the implementation of the function needed to initialize the board

#include "game_init.h"
#include <stdio.h>


/*
 * This function creates the board for the first time
 *
 * Input: board - a 6x9 array of squares
 *
 */
void initialize_board(square board[NUM_ROWS][NUM_COLUMNS])
{

    for (int i =0; i< NUM_ROWS; i++)
    {
        for(int j =0; j < NUM_COLUMNS; j++)
        {
            //creates an obstacle square at positions (0,3), (1,6), (2,4), (3,5), (4,2) and (5,7)       
            if((i == 0 && j==3) || (i == 1 && j == 6) || (i ==2 && j ==4)
                    || (i == 3 && j ==5) || (i==4 && j==2) || (i==5 && j==7))
                    {
                board[i][j].type = OBSTACLE;
            } else
            {
                //creates a normal square otherwise
                board[i][j].type = NORMAL;
            }
            board[i][j].stack = NULL;
        }
    }
}


 /*
 * This function creates players for the first time
 *
 * Input: the array of players to be initialized
 * Output: The number of players of the game
 */
int initialize_players(player players[6])
{
    int num, j;
    char name;
    char col[7][7] = {"Red", "Blue", "Green", "Yellow", "Pink", "Orange", "\0"};

    printf("How many players do you want to input? (2-6)\n");
    scanf("%d", &num);
    if(num<2 || num>6){
        printf("Error. Enter a number between 2 and 6 inclusive.\n");
        return 0;
    }

    for(int i=0; i<num; i++)
    {
      printf("Enter a players name: ");
      scanf("%s", &players[i].name);

      switch(i)
    {
        case(0):
                players[i].col = RED;
        case(1):
                players[i].col = BLUE;
        case(2):
                players[i].col = GREEN;
        case(3):
                players[i].col = YELLOW;
        case(4):
                players[i].col = PINK;
        case(5):
                players[i].col = ORANGE;
        default: break;
    }
      printf("Player %d has been assigned the colour %s.\n", i+1, col[i]);
    }
        return num;
}