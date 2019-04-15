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
    //enum col chosen;
    //char color;
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
      printf("Choose a player colour: red, blue, green, yellow, pink, orange\n");
      scanf("%s", &players[i].col);
    }
    /*switch (chosen)
    {
        case (RED):
            scanf(" ");
            break;
        case (BLU):
            scanf(" ");
            break;
        case (GREEN):
            scanf(" ");
            break;
        case (YELLOW):
            scanf(" ");
            break;
        case (PINK):
            scanf(" ");
            break;
        case (ORANGE):
            scanf(" ");
            break;
        default:
            break;
    }*/
        return num;
}