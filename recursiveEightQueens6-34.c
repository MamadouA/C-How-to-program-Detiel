#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <stdbool.h>
#define BOARD_SIZE 8
#define QUEENS 8

// function prototypes
bool solveNQ( int chessboard[][ BOARD_SIZE ], size_t row, size_t column, int numberOfQueens );
bool isAttacked( int chessboard[][ BOARD_SIZE ], size_t positionalRow, size_t positionalColumn );
void showBoard( int array[][ BOARD_SIZE ] );

// function main
int main( void )
{
    int board[ BOARD_SIZE ][ BOARD_SIZE ];
    size_t currentRow = 0; 
    size_t currentColumn = 0;

    // seed for the random number generator
    srand( time( NULL ) );

    do
    {
        // initialize array board
        // loop through the rows
        for( currentRow = 0; currentRow < BOARD_SIZE; ++currentRow ) { 
            // loop through the columns 
            for( currentColumn = 0; currentColumn < BOARD_SIZE; ++currentColumn ) {
                // initialize board[ currentRow ][ currentColumn ] to 0
                board[ currentRow ][ currentColumn ] = 0; 
            } // end inner for
        } // end outer for

        // initialize the starting square
        board[ rand() % BOARD_SIZE ][ rand() % BOARD_SIZE ] = 1;

    } while ( !solveNQ( board, 0, 0, 1 ) );

    showBoard( board );
    return 0;
} // end main

// function solveNQProblem
bool solveNQ( int chessboard[][ BOARD_SIZE ], size_t row, size_t column, int numberOfQueens )
{   
    if( numberOfQueens == QUEENS ) {
        return true; // all the queens were placed
    } // end if
    if( ( row == BOARD_SIZE - 1 ) && ( column == BOARD_SIZE - 1 ) ) {
        return false; // all the queens were not placed
    } // end if
    if( isAttacked( chessboard, row, column ) || ( chessboard[ row ][ column ] ) ) {
        // pass to the next column if column < BOARD_SIZE
        if( column < BOARD_SIZE ) {
            return( solveNQ( chessboard, row, ++column, numberOfQueens ) );
        } // end if
        else {
            // pass to the next row if column = BOARD_SIZE 
            return ( solveNQ( chessboard, ++row, 0, numberOfQueens ) );
        } // end else
     } // end if

     // if this square is safe place a queen
     chessboard[ row ][ column ] = 1;

     return( solveNQ( chessboard, row, column, ++numberOfQueens ) );
} // end function solveNQProblem

// Defintion function checkForAttacks
bool isAttacked( int chessboard[][ BOARD_SIZE ], size_t positionalRow, size_t positionalColumn )
{
    size_t tempRow = 0;
    size_t  tempColumn = 0;
    size_t i = 0;

    // is the queen attacked from the horizontal or vertical squares?
    for( i = 0; i < BOARD_SIZE; ++i )
    {   
        if( ( chessboard[ positionalRow ][ i ] != 0 ) && ( i != positionalColumn ) )
            return true;

        if( ( chessboard[ i ][ positionalColumn ] != 0 ) && ( i != positionalRow ) )
            return true;
    } // end for
   
   // is the queen attacked from the diagonals?
   for( tempRow = 0; tempRow < BOARD_SIZE; ++tempRow )
   {
       for( tempColumn = 0; tempColumn < BOARD_SIZE; ++tempColumn )
       {
           if( ( tempRow + tempColumn == positionalRow + positionalColumn ) || 
                            ( tempRow - tempColumn == positionalRow - positionalColumn ) )
           {   
                if( ( positionalRow == tempRow ) && ( positionalColumn == tempColumn ) )
                    continue;

               if( chessboard[ tempRow ][ tempColumn ] )
                    return true;
           } // end if
       } // end inner for
   } // end outer for

    return false;
} // End function isAttacked

// Definition function print2DArray
void showBoard( int array[][ BOARD_SIZE ] )
{
    size_t row = 0; // counter for the rows
    size_t column = 0; // counter for the columns

    printf( "\n%33s", "C H E S S B O A R D\n\n" );

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
