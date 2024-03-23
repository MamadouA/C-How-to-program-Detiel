// To determinate the greatest common divisor between two integer

#include <stdio.h>
int gcd( int x, int y ); // Function gcd prototype

// Function main
int main( void )
{
	int number1;
	int number2;
	
	// Input number from user
	printf( "%s", "Enter two integers: ");
	scanf( "%d%d", &number1, &number2 );
	
	// Display result after calculation
	printf( "\nThe greatest common divisor between %d and %d is: %d", number1, number2, gcd( 2, 7 ) );
} // End function main

//Definition function greatest common divisor
int gcd( int x, int y )
{
	if( y == 0 )
	{ // The base case
		return x;
	} // End if
	else
	{ // If not the base case
		return( gcd( y, x%y ) );
	} // End else
} // End function gcd
