// This program simulate the rolling of two dice
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 13
#define ROLL 36000

// function prototypes
int rollDice( void );
void printArray1D( const int a[], size_t size );

// function main begins program execution
int main( void )
{
    int freq[ SIZE ] = { 0 }; // count a sum's frequency
    int sum; // hold the sum of the roll dice
    int sevenCounter = 0; // count the number of seven
    size_t j; // counter for the array freq elements
    int frequenciesTotal = 0; // hold the sum of the frequencies

    // seed for the random number generator
    srand( time( NULL  ) );

    // start rolling dice
    for( int i = 0; i < ROLL; ++i )
    {
        sum = rollDice() + rollDice(); // sum of the roll dice

        ++freq[ sum ]; // count a sum's frequency
    } // end for

    // print the different values possible for each roll dice
    printf( "%s", "The different values possible for each roll dice are:\n");
    for( int i = 1; i <= 11; ++i )
    {
        printf( "%4d\t", i + 1 );
    } // end for
    
    puts("\nThe frequencies respectively are: " );
    // print array freq elements
    printArray1D( freq, SIZE );

    // is freq[ 7 ] approximately equal to one-sixth of all the roll
    if( ( ROLL / 6 - 50 <= freq[ 7 ] ) && ( freq[ 7 ] <= ROLL / 6 + 50  ) ) 
    {
        puts( "\nThe result is raisonable." );
    } // end if
    else
    {
        puts( "\nThe result is not raisonable." );
    } // end else
} // end main

// Definition function rollDice
int rollDice( void )
{
    return( 1 + rand() % 6 );                    
} // end function rollDice

// Definition function printArray1D
void printArray1D( const int a[], size_t size )
{
    size_t i; // counter for array a elements

    // print array a element
    for( i = 2; i < size; ++i )
    {
        printf( "%d\t", a[ i ] );
    } // end for
} // end function printArray1D