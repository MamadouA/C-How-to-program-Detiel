// This program read a number
// and print it only if it is not a duplicate
// of a number already read
#include <stdio.h>
#define SIZE 20

// function main begins program execution
int main( void )
{
    int table[ SIZE ] = { 0 }; // initialize array table
    size_t i = 0; // counter for array table elements
    size_t j; // counter for array table elements
    size_t duplicateNumberCounter = 0; // counter for the duplicate number

    // display message
    printf( "%s", "Enter only numbers between 10 and 100" );
    puts( "" ); // start a new line

    for( i = 0; i < SIZE; ++i )
    {
        // input another number
        printf( "%s", "\nEnter a number: " );
        scanf( "%d", &table[ i ] );

        // while table[ i ] is not between 10 and 100
        while( table[ i ] < 10 || table[ i ] > 100 ) 
        {   
            // input another number
            printf( "\n%s", "Number incorrect! Try another number: " );
            scanf( "%d", &table[ i ] );
        } // end while

        // search for a duplicate number
        for( j = 0; j < i; ++j )
        {
            if( table[ i ] == table[ j ] )
            {
                ++duplicateNumberCounter;
            } // end if
        } // end inner for

        // if table[ i ] is not a duplicate number
        if( duplicateNumberCounter == 0 )
        {
            printf( "\narray[ %d ] = %d which is not a duplicate"
                    " of a number already read.\n", i, table[ i ] );
        } // end if

        // reinitialize the duplicate number counter
        duplicateNumberCounter = 0;
    } // end outer for
} // end main