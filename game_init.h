//init.h

//number of rows of the board
#define NUM_ROWS 6
//number of columns of the board
#define NUM_COLUMNS 9
//max number of players in the game
#define NUM_PLAYERS 6


//types of squares
enum stype
{
    NORMAL, OBSTACLE 
};

//colours of tokens
enum color
{
    RED, BLUE, GREEN, YELLOW, PINK, ORANGE
};

//defines a token. 
//Note each token can be associated with a color
typedef struct token
{
   enum color col;
   //token * next;

}token;

//Defines a square of the board.
typedef struct square
{
    //A square can be a NORMAL or an OBSTACLE square
     enum stype type;
     //the stack of tokens that can be placed on the board square
     token * stack;
     //***the number of tokens in a square --ADDED by Sean from lab2
     int numTokens;
}square;


/* stack tings

struct stack{
    int token;
    struct stack *next;
} stack;

<<<<<<< HEAD
struct stack_elem * push(int value, struct stack_elem *top){
    struct stack_elem *curr = top;
    top = malloc(sizeof(stack));
    top->data = value;
    top->next = curr;
    return top;
}

struct stack_elem * pop(struct stack_elem *top){
    struct stack_elem *curr = top;
    if(curr!=NULL){
        top = curr->next;
        printf("Stack Data: %d\n", curr->data);
        free(curr);
    }
    return top;
}*/



=======
>>>>>>> 88f2317618739d037f4e1aa487ec544f0aa664b9


/*
 * You need to fill this data structure
 * with the information about the player
 * such as a name and a color.
 */
typedef struct players
{

    //a player is characterized by a name, color AND-> the no. of their tokens in the last column!!
    char name[50];
    enum color col;
    int numTokensLastCol;
    struct token token;

}player; 


/*
 * This function creates the board for the first time
 * 
 * Input: board - a 6x9 array of squares
 *
 */
void initialize_board(square board[NUM_ROWS][NUM_COLUMNS]);

/*
 * This function creates players for the first time
 * 
 * Input: the array of players to be initialized
 * Output: The number of players of the game
 *
 */
int initialize_players(player players[NUM_PLAYERS]);