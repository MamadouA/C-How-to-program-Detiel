// For visualizing recursion
#include <stdio.h>
unsigned int factoriel( unsigned int x );

// Function main
int main( void )
{
	unsigned int number = 6;
	
	factoriel( number );	
}

// Definition function factoriel
unsigned int factoriel( unsigned int x )
{
	unsigned int space;
	static int counter = 1;
	
	for( space = 1; space <= counter; ++space )
		printf( " " );
	printf( "Call number %u of the function with the argument %u\n", counter, x );
	
	if( x == 1 )
	{
		return 1;
	}	
	else
	{
		counter++;
		return( x * factoriel( x - 1 ) );
	}
}
