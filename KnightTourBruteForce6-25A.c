// Moving a knight tour arround the chessborad
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BOARD_SIZE 8
#define NUMBER_OF_MOVES 8
#define NUMBER_OF_SQUARES 64

// Function prototypes
int controlArrayLimits( size_t row, size_t column, size_t size );
int determinePotentialMoves( int chessboard[][ BOARD_SIZE ], int potentialMoves[],
                                 int vertical[], int horizontal[], size_t currentColumn, size_t currentRow );
void print2DArray( int array[][ BOARD_SIZE ] );

// Function main begins program execution
int main( void )
{   
    size_t currentRow = 0;
    size_t currentColumn = 0;
    int moveNumber = 0;
    int numberOfPotentialMoves = 0;
    int squaresCounter = 0;
    int potentialMoves[ NUMBER_OF_MOVES ] = { 0 };
    int horizontal[ BOARD_SIZE ] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int vertical[ BOARD_SIZE ] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    int board[ BOARD_SIZE ][ BOARD_SIZE ];

    // seed for the random number generator
    srand( time( NULL ) );           
    
    // initialize array board
    for( currentRow = 0; currentRow < BOARD_SIZE; ++currentRow )
    {
        for( currentColumn = 0; currentColumn < BOARD_SIZE; ++currentColumn )
        {
            board[ currentRow ][ currentColumn ] = 0;
        } // end inner for
    } // end outer for

    // reinitialize currentRow and currentColumn to 0
    currentRow = 0;
    currentColumn = 0;

    board[ currentRow ][ currentColumn ] = 1; // initialize board[ 0 ][ 0 ] to 1

    // determine all the potential moves using board[ 0 ][ 0 ] as starting square
    numberOfPotentialMoves = determinePotentialMoves( board, potentialMoves, vertical, horizontal, currentColumn, currentRow );

    for( squaresCounter = 2; squaresCounter <= NUMBER_OF_SQUARES; ++squaresCounter )
    { 
        moveNumber = potentialMoves[ rand() % numberOfPotentialMoves ]; // choose randomly, a move number

        currentRow += vertical[ moveNumber ]; // determine the current row
        currentColumn += horizontal[ moveNumber ]; // determine the current column
        
        board[ currentRow ][ currentColumn ] = squaresCounter; // count the number of square already visited

        // determine all the potential moves using board[ currentRow ][ currentColumn ] as starting square
        numberOfPotentialMoves = determinePotentialMoves( board, potentialMoves, vertical, horizontal, currentColumn, currentRow );

        if( numberOfPotentialMoves == 0 )
            break;

    } // end for

    puts( "" );
    print2DArray( board );
    return 0;
} // End main

// Defintion function determinePotentialMoves
int determinePotentialMoves( int chessboard[][ BOARD_SIZE ], int potentialMoves[],
                                 int vertical[], int horizontal[], size_t currentColumn, size_t currentRow )
{
    size_t tempRow, tempColumn = 0;
    size_t subscriptOfThePotentialMove = -1;
    int tempMoveNumber = 0;

    for( tempMoveNumber = 0; tempMoveNumber < NUMBER_OF_MOVES; ++tempMoveNumber )
    {   
        // use tempRow and tempColumn as starting points
        tempRow = currentRow;
        tempColumn = currentColumn;

        // determine the corresponding row and column for tempMoveNumber
        tempRow += vertical[ tempMoveNumber ];
        tempColumn += horizontal[ tempMoveNumber ];

        // With tempMoveNumber, will the knight land off the chessboard
        if( controlArrayLimits( tempRow, tempColumn, BOARD_SIZE ) == -1 ) 
            continue;
        if( chessboard[ tempRow ][ tempColumn ] != 0 ) // is this square already visited
            continue;
        
        // save tempMoveNumber as a potential move
        potentialMoves[ ++subscriptOfThePotentialMove ] =  tempMoveNumber;
    } // end for
    
    return ( subscriptOfThePotentialMove + 1 );
} // End function determinePotentialMovesCounter

// Definition function contorlLimitsOfTheArray
int controlArrayLimits( size_t row, size_t column, size_t size )
{
    if( row < 0 || row >= size ) // does this row belong to the array?
        return -1;
    if( column < 0 || column >= size ) // does this column belong to the array?
        return -1;

    return 0;
} // End function controlLimitsOfTheArray       

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