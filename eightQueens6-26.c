// Solving the eight queens problem
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define BOARD_SIZE 8
#define NUMBER_OF_QUEENS 8
#define NUMBER_OF_SQUARES 64

// Function prototypes
bool isAttacked( int chessboard[][ BOARD_SIZE ], size_t positionalRow, size_t positionalColumn );
int solveNQueen( int chess[][ BOARD_SIZE ], int eliminations[][ BOARD_SIZE ] );
void showBoard( int arrayBoard[][ BOARD_SIZE ] );

// Function main begins program execution
int main( void )
{
    size_t currentRow, currentColumn;
    int board[ BOARD_SIZE ][ BOARD_SIZE ];
    int eliminationNumbers[ BOARD_SIZE ][ BOARD_SIZE ] = { { 22, 22, 22, 22, 22, 22, 22, 22 },
                                                           { 22, 24, 24, 24, 24, 24, 24, 22 },
                                                           { 22, 24, 26, 26, 26, 26, 26, 24 },
                                                           { 22, 24, 26, 28, 28, 26, 24, 22 },
                                                           { 22, 24, 26, 28, 28, 26, 24, 22 },
                                                           { 22, 24, 26, 26, 26, 26, 24, 22 },
                                                           { 22, 24, 24, 24, 24, 24, 24, 22 },
                                                           { 22, 22, 22, 22, 22, 22, 22, 22 }};
    
    // seed for the random number generator
    srand( time( NULL ) );

    do
    {
         // initialize board
        for( currentRow = 0; currentRow < BOARD_SIZE; ++currentRow )
        {
            for( currentColumn = 0; currentColumn < BOARD_SIZE; ++currentColumn )
            {
                board[ currentRow ][ currentColumn ] = 0;
            } // end inner for
        } // end outer for
        // solve the N queen problem and return the number of placed queens
    }while( solveNQueen( board, eliminationNumbers ) < NUMBER_OF_QUEENS );

    showBoard( board ); // show the chessboard

    return 0;
} // End function main
 
// Definition function solveNQeen
int solveNQueen( int chess[][ BOARD_SIZE ], int eliminations[][ BOARD_SIZE ] )
{
    
} // End function solveNQueen

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