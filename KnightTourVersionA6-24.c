// The knight's tour
#include <stdio.h>
#define MAX_SQUARES 64
#define BOARD_SIZE 8
#define MAX_TRIES 8

// Function prototypes
void print2DArray( int array[][ BOARD_SIZE ] );
int checkTheMoveNumber( int chessBoard[][ BOARD_SIZE ], int x[], int y[], int moveIndex, int presentRow, int presentColumn );

// Function main begins program execution
int main( void )
{
    int board[ BOARD_SIZE ][ BOARD_SIZE ];
    int horizontal[ BOARD_SIZE ];
    int vertical[ BOARD_SIZE ];
    int moveNumber = 0;
    int squareCounter = 0;
    size_t currentRow = 0;
    size_t currentColumn = 0;


    // initialize the array board
    for( currentRow = 0; currentRow < BOARD_SIZE; ++currentRow )
    {
        for( currentColumn = 0; currentColumn < BOARD_SIZE; ++currentColumn )
        {
            board[ currentRow ][ currentColumn ] = 0;
        } // end inner for
    } // end outer for

    // reinitialize currentRow and currentColumn
    currentRow = 3;
    currentColumn = 3;

    // initialize the array horizontal
    horizontal[ 0 ] = 2;
    horizontal[ 1 ] = 1;
    horizontal[ 2 ] = -1;
    horizontal[ 3 ] = -2;
    horizontal[ 4 ] = -2;
    horizontal[ 5 ] = -1;
    horizontal[ 6 ] = 1;
    horizontal[ 7 ] = 2;

    // initialize the array vertical
    vertical[ 0 ] = -1;
    vertical[ 1 ] = -2;
    vertical[ 2 ] = -2;
    vertical[ 3 ] = -1;
    vertical[ 4 ] = 1;
    vertical[ 5 ] = 2;
    vertical[ 5 ] = 2;
    vertical[ 6 ] = 2;
    vertical[ 7 ] = 1;

    for( squareCounter = 1; squareCounter <= MAX_SQUARES; ++squareCounter )
    {
        // count each square the knight have already visited
        board[ currentRow ][ currentColumn ] = squareCounter;

        // choose 0 as a moveNumber
        moveNumber = 0;

        // check the limit of the board and
        // determine if the choosen square have been already visited 
        while( ( checkTheMoveNumber( board, horizontal, vertical, moveNumber, currentRow, currentColumn ) == 0 )
                     && ( moveNumber < MAX_TRIES ) )
        {
            // try another moveNumber
            ++moveNumber;
        } // end while

        if( moveNumber == MAX_TRIES ) // did the user try all the possible moves?
        {   
            printf( "%s", "\nThere is no more possible move." );
            break;
        } // end if
        else
        {   
            // pass to another row and another column
            currentRow += vertical[ moveNumber ];
            currentColumn += horizontal[ moveNumber ];
        } // end else 
    } // end for

    puts( "" ); // start a new line

    // print the array board
    print2DArray( board );
    printf( "You made %d moves.", squareCounter );

    return 0;
} // end function main

// Definition function print2DArray
void print2DArray( int array[][ BOARD_SIZE ] )
{
    size_t row = 0; // counter for the rows
    size_t column = 0; // counter for the columns

    // print a 2D array
    for( row = 0; row < BOARD_SIZE; ++row )
    {
        for( column = 0; column < BOARD_SIZE; ++column )
        {
            printf( "%5d", array[ row ][ column ] );
        } // end inner for

        puts( "" );
        puts( "" );
    } // end outer for
} // end function print2DArray

// Definition function checkTheMoveNumber
int checkTheMoveNumber( int chessBoard[][ BOARD_SIZE ], int x[], int y[],
                     int moveNumber, int presentRow, int presentColumn )
{
    presentRow += y[ moveNumber ]; // determine the following row
    presentColumn += x[ moveNumber ]; // determine the following column

    // Did the knight land off the chessboard
    if( ( presentRow < 0 || presentRow >= BOARD_SIZE ) ||
             ( presentColumn < 0 || presentColumn >= BOARD_SIZE ) ) 
        return 0;
    
    // Did the knight already visited this square?
    if( chessBoard[ presentRow ][ presentColumn ] != 0 ) 
        return 0; // end the function by returning 0
    
    return 1; // end the function by returning 1
} // end function checkTheMoveNumber