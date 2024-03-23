// Binary search of a sorted array.
#include <stdio.h>
#define SIZE 15

// function prototypes
size_t binarySearch( int array[], size_t startingSubscript, size_t endingSubscript, int key );
void printHeader( void );
void printfRow( const int b[], size_t low, size_t mid, size_t high );

// function main begins program execution
int main( void )
{
	int a[ SIZE ]; // create array a
	size_t i; // counter for initializing elements of array a
	int key; // value to locate in array a
	size_t result; // variable to hold location of key or -1
	
	// create data
	for( i = 0; i < SIZE; ++i )
	{
		a[ i ] = 2 * i;
	} // end for
	
	printf( "%s", "Enter a number between 0 and 28: " );
	scanf( "%d", &key );
	
	printHeader();
	
	// search for key in array a 
	result = binarySearch( a, 0, SIZE - 1, key );
	
	// display reslut
	if( result != -1 )
	{
		printf( "\n%d found in array element %d\n", key, result );
	} // end if
	else
	{
		printf( "\n%d not found\n", key );
	} // end else
} // end main

// function to perform binary search of an array
// Recursive binarySearch
size_t binarySearch( int array[], size_t startingSubscript, size_t endingSubscript, int key )
{	
	// display subarray used in this loop iteration
	printfRow( array, startingSubscript, ( startingSubscript + endingSubscript ) / 2, endingSubscript );

	// if the key was found
	if( array[ ( startingSubscript + endingSubscript ) / 2 ] == key ) {
		
		return ( ( startingSubscript + endingSubscript ) / 2 );
	}
	// if the key was not found
	if( startingSubscript == endingSubscript ) {
		
		return -1;
	} 
	if( key < array[ ( startingSubscript + endingSubscript ) / 2 ] ) {
		
		return ( binarySearch( array, startingSubscript, ( startingSubscript + endingSubscript ) / 2 - 1, key ) );
	}
		
	return( binarySearch( array, ( startingSubscript + endingSubscript ) / 2 + 1, endingSubscript, key ) );
} // end binarySearch

// printf a header for the output
void printHeader( void )
{
	unsigned int i; // counter
	
	puts( "\nSubscript: " );
	
	// output colomn head
	for( i = 0; i < SIZE; ++i )
	{
		printf( "%3u ", i );
	} // end for
	
	puts( "" ); // start new line of output
	
	// output line of - characters
	for( i = 1; i <= 4 * SIZE; ++i )
	{
		printf( "%s", "-" );
	} // end for
	
	puts( "" ); // start new line of output
} // end function printHeader

// Print one row of output showing the current
// part of the array being processed.
void printfRow( const int b[], size_t low, size_t mid, size_t high )
{
	size_t i; // counter for iterating through array b
	
	// loop through entire array
	for( i = 0; i < SIZE; ++i )
	{
		// display spaces if outside current subarray range
		if( i < low || i > high )
		{
			printf( "%s", "    " );
		} // end if  
		else if( i == mid )
		{
			// display middle element
			printf( "%3d*", b[ i ] ); // mark middle value
		} // end else if
		else
		{
			// display other elements in subarray
			printf( "%3d ", b[ i ] );
		} // end else
	} // end for
	
	puts( "" ); // start a new line of output
} // end function printRow
