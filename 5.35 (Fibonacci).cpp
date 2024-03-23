// This program calculate the nth Fibonacci number
#include <stdio.h>
unsigned long long int fibonacci( int numTerm ); // function fibonacci prototype

// Function main
int main( void )
{
	int term; // Terme's number
	
	// Input the terme's number from the user
	printf("%s", "Enter the term's number: ");
	scanf("%d", &term);
	
	// Display the result
	printf("Fibonacci( %d ) = %llu", term, fibonacci( term ) );
} // End function main

// Definition funtion fibonacci
unsigned long long int fibonacci( int numTerm )
{
	unsigned long long int term0 = 0;
	unsigned long long int term1 = 1;
    unsigned long long int term2;
	unsigned int i;
	
	// Case term's number = 1 or term's number = 2
	if( numTerm == 0 || numTerm == 1 )
		return numTerm;
	// Case terme'number != 1 and terme's number != 2	
	for( i = 3; i <= numTerm; ++i )
	{ // Terme value calculation
		term2 = term1 + term0;
		term0 = term1;
		term1 = term2;
	} // End for
	
	return term2;
} // End funtion fibonacci

