// This program simulates coin tossing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int flip( void ); // Funciton flip prototype

// Function main
int main( void )
{
	int tossNumber = 1;
	int headsCounter = 0;
	int tailsCounter = 0;
	
	// Seed for function random
	srand( time( NULL ) );
	
	// Begin similation
	do
	{
		if( flip() )
		{ // case heads
			printf("\t%s", "Heads");
			++headsCounter;
		} // End if
		else
		{ // case tails
			printf("\t%s", "Tails");
			++tailsCounter;
		} // End else
		
		// go to another line after 10 tabulation
		if( tossNumber % 10 == 0 )
			puts("");
			
		++tossNumber;	
	}while( tossNumber <= 100 );
	
	// Display the number of heads and tails
	printf("\nNumber of heads = %d", headsCounter);
	printf("\nNumber of tails = %d", tailsCounter);
} // End function main

// Definition function flip
int flip( void )
{	
	return rand() % 2;
} // End function flip
