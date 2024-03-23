// Simulating the game of craps
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LASTGAME 1000
#define SIZE 22

// function prototypes
int startGame( void );
int rollDice( void );
void freq( int gamesCounter[] );
int sumArrayElements( const int array[] );
void printResults( const int gamesWon[], const int gamesLost[] );

int rollCounter = 0; // roll counter

// enumeration constant represent the game status
enum status{ CONTINUE, WON, LOST };

enum status gameStatus; // can contain CONTINUE, WON, or LOST

// function main
int main( void )
{
	int i = 1; // game's counter
	int gamesWonAfterXRoll[ SIZE ] = { 0 }; // counter for the games won after x roll
	int gamesLostAfterXRoll[ SIZE ] = { 0 }; // counter for the games lost after x roll
	int totalRoll = 0; // total the roll for 1000 games

	// randomerize the random number generator using the current time
	srand( time( NULL ) );
	
	do
	{
		// print the game number
		printf( "\n\nGame number %d\n\n", i );

		// run one game of craps
		startGame();
	
		// display won or lost message
		if( gameStatus == WON ) // Did player win?
		{
			puts( "Player win." );
			
			// count the number of games won 
			// after x roll
			freq( gamesWonAfterXRoll );
		}
		else // player lost
		{
			puts( "Player loses." );

			// count the number of games 
			// lost after x roll
			freq( gamesLostAfterXRoll );
		} // end if
		
		// calculate the total number of rolls
		totalRoll += rollCounter;

		// after each game reinitialize rollCounter
		rollCounter = 0;

		// increment the game's counter
		++i;
	}while( i <= LASTGAME );

	// output the results
	printResults( gamesWonAfterXRoll, gamesLostAfterXRoll );

	// display the chances of winning a game of craps
	printf( "\nThe chances of winning a game of craps: %d %%", 
			sumArrayElements( gamesWonAfterXRoll ) * 100 / LASTGAME );
	
	// display the average length of a game of craps
	printf( "\nThe average length of a game of craps: %d", 
			totalRoll / LASTGAME );
} // end main

// Definition function rollDice
int rollDice( void )
{
	int die1; // first die
	int die2; // second die
	int worksum; // sum of dice
	
	// count how many times the function rollDice is called
	++rollCounter;

	die1 = 1 + rand() % 6; // pick random die1 value
	die2 = 1 + rand() % 6; // pick random die2 value
	worksum = die1 + die2; // sum die1 and die2
	// display the roll number
	printf( "Roll Number %d\n", rollCounter );

	// display result of this roll
	printf( "Player rolled %d + %d = %d\n", die1, die2, worksum );

	return worksum; // return sum of dice
} // end function rollDice

// Definition function startGame
int startGame( void )
{
	int sum; // sum of rolled dice
	int myPoint; // player must make this point to win
	int rollCounter = 0; // count the number of rolls
	
	sum = rollDice(); // first roll of dice
	
	// Determine game satus based on sum of dice
	switch( sum )
	{
		// win on first roll
		case 7: // is a winner
		case 11: // is a winner
			gameStatus = WON; // game has been won
			break;
		// lose on first roll
		case 2: // is a loser
		case 3: // is a loser
		case 12: // is a loser
			gameStatus = LOST; // game has been lost
			break;
			
		// remember point
		default:
			gameStatus = CONTINUE; // Player should keep rolling
			myPoint = sum; // remember the point
			printf( "Point is %d\n", myPoint );
			break; // optional
	} // end of switch
	
	// while game not complete
	while( gameStatus == CONTINUE ) // player should keep rolling
	{
		sum = rollDice(); // roll dice again
		
		// determine gameStatus
		if( sum == myPoint ) // win by making point
		{
			gameStatus = WON; // game over, player won
		} // end if
		else
		{
			if( sum == 7 ) // lose by making 7
			{
				gameStatus = LOST; // game over, player lost
			} // end if
		} // end else
	} // end while
} // end function startGame

// Definition function freq
void freq( int gamesCounter[] )
{
	if( rollCounter <= 20 )
	{
		// count the number of games 
		// won ( or lost ) after x roll if x < 20
		++gamesCounter[ rollCounter ];
	} // end if
	else
	{
		// count the number of games 
		// won ( or lost ) after 21 roll
		++gamesCounter[ 21 ]; 
	} // end else	
} // end function freq

// Definition function printResults
void printResults( const int gamesWon[], const int gamesLost[] )
{
	size_t i; // counter for the array elements

	// display indications
	printf( "%s", "\nThe following table print the number\n" 
			"of games won and the number of games lost\n"
				"for each number of roll" );
	
	// print headers for the outputs
	printf( "%s", "\nNumber of rolls" "     Number of games won " "     Number of games lost" );

	// number of games won ( lost ) before the twentieth roll
	for( i = 1; i < SIZE - 1; ++i )
	{
		printf( "\n%15u%24d%25d", i, gamesWon[ i ], gamesLost[ i ] );
	} // end for

	// number of games won( lost ) after the twnetieth roll
	printf( "\nThe number of games won after the twentieth roll: %d", gamesWon[ 21 ] );
	printf( "\nThe number of games lost after the twentieth roll: %d", gamesLost[ 21 ] );

	puts( "" ); // begins a new line of output
} // end function printResults

// Definition function sumArrayElements
int sumArrayElements( const int array[] )
{
	size_t i; // counter for array elements
	int sum = 0; // total the array elements

	// calculate array elements sum
	for( i = 1; i < SIZE; ++i )
	{
		sum += array[ i ];
	} // end for

	return sum;
} // end functin sumArrayElements

