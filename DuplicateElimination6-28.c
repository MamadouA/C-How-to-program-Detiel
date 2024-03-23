#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define NUMBER_OF_VALUES 20

// Function prototype
bool isDuplicated( int numbers[], int x ); 
void print1DArray( int [] );

// Function main begins program execution
int main( void )
{
    int nonDuplicateNumbers[ NUMBER_OF_VALUES ] = { 0 };
    int numbersCounter = 0;
    int randNumber = 0;

    // seed for the random number generator
    srand( time( NULL ) );

    for( numbersCounter = 0; numbersCounter < NUMBER_OF_VALUES; ++numbersCounter )
    {
        randNumber = 1 + rand() % NUMBER_OF_VALUES;

        if( !isDuplicated( nonDuplicateNumbers, randNumber ) )
        {
            nonDuplicateNumbers[ numbersCounter ] = randNumber;
        } // end if
    } // end for

    print1DArray( nonDuplicateNumbers ); // show the non duplicate value
    return 0;
} // End function main

// Defintion function isDuplicate
bool isDuplicated( int numbers[], int x )
{
    for( int i = 0; i < NUMBER_OF_VALUES; ++i )
    {
        if( numbers[ i ] == x ) // is x a duplicate value
        {
            numbers[ i ] = 0; // reset numbers[ i ] to 0

            return true; 
        } // end if
    } // end for
    return false;
} // End function isDuplicate

// Definition function print1DArray
void print1DArray( int array[] )
{
    puts( "" );

    for( int i = 0; i < NUMBER_OF_VALUES; ++i )
    {
        printf( "%4d", array[ i ] );
    } // end for

    puts( "\n" );
} // End function print1DArray