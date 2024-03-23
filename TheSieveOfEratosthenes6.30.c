// Determine the prime numbers between 1 and 999
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define NUMBER_OF_SUBSCRIPTS 1000

// function prototypes
bool isAPrimeNum( int number );
void eliminateMultiples( int index[], int x );
void showNumbersStatus( int array[] );

// Function main begins program execution
int main( void )
{   
    int subscriptsCounter = 0;
    int numbersStatus[ NUMBER_OF_SUBSCRIPTS ];

    // initialize the status of subscript 0 and 1 to 0
    numbersStatus[ 1 ] = 0;

    // initialize array numbersStatus
    for( int subscriptsCounter = 2; subscriptsCounter < NUMBER_OF_SUBSCRIPTS; ++subscriptsCounter)
    {
        numbersStatus[ subscriptsCounter ] = 1;
    } // end for

    // determine the status of each number
    for( subscriptsCounter = 2; subscriptsCounter < NUMBER_OF_SUBSCRIPTS; ++subscriptsCounter )
    {
        if( isAPrimeNum( subscriptsCounter ) )
        {
            eliminateMultiples( numbersStatus, subscriptsCounter );
        } // end if
    } // end for

    showNumbersStatus( numbersStatus );
    return 0;
} // End function main

// Definition function isAPrimeNum
bool isAPrimeNum( int subscript )
{
    for( int counter = 2; counter <= sqrt( subscript ); ++counter )
    {
        if( subscript % counter == 0 ) // is subscript a multiple of counter?
            return false;
    } // end for

    return true;
} // End function isAPrimeNum

// Definition function eliminateMultiples
void eliminateMultiples( int index[], int startingSubscript )
{
    for( int subscript = startingSubscript + 1; subscript < NUMBER_OF_SUBSCRIPTS; ++subscript )
    {
        if( subscript % startingSubscript == 0 ) // is subscript a multiple of startingSubscript?
            index[ subscript ] = 0;
    } // end for
} // End function eliminateMultiples

void showNumbersStatus( int array[] )
{
    int i = 1;

    // print headers
    printf( "\n%s", "S U B S C R I P T" );

    for( ; i < NUMBER_OF_SUBSCRIPTS / 30; ++ i )
    {
        printf( "%4d", i );
    } // end for

    printf( "\n\n%17s", "S T A T U S" );

    // show the status of each numbers
    for( i = 1; i < NUMBER_OF_SUBSCRIPTS / 30; ++i )
    {
        printf( "%4d", array[ i ] );
    } // end for

    puts( "" );
} // End function print1DArray