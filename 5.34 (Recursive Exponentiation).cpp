// This program use a recurive function to calculate x pow y

#include <stdio.h>
int power( int base, int exponent ); // Function power prototype

// Function main
int main( void )
{
	int x, y;
	
	// Input variables from the user
	printf("%s", "Enter respectively the base and the exponent: ");
	scanf("%d%d", &x, &y);
	
	// Display the result after calculation
	printf("%d pow %d = %3d", x, y, power( x, y ) );
} // End function main

// Definition function power
int power( int base, int exponent )
{
	if( exponent == 1 )
	{ // base case
		return base;
	} // End if	
	else
	{ // recursive call
		return ( base * power( base, exponent - 1 ) );
	} // End else
		
} // End function power 
