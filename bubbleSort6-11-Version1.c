// Fig 6.15 version1
// Sorting an array's values into ascending order
#include <stdio.h>
#define SIZE 10

int main( void )
{
    // initialize a
    int a[ SIZE ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
    int pass; // passes counter
    size_t i; // comparisons counter
    int hold; // temporary location used to swap array elements
    int swapCounter = 0; // count the number of swap

    puts( "Data items in original order" );

    // output original array
    for( i = 0; i < SIZE; ++i )
    {
        printf( "%4d", a[ i ] );
    } // end for

    // bubble sort
    // loop to control the number of passes
    for( pass = 1; pass < SIZE - 1; ++pass )
    {
        // loop to control number of comparisons per pass
        for( i = 0; i < SIZE - pass; ++i )
        {
            // compare elements and swap them if first 
            // element is greater than second element
            if( a[ i ] > a[ i + 1 ] )
            {
                hold = a[ i ];
                a[ i ] = a[ i + 1 ];
                a[ i + 1 ] = hold;
                
                ++swapCounter;
            } // end if
        } // end inner for

        // test if swaps have been made
        if( swapCounter == 0 )
        {
            break;
        } // end if
        else
        {
            swapCounter = 0;
        } // end else
    } // end outer for

    puts( "\nData items in ascending order" );
    
    // output sorted array
    for( i = 0; i < SIZE; ++i )
    {
        printf( "%4d", a[ i ] );
    } // end for

    puts( "" );
} // end



















