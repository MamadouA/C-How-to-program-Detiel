// 6-23 Turtle graphics sumilation 
#include <stdio.h>
#define PEN_UP 1
#define PEN_DOWN 2
#define RIGHT 3
#define LEFT 4
#define FORWARD 5
#define PRINT_ARRAY 6
#define END_OF_DATA 9
#define FLOOR_LENGTH 22

#define MOVE_LENGTH 5
#define MAX_COMMANDS 40

enum axes { X_POSITIF, X_NEGATIF, Y_UP, Y_DOWN };
enum axes axis = X_POSITIF; // can contain X, Y...

// Function prototypes
void changeAxis( int newDirection );
void print2DArray( int array[][ FLOOR_LENGTH ] );
void makeMoves( int floor[][ FLOOR_LENGTH ], int penStatus );

// Function main begins program execution
int main( void )
{
    // array to hold the commands
    int commands[ MAX_COMMANDS ] = 
        { PEN_DOWN, FORWARD, RIGHT, FORWARD, LEFT , FORWARD, LEFT,
             FORWARD, RIGHT, FORWARD, LEFT, FORWARD, RIGHT,
                 FORWARD, RIGHT, FORWARD,
                 RIGHT, PEN_UP, FORWARD, RIGHT, PEN_DOWN, FORWARD, RIGHT, FORWARD,
                    RIGHT, FORWARD, LEFT, FORWARD, PRINT_ARRAY, END_OF_DATA }; 
    
    int floor[ FLOOR_LENGTH ][ FLOOR_LENGTH ]; // hold the turtle moves
    int penPosition = PEN_DOWN; // hold the pen position
    size_t commandsCounter = 0; // count the number of commands

    // initialize array floor
    for( int i = 0; i < FLOOR_LENGTH; ++i )
    {
        for( int j = 0; j < FLOOR_LENGTH; ++j )
        {
            floor[ i ][ j ] = 0;
        } // end inner for
    } // end outer for

    // initialize the starting point to 1
    floor[ 0 ][ 0 ] = 1;

    for( commandsCounter = 0; commandsCounter < MAX_COMMANDS; ++commandsCounter )
    {   
        // determine the rule of each command
        switch( commands[ commandsCounter ] ) 
        {
            case PEN_UP: 
                penPosition = PEN_UP; // set pen position to up
                break;
            case PEN_DOWN:
                penPosition = PEN_DOWN; // set pen position to down
                break;
            case RIGHT:
                // choose a new axis based on the current direction
                changeAxis( RIGHT );
                break;
            case LEFT:
               // choose a new axis based on the current direction
               changeAxis( LEFT );
                break;
            case FORWARD:
                makeMoves( floor, penPosition ); // move FORWARD
             break;
            case PRINT_ARRAY:
                print2DArray( floor );  // print the array
                break;
            case END_OF_DATA:  // end of data
                break;
        } // end switch
    } // end for
    return 0;
} // end function main

// Definition function changeAxis
void changeAxis( int newDirection) // This function change the global variable axis
{     
	switch( axis )
	{
		case X_POSITIF:
			if( newDirection == RIGHT ) // is newDirection = RIGHT?
				axis = Y_DOWN; // set newDirection to Y_DOWN
			else // if newDirection != RIGHT    
				axis = Y_UP; // set axis to Y_UP
			break;
		case X_NEGATIF:
			if( newDirection == RIGHT ) // is newDirection = RIGHT?
				axis = Y_UP; // set direction to Y_UP
			else // if newDirection != RIGHT
				axis = Y_DOWN; // set axis to Y_DOWN
			break;
		case Y_UP:
        case Y_DOWN:
			if( newDirection == RIGHT ) // is newDirection = RIGHT?
				axis = X_POSITIF; // set axis to X_POSITIF
			else // if newDirection != RIGHT
				axis = X_NEGATIF; // set the axis to X_NEGATIF
			break;
	} // end switch
} // end function changeAxis

// Defintion function makeMoves
void makeMoves( int floor[][ FLOOR_LENGTH ], int penStatus )
{
    int i; // count the number of move
    static size_t positionOnX = 0; // hold the position of the turtle on X
    static size_t positionOnY = 0; // hold the positon of the turtle on Y

    for( i = 0; i < MOVE_LENGTH; ++i )
    {    
       // make a move based on the current axis
        switch( axis )
        {
            case X_POSITIF: 
                ++positionOnX;
                break;
            case X_NEGATIF:
                --positionOnX;
                break;
            case Y_UP:
                --positionOnY;
                break;
            case Y_DOWN:
                ++positionOnY;
                break;
        } // end switch

        // determine the position of the pen
        if( penStatus == PEN_DOWN ) // is penStatus DOWN?
        {   
            floor[ positionOnY ][ positionOnX ] = 1; // set one element of the array floor to 1
        } // end if
        else // if penStatus != DOWN
        {   
            floor[ positionOnY ][ positionOnX ] = 0; // set one element of the array floor to 0
        } // end else
    } // end for
} // end function makeMoves

// Definition function print2DArray
void print2DArray( int array[][ FLOOR_LENGTH ] )
{   
    size_t row = 0; // count the rows
    size_t column = 0; // counter for the columns

    // print a 2D array
    for( row = 0; row < FLOOR_LENGTH; ++row )
    {
        for( column = 0; column < FLOOR_LENGTH; ++column )
        {
            if( array[ row ][ column ] == 1 )
            {
                printf( "%2s", "-" );
            } // end if
            else
            {
                printf( "%s", "  " );
            } // end else
        } // end inner for

        puts( "" );
    } // end outer for
} // end function print2DArray