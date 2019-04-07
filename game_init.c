//game_init.c contains the implementation of the function needed to initialize the board

#include "game_init.h"
#include <stdio.h>


/*
 * This function creates the board for the first time
 *
 * Input: board - a 6x9 array of squares
 *
 */
void initialize_board(square board[NUM_ROWS][NUM_COLUMNS]){

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
int initialize_players(player players[NUM_PLAYERS])
{
    int num;
    printf("How many players do you want to input? (2-6): ");
    scanf("%d", &num);
    if(num<2 || num>6){
        printf("Error. Enter a number between 2 and 6 inclusive.\n");
        return 0;
    }

    for(int i=0; i<num; i++)
    {
      printf("Enter a players name: ");
      scanf("%s", &players[i].name);
    }
    return num;
}

/*
* This function is for player colour
*
* Input: The array of players
* Output: The colours relative to each player of the game
*/
int initialize_colors(enum color)
{
    int choice = 0;
    printf("Choose a player colour from the list:\n(0) red\n(1) blue\n(2) green\n(3) yellow\n(4) pink\n(5) orange\n");
      scanf("%d", choice);
      
      switch(type)
      {
          case(RED):printf("Colour chosen: %s\n", "red");
          break;
          case(BLUE):printf("Colour chosen: %s\n", "blue");
          break;
          case(GREEN):printf("Colour chosen: %s\n", "green");
          break;
          case(YELLOW):printf("Colour chosen: %s\n", "yellow");
          break;
          case(PINK):printf("Colour chosen: %s\n", "pink");
          break;
          case(ORANGE):printf("Colour chosen: %s\n", "orange");
          break;
          default:break;
        }
}
void place_tokens(square board[NUM_ROWS][NUM_COLUMNS], player players[], int numPLayers){
    int minNumOfTokens = 0;
    int selectedSquare = 0;

    for(int i=0; i<4; i++){
        for(int j=0; j<numPLayers; j++){

            printf("Player %d please select a square\n", j);
            scanf("%d", &selectedSquare);

            board[selectedSquare][0].stack = (token *) malloc(sizeof(token));
            board[selectedSquare][0].stack->col = players[j].col;
            board[selectedSquare][0].numTokens++;

            if((numPLayers * i) + j +1)%NUM_ROWS == 0)
            minNumOfTokens++;
        }
    }
}
