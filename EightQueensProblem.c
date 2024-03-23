// This program solve the n queens problem
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 8
#define QUEENS 8

size_t currentRow = 0; // next row to place the next queen
size_t currentColumn = 0; // next column to place the next queen
int done = 0;
int highestEliminationNumber = 30;

// function prototypes
int solveNQ( int chessboard[][ SIZE ] );
void chooseNextSquare( int chess[][ SIZE ], int eliminations[][ SIZE ] );
int isSafe( size_t iRow, size_t iColumnm, size_t iRightDiagonal, size_t iLeftDiagonal, int board[][ SIZE ] );
void showBoard( int array[][ SIZE ] );

int main() {
    int board[ SIZE ][ SIZE ];

    // seed for random number generator
    srand( time( NULL ) );

    do{
       // initialize board
        for( currentRow = 0; currentRow < SIZE; ++currentRow ) { // loop through the rows
            for( currentColumn = 0; currentColumn < SIZE; ++currentColumn ) { // loop throught the columns
                board[ currentRow ][ currentColumn ] = 0;
            } // end inner for 
        } // end outer for
    }while( !solveNQ( board ) ); // while all the n queens are not place
    
    showBoard( board ); // show the board
    return 0;
} // end function main

// function solveNQ
int solveNQ( int chessboard[][ SIZE ] ) {
    size_t iQueen = 1;
    int eliminationNumbers[ SIZE ][ SIZE ] = {{ 22, 22, 22, 22, 22, 22, 22, 22 }, 
                                              { 22, 24, 24, 24, 24, 24, 24, 22 }, 
                                              { 22, 24, 26, 26, 26, 26, 24, 22 }, 
                                              { 22, 24, 26, 28, 28, 26, 24, 22 }, 
                                              { 22, 24, 26, 28, 28, 26, 24, 22 },
                                              { 22, 24, 26, 28, 28, 26, 24, 22 },
                                              { 22, 24, 24, 24, 24, 24, 24, 22 },
                                              { 22, 22, 22, 22, 22, 22, 22, 22 }};

    // currentRow and currrentColumn are global variables
    currentRow = rand() % SIZE; // choose a random row
    currentColumn = rand() % SIZE; // choose a random column
    chessboard[ currentRow ][ currentColumn ] = iQueen; // initialize the starting square

    for( iQueen = 2; iQueen <= QUEENS; ++iQueen ) {
        // choose the next square to place a queen
        chooseNextSquare( chessboard, eliminationNumbers );

        // initialize the new choosen square( done is a global variable )
        if( !done ) { // if there is no new choosen square to place a queen
            return 0;
        } // end if

        // if a new row and a new column has been choosen
        chessboard[ currentRow ][ currentColumn ] = iQueen;
        highestEliminationNumber = 30; // reinitialize highestEliminationNumber
        done = 0; 
    } // end for  

    return 1; // the n queens has been placed
} // end function solveNQ

// function chooseNextSquare
void chooseNextSquare( int chess[][ SIZE ], int eliminations[][ SIZE ] ) {
    size_t row = 0; 
    size_t column = 0;

    for( row = 0; row < SIZE; ++row ) {
        for( column = 0; column < SIZE; ++column ) {
            if( isSafe( row, column, row + column, row - column, chess ) ) {
                if( eliminations[ row ][ column ] < highestEliminationNumber ) {
                    currentRow = row;
                    currentColumn = column;
                    highestEliminationNumber = eliminations[ row ][ column ];
                } // end inner
                else if( eliminations[ row ][ column ] == highestEliminationNumber ) {
                    if( rand() % 2 == 1 ) {
                        currentRow = row;
                        currentColumn = column;
                    } // end inner if
                } // end inner else if
                done = 1; // a safe square to place a queen has been choosen
            } // end outer if
        } // end inner for
    } // end outer for
} // end function chooseNextSquare

// function isSafe
int isSafe( size_t iRow, size_t iColumn, size_t iRightDiagonal, size_t iLeftDiagonal, int board[][ SIZE ] ) {
    size_t i = 0;
    size_t tmpRow = 0;
    size_t tmpColumn = 0;

    // loop through a row and a column
    for( i = 0; i < SIZE; ++i ) {
        if( board[ i ][ iColumn ] ) { // Is this row already occupied by a queen?
            return 0;
        } // end if
        if( board[ iRow ][ i ] ) { // Is this column already occupied by a queen?
            return 0;
        } // end if
    } // end for

    // loop through the board
    for( tmpRow = 0; tmpRow < SIZE; ++tmpRow ) {
        for( tmpColumn = 0; tmpColumn < SIZE; ++tmpColumn ) {
            // test for the right and the left diagonal of the square board[ iRow ][ iColumn ]
            if( ( ( tmpRow + tmpColumn ) == iRightDiagonal ) || ( ( tmpRow - tmpColumn ) == iLeftDiagonal ) ) { 
                if( board[ tmpRow ][ tmpColumn ] ) { // Is the right or left diagonal occupied by a queen?
                    return 0;
                } // end inner if
            } // end outer if
        } // end inner for
    } // end outer for
    return 1; // the square is safe
} // end function isSafe

// function showBoard
void showBoard( int array[][ SIZE ] ) {
    size_t row = 0; // counter for the rows
    size_t column = 0; // counter for the columns

    // print header
    printf( "\n%33s", "C H E S S B O A R D\n\n" );

    for( row = 0; row < SIZE; ++row ) { // loop through the rows
        for( column = 0; column < SIZE; ++column ) { // loop through the columns
            printf( "%5d", array[ row ][ column ] );
        } // end inner for 

        puts( "" ); // new line of output
        puts( "" ); // new line of output
    } // end outer for
} // end function showBoard