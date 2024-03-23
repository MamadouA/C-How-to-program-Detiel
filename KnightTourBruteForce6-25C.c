// Moving a knight tour arround the chessborad
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BOARD_SIZE 8
#define NUMBER_OF_MOVES 8
#define NUMBER_OF_SQUARES 64
#define TOURS_LENGTH 65

// Function prototypes
int controlArrayLimits( size_t row, size_t column, size_t size );
int determinePotentialMoves( int chessboard[][ BOARD_SIZE ], int potentialMoves[],
                                 int vertical[], int horizontal[], size_t currentColumn, size_t currentRow );
void print1DArray( int array[], size_t size );

// Function main begins program execution
int main( void )
{
    size_t currentRow = 0;
    size_t currentColumn = 0;
    int moveNumber = 0;
    int numberOfPotentialMoves = 0;
    int squaresCounter = 0;
    int lengthFrequencies[ TOURS_LENGTH ] = { 0 };
    int potentialMoves[ NUMBER_OF_MOVES ] = { 0 };
    int horizontal[ BOARD_SIZE ] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int vertical[ BOARD_SIZE ] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    int board[ BOARD_SIZE ][ BOARD_SIZE ];

    srand( time( NULL ) );
    
    do
    {
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

        board[ currentRow ][ currentColumn ] = 1; // initizlize the starting square board[ 0 ][ 0 ]

        // determine the number of possible moves using board[ 0 ][ 0 ] as starting square
        numberOfPotentialMoves = determinePotentialMoves( board, potentialMoves, vertical, horizontal, currentColumn, currentRow );
        
        for( squaresCounter = 2; squaresCounter <= NUMBER_OF_SQUARES; ++squaresCounter )
        {
            // choose randomly a moveNumber
            moveNumber = potentialMoves[ rand() % numberOfPotentialMoves ];

            // determine the corresponding row and column for the choosen moveNumber
            currentRow += vertical[ moveNumber ];
            currentColumn += horizontal[ moveNumber ];

            // count each square already visited by the knight
            board[ currentRow ][ currentColumn ] = squaresCounter; 

            // determine the number of all the possible moves
            // using board[ currentRow ][ currentColumn ] as starting square
            numberOfPotentialMoves = determinePotentialMoves( board, potentialMoves, vertical, horizontal, currentColumn, currentRow );

            if( numberOfPotentialMoves == 0 ) // if there is no more possible move
                break;
        } // end for

        ++lengthFrequencies[ squaresCounter ];

    } while( squaresCounter < NUMBER_OF_SQUARES );
    
    // print array lengthFrequencies
    print1DArray( lengthFrequencies, TOURS_LENGTH ); 
    return 0;
} // End function main

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
        if( chessboard[ tempRow ][ tempColumn ] != 0 ) // is this square already visited?
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

// Defintion function print1DArray
void print1DArray( int array[], size_t size )
{
    size_t i = 0;
    size_t index = 0;

    // print headers
    printf( "\n%s", "Length of the tours:  " );

    for( index = 60; index < size; ++index )
    {
        printf( "%10d", index );
    } // end for
    
    // print header
    printf( "\n\n%s", "    Number of tours:  " );

    // print the array elements
    for( i = 60; i < size; ++i )
    {
        printf( "%10d", array[ i ] );
    } // end for
} // End function print1DArray

