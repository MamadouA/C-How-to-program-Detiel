// Help elementary school student learn multiplication
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateQuestions( void ); // function question prototype

// function main
int main( void )
{
	int correctResult; // contains the correct result
	int inputNumber; // input number
	
	//randomerize the random number generator
	srand( time( NULL ) );
	
	// indication if the user want to quite
	puts( "Enter -1 if you want to quit." );
	
	// display multiplication question and save the correct result
	correctResult = generateQuestions();
	
	// input a number from the user
	scanf( "%d", &inputNumber );
	
	while( inputNumber != -1 ) // while input number is not -1
	{
		if( inputNumber == correctResult ) // is inputNumber the correct answer?
		{
			puts( "Verry good!" );
			
			// display another question and save the correct result
			correctResult = generateQuestions();
		} // end if
		else
		{
			printf( "No. Please try again!: " );
		} // end else
		
		scanf( "%d", &inputNumber );
	}
} // end main

// Defintion function generateQuestions
int generateQuestions()
{
	int randNumber1 = 1 + rand() % 10;
	int randNumber2 = 1 + rand() % 10;
	// display a question
	printf( "How much is %d times %d?: ", randNumber1, randNumber2 );
	
	// return the correct answer
	return ( randNumber1 * randNumber2 );
} // end generateQuestions
