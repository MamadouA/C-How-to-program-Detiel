#include <stdio.h>
#define BOARD_SIZE 8
#define NUMBER_OF_SQUARES 64
#define NUMBER_OF_MOVES 8

// Function prototypes
int controlArrayLimits( size_t row, size_t column, size_t size );
void reduceAccessibilities( int accessibilities[][ BOARD_SIZE ], int vertical[], int horizontal[],
                                 size_t rowNumber, size_t columnNumber );
int chooseBetweenTwoMoves( int chessboard[][ BOARD_SIZE ], int accessibilities[][ BOARD_SIZE ], int vertical[],
                             int horizontal[], size_t rowMove1, size_t columnMove1, size_t rowMove2,
                              size_t columnMove2, int moveNumber1, int moveNumber2 );

void print2DArray( int array[][ BOARD_SIZE ] );

// Function main begins program execution
int main( void )
{
    size_t currentRow = 0;
    size_t currentColumn = 0;
    size_t nextRow = 0;
    size_t nextColumn = 0;
    size_t tempRow = 0;
    size_t tempColumn = 0;
    int moveNumber = 0;
    int tempMoveNumber = 0;
    int squaresCounter = 0;
    int lowestAccessibilityNumber = 0;

    int horizontal[ BOARD_SIZE ] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int vertical[ BOARD_SIZE ] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    int board[ BOARD_SIZE ][ BOARD_SIZE ];
    int accessibility[ BOARD_SIZE ][ BOARD_SIZE ] = { { 2, 3, 4, 4, 4, 4, 3, 2 },
                                                      { 3, 4, 6, 6, 6, 6, 4, 3 },
                                                      { 4, 6, 8, 8, 8, 8, 6, 4 },
                                                      { 4, 6, 8, 8, 8, 8, 6, 4 },
                                                      { 4, 6, 8, 8, 8, 8, 6, 4 },
                                                      { 4, 6, 8, 8, 8, 8, 6, 4 },
                                                      { 3, 4, 6, 6, 6, 6, 4, 3 },
                                                      { 2, 3, 4, 4, 4, 4, 3, 2 }};
    
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

    // initialize the starting square
    board[ currentRow ][ currentColumn ] = 1;

    // reduce the accessibility of each accessible squares
    reduceAccessibilities( accessibility, vertical, horizontal, currentRow, currentColumn );

    // mechanisme of moving the knight
    for( squaresCounter = 2; squaresCounter <= NUMBER_OF_SQUARES; ++squaresCounter )
    {   
        lowestAccessibilityNumber = 8; // reinitialize lowestAccessibilityNumber

        moveNumber = -1; // initialize moveNumber to -1

        // search between the 8 move number the one with the lowest accessibility number
        for( tempMoveNumber = 0; tempMoveNumber < NUMBER_OF_MOVES; ++tempMoveNumber )
        {   
            // intialize tempRow and tempColumn
            tempRow = currentRow + vertical[ tempMoveNumber ]; 
            tempColumn = currentColumn + horizontal[ tempMoveNumber ];

            // Will the knight land of the chessboard?
            if( controlArrayLimits( tempRow, tempColumn, BOARD_SIZE ) == -1 )
                continue;

            if( board[ tempRow ][ tempColumn ] != 0 ) // is this square already visited?
                continue;

            // Does this square contain the lowest accessibility number?
            if( accessibility[ tempRow ][ tempColumn ] < lowestAccessibilityNumber )
            {
                moveNumber = tempMoveNumber;

                nextRow = tempRow;
                nextColumn = tempColumn;

                lowestAccessibilityNumber = accessibility[ tempRow ][ tempColumn ];
            } // end if
            else if( accessibility[ tempRow ][ tempColumn ] == lowestAccessibilityNumber )
            {   
               moveNumber = chooseBetweenTwoMoves( board, accessibility, vertical, horizontal,
                                 nextRow, nextColumn, tempRow, tempColumn, moveNumber, tempMoveNumber );

            } // end else if
        } // end inner for

        if( moveNumber == -1 ) // is move number == -1?
            break;
        
        // determine the current row and the current column
        currentRow += vertical[ moveNumber ];
        currentColumn += horizontal[ moveNumber ];

        // reduce the accessibility of each accessible squares
        reduceAccessibilities( accessibility, vertical, horizontal, currentRow, currentColumn );

        board[ currentRow ][ currentColumn ] = squaresCounter; // count the number of occupied squares
    } // End outer for

    printf( "\n%33s", "C H E S S B O A R D.\n\n" );
    print2DArray( board );
    printf( "%36s", "A C C E S S I B I L I T Y.\n" );
    puts( "" );
    print2DArray( accessibility );
    return 0;
} // End function main

// Defintion function reduceAccessibilities
void reduceAccessibilities( int accessibilities[][ BOARD_SIZE ], int vertical[], int horizontal[], 
                                size_t rowNumber, size_t columnNumber )
{
    size_t tempRow = 0;
    size_t tempColumn = 0;
    int tempMoveNumber = 0;

    for( tempMoveNumber = 0; tempMoveNumber < NUMBER_OF_MOVES; ++tempMoveNumber )
    {
        tempRow = rowNumber; // use the current row as starting row
        tempColumn = columnNumber; // use the current column as starting column 

        // determine the corresponding row and column for each temp move number
        tempRow += vertical[ tempMoveNumber ];
        tempColumn += horizontal[ tempMoveNumber ];

        //Will the knight land off the chessboard
        if( controlArrayLimits( tempRow, tempColumn, BOARD_SIZE ) == -1 ) 
            continue;

        --accessibilities[ tempRow ][ tempColumn ]; // reduce the accessibility of this square
    } // end for
} // End function reduceAccessibilities

// Definition function contorlLimitsOfTheArray
int controlArrayLimits( size_t row, size_t column, size_t size )
{
    if( row < 0 || row >= size ) // does this row belong to the array?
        return -1;
    if( column < 0 || column >= size ) // does this column belong to the array?
        return -1;

    return 0;
} // End function controlLimitsOfTheArray

// Definition function chooseBetweenTwoMoves
int chooseBetweenTwoMoves( int chessboard[][ BOARD_SIZE ], int accessibilities[][ BOARD_SIZE ], int vertical[], int horizontal[], 
                            size_t rowMove1, size_t columnMove1, size_t rowMove2, size_t columnMove2, int moveNumber1, int moveNumber2 )
{
    size_t tempRow = 0;
    size_t tempColumn = 0;
    int tempMoveNumber = 0;
    int choosenMoveNumber = -1;
    int lowestAccessibility = 8;

    for( tempMoveNumber = 0; tempMoveNumber < NUMBER_OF_MOVES; ++tempMoveNumber )
    {   
        // determine tempRow and tempColumn
        tempRow = rowMove1 + vertical[ tempMoveNumber ];
        tempColumn = columnMove1 + horizontal[ tempMoveNumber ];

        // Will the knight land off the chessboard?
        if( controlArrayLimits( tempRow, tempColumn, BOARD_SIZE ) == -1 )
            continue;
        if( chessboard[ tempRow ][ tempColumn ] != 0 ) // Is this square already visited?
            continue;

        // determine the move number with the lowest accessibilitly 
        // accessible from the location of moveNumber1
        if( accessibilities[ tempRow ][ tempColumn ] <= lowestAccessibility ) 
        {
            lowestAccessibility = accessibilities[ tempRow ][ tempColumn ];

            choosenMoveNumber = moveNumber1;
        } // end if
        
        // determine tempRow and tempColumn 
        // using rowMove2 and columnMove2 as the starting points
        tempRow = rowMove2 + vertical[ tempMoveNumber ];
        tempColumn = columnMove2 + horizontal[ tempMoveNumber ];

        if( controlArrayLimits( tempRow, tempColumn, BOARD_SIZE ) == -1 ) // Will the knight land off the chessboar?
            continue;
        if( chessboard[ tempRow ][ tempColumn ] != 0 ) // Is this square already visited?
            continue;

        // determine the move number with the lowest accessibilitly 
        // accessible from the location of moveNumber2
        if( accessibilities[ tempRow ][ tempColumn ] <= lowestAccessibility )
        {
            lowestAccessibility = accessibilities[ tempRow ][ tempColumn ];

            choosenMoveNumber = moveNumber2;
        } // end if
    } // end for

    return choosenMoveNumber;
} // End function chooseBetweenTwoMoves

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