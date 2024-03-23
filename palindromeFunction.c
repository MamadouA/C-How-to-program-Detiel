// Determine if a string is a palindrome or nor
#include <stdio.h>
#include <stdbool.h>

bool isASymbol( char x ); // function prototype
int testPalindrome( const char charArray[], size_t firstElement, size_t lastElement ); // function prototype

// Function main begins program execution
int main( void )
{
	char string[] = "+ able was i, ere i saw elba.";
	
	if( testPalindrome( string, 0, sizeof( string ) / sizeof( string[ 0 ] ) - 2 ) == 1 ){
		
		printf( "-->%s<-- is a palindrome", string );
	} // end if	
	else{
		
		printf( "-->%s<-- is not a palindrome", string );
	} // end else
		
	
	
	return 0;
} // End function main


// Definition function testPalindrome
int testPalindrome( const char charArray[], size_t firstElement, size_t lastElement )
{
	// base case
	if( firstElement >= lastElement ){
		
		return 1;
	}
	// if the first element of the comparaison is not a letter
	if( isASymbol( charArray[ firstElement ] ) ){
		
		return ( testPalindrome( charArray, ++firstElement, lastElement ) );
	}
	// if the second element of the comparaison is not a letter
	if( isASymbol( charArray[ lastElement ] ) ){
		
		return ( testPalindrome( charArray, firstElement, --lastElement ) );
	}
	// if the first element and the second element of the comparaison are different
	if( charArray[ firstElement ] != charArray[ lastElement ] ){
		
		return -1;
	}  // end if
	
	// recursive steps
	return( testPalindrome( charArray, ++firstElement, --lastElement ) );
} // End function testPalindome

// Function isASymbol
bool isASymbol( char x )
{
	int symbolsCounter = 0;
	char symbols[] = " ,;.'-_=+";
	
	for( ; symbols[ symbolsCounter ] != '\0'; ++symbolsCounter ){
		
		if( symbols[ symbolsCounter ] == x )
			return true;
	} // end for
	
	return false;
} // end function isASymbol










