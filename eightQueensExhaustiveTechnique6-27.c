#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define BOARD_SIZE 8
#define NUMBER_OF_QUEENS 8

// Function prototypes
void placeQueens( int chess[][ BOARD_SIZE ] );
void showBoard( int boardArray[][ BOARD_SIZE ] );
bool isAttacked( int chessboard[][ BOARD_SIZE ], size_t positionalRow, size_t positionalColumn );
bool isSolved( int board[][ BOARD_SIZE ] );

// Function main begins program execution
int main( void )
{
    int board[ BOARD_SIZE ][ BOARD_SIZE ] = { 0 };
    int tries = 0;

    // seed for the random number generator
    srand( time( NULL ) );

    do
    {
        placeQueens( board );

        showBoard( board );
        
        isSolved( board ) ? puts( "True" ) : puts( "False" );

        ++tries;
    } while( !isSolved( board ) && tries < 8 );
    
    return 0;
} // End function main

//  Definition function placeQueens
void placeQueens( int chess[][ BOARD_SIZE ] )
{
    size_t rowIndex = 0;
    size_t columnIndex = 0;
    unsigned int queensCounter = 0;

    // initialize array board
    for( rowIndex = 0; rowIndex < BOARD_SIZE; ++rowIndex )
    {
        for( columnIndex = 0; columnIndex < BOARD_SIZE; ++columnIndex )
        {
            chess[ rowIndex ][ columnIndex ] = 0;
        } // end inner for
    } // end outer for

    for( queensCounter = 0; queensCounter < NUMBER_OF_QUEENS; ++queensCounter )
    {
        rowIndex = rand() % 8; // choose a random row
        columnIndex = rand() % 8; // choose a random column

        while( chess[ rowIndex ][ columnIndex ] )
        {
            rowIndex = rand() % 8;
            columnIndex = rand() % 8;
        } // end while

        chess[ rowIndex ][ columnIndex ] = 1; // place a queen in the choosen square
    } // end for
} // end function placeQueens

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

// Definition function isSolved
bool isSolved( int board[][ BOARD_SIZE ] )
{
    for( size_t row = 0; row < BOARD_SIZE; ++row )
    {
        for( size_t column = 0; column < BOARD_SIZE; ++column )
        {   
            if( board[ row ][ column ] )
            {
                if( isAttacked( board, row, column ) )
                    return false;
            } // end if

        } // end inner for
    } // end outer for

    return true;
} // end function isSolved

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