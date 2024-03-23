#include <stdio.h>

void tower( int n, int source, int temp, int destination );

int main( void )
{
	int n = 2;
	int source = 1;
	int temp = 2;
	int destination = 3;
	
	tower( n, source, destination, temp );
}

void tower( int n, int source, int destination, int temp ) 
{
	if( n == 1 )
		printf( "\n%d -----> %d\n", source, destination );
	else
	{
		tower( n - 1, source, temp, destination );
		printf( "\n%d -----> %d\n", source, destination );
		tower( n - 1, temp, destination, source );
	}
}
