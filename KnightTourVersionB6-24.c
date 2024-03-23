// The knight's tour
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SQUARES 64
#define BOARD_SIZE 8
#define MAX_TRIES 8

// Function prototypes
void print2DArray( int array[][ BOARD_SIZE ] );
int determineTheMoveNumber( int squareAccessibility[][ BOARD_SIZE ], int chessboard[][ BOARD_SIZE ], 
                                    int horizontal[], int vertical[], int row, int column );
void checkTheChessboard( int chessboard[][ BOARD_SIZE ] );        
void reduceAccessibility( int accessibilityTable[][ BOARD_SIZE ], int row, int column, int horizontal[], int vertical[] );

// Function main begins program execution
int main( void )
{
    size_t currentRow = 0;
    size_t currentColumn = 0;
    int moveNumber = 0;
    int squaresCounter = 0;
    int horizontal[ BOARD_SIZE ];
    int vertical[ BOARD_SIZE ];
    int board[ BOARD_SIZE ][ BOARD_SIZE ];
    int accessibility[ BOARD_SIZE ][ BOARD_SIZE ] = { { 2, 3, 4, 4, 4, 4, 3, 2 },
                                                      { 3, 4, 6, 6, 6, 6, 4, 3 },
                                                      { 4, 6, 8, 8, 8, 8, 6, 4 },
                                                      { 4, 6, 8, 8, 8, 8, 6, 4 },
                                                      { 4, 6, 8, 8, 8, 8, 6, 4 },
                                                      { 4, 6, 8, 8, 8, 8, 6, 4 },
                                                      { 3, 4, 6, 6, 6, 6, 4, 3 },
                                                      { 2, 3, 4, 4, 4, 4, 3, 2 }};

    // seed for the random number generator
    srand( time( NULL ) );
    
    // initialize the array board
    for( currentRow = 0; currentRow < BOARD_SIZE; ++currentRow )
    {
        for( currentColumn = 0; currentColumn < BOARD_SIZE; ++currentColumn )
        {
            board[ currentRow ][ currentColumn ] = 0;
        } // end inner for
    } // end outer for

    // reinitialize currentRow and currentColumn
    currentRow = 0;
    currentColumn = 0;

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

    // initialize the starting point
    board[ currentRow ][ currentColumn ] = 1;
    // reduce the accessibility for each accessible square
    reduceAccessibility( accessibility, currentRow, currentColumn, horizontal, vertical );

    for( squaresCounter = 2; squaresCounter <= MAX_SQUARES; ++squaresCounter )
    {
        // determine the move number with the lowest accessibility number
        moveNumber = determineTheMoveNumber( accessibility, board, horizontal, vertical, currentRow, currentColumn );

        if( moveNumber == -1 )
        {
            break;
        } // end if

        // determine the corresponding row and column for the choosen move number
        currentRow += vertical[ moveNumber ];
        currentColumn += horizontal[ moveNumber ];

        // reduce the accessibility for each accessible square
        reduceAccessibility( accessibility, currentRow, currentColumn, horizontal, vertical );

        // cout the number of squares the knight have already visited
        board[ currentRow ][ currentColumn ] = squaresCounter;
    } // End for

    puts( "" );
    printf( "\n%35s", "C H E S S B O A R D\n\n" );
    print2DArray( board );
    printf( "\n%35s", "A C C E S S I B I L I T Y\n" );
    puts( "" );
    print2DArray( accessibility );

    return 0;
} // End function main

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

// Definition function reduceAccessibility
void reduceAccessibility( int accessibilityTable[][ BOARD_SIZE ], int row, int column, int horizontal[], int vertical[] )
{
    int moveNumberCounter = 0; // counter for the move number
    int tmpRow = 0;
    int tmpColumn = 0;

    for( moveNumberCounter = 0; moveNumberCounter < MAX_TRIES; ++moveNumberCounter )
    {
        // reinitialize tmpRow and tmpColumn
        tmpRow = row;
        tmpColumn = column;

        // determine the corresponding row and column for each potential move
        tmpRow += vertical[ moveNumberCounter ]; 
        tmpColumn += horizontal[ moveNumberCounter ]; 

        // will the knight land off the chessboard ?
        if( ( tmpRow >= 0 && tmpRow < BOARD_SIZE ) && ( tmpColumn >= 0 && tmpColumn < BOARD_SIZE ) )
        {
            --accessibilityTable[ tmpRow ][ tmpColumn ]; // reduce the accessibility for this square
        } // End if
    } // End for
} // End function reduce the accessibility

// Definition function determineTheMoveNumber
int determineTheMoveNumber( int squareAccessibility[][ BOARD_SIZE ], int chessboard[][ BOARD_SIZE ],
                                int horizontal[], int vertical[], int row, int column )
{
    int lowestAccessibilityNumber = 8;
    int moveNumber = -1;
    int tempRow = 0;
    int tempColumn = 0;
    int moveNumberCounter = 0;
    int randomChoice = 0;

    for( moveNumberCounter = 0; moveNumberCounter < MAX_TRIES; ++moveNumberCounter )
    {   
        // reinitialize tempRow and tempColumn
        tempRow = row;
        tempColumn = column;

        // determine the corresponding row and column
        // for each potential move
        tempRow += vertical[ moveNumberCounter ]; 
        tempColumn += horizontal[ moveNumberCounter ]; 

        // Did the knight land off the chessboard
        if( ( tempRow < 0 || tempRow >= BOARD_SIZE ) || ( tempColumn < 0 || tempColumn >= BOARD_SIZE ) ||
                     ( chessboard[ tempRow ][ tempColumn ] != 0 ) )
            continue;


        // Does this square contain a lowest accessibility number?
        if( squareAccessibility[ tempRow ][ tempColumn ] < lowestAccessibilityNumber )
        {
            // determine the move number with the lowest accessibility number
            lowestAccessibilityNumber = squareAccessibility[ tempRow ][ tempColumn ];
            
            moveNumber = moveNumberCounter;
        } // end if
        else if( squareAccessibility[ tempRow ][ tempColumn ] == lowestAccessibilityNumber ) // in case of a tie
        {
            randomChoice = 1 + rand() % 2; // make a random choice

            if( randomChoice == 2 ) 
                moveNumber = moveNumberCounter; // choose the last move number
        } // end inner if
    } // end for

    return moveNumber; // return the move number with the lowest accessibility number
} // End function determineTheMoveNumber

// Defintion function checkTheChessboard
void checkTheChessboard( int chessboard[][ BOARD_SIZE ] )
{
    int squaresCounter = 0;
    size_t row = 0;
    size_t column = 0;

    for( row = 0; row < BOARD_SIZE; ++row )
    {
        for( column = 0; column < BOARD_SIZE; ++column )
        {
            if( chessboard[ row ][ column ] != 0 )
                ++squaresCounter;
        } // end inner for
    } // end outer for

    if( squaresCounter == MAX_SQUARES )
        printf( "%s", "This is a full tour. " );
    else    
        printf( "%s", "This is not a full tour." ); 
} // End function checkTheChessboard
