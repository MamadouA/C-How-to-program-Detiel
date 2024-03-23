// Simulating the game of craps
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int startGame( void ); // function prototype
int rollDice( void ); // function prototype

// enumeration constant represent the game status
enum status{ CONTINUE, WON, LOST };

enum status gameStatus; // can contain CONTINUE, WON, or LOST

// function main
int main( void )
{
	int wager;
	int bankBalance = 1000;
	
	// randomerize the random number generator using the current time
	srand( time( NULL ) );
	
	// input wager from player
	printf( "%s", "Enter a wager ( 0 < wager < 1000 ): " );
	scanf( "%d", &wager );
	
	// while wager is incorrect input wager
	while( wager < 0 || wager > 1000 )
	{
		printf( "%s", "Please Enter a correct wager: " );
		scanf( "%d", &wager );
	} // End while
	
	// run one game of craps
	startGame();
	
	// display won or lost message
	if( gameStatus == WON ) // Did player win?
	{
		puts( "Player win." );
		puts( "You're up big. Now's the time to cash in you're chips!" );
		
		// increase the bankBlance by wager
		bankBalance += wager;
		printf( "BankBalance = %d", bankBalance ); // print the new bankBalance
	}
	else // player lost
	{
		puts( "Player loses." );
		
		// decrease the bankBalance by wager
		bankBalance -= wager;
		printf( "bankBalance = %d\n", bankBalance ); // print the new bankBalance
		
		if( bankBalance == 0 ) // if bankBalance become 0
		{
			puts( "Sorry. You busted!" );
		} // end if
		else // if bankBalance > 0
		{
			puts( "Aw cmon, take a chance!" ); 
		} // end else	
	} // end else
} // end main

// Definition function rollDice
int rollDice( void )
{
	int die1; // first die
	int die2; // second die
	int worksum; // sum of dice
	
	die1 = 1 + rand() % 6; // pick random die1 value
	die2 = 1 + rand() % 6; // pick random die2 value
	worksum = die1 + die2; // sum die1 and die2
	
	// display result of this roll
	printf( "Player rolled %d + %d = %d\n", die1, die2, worksum );
	return worksum; // return sum of dice
} // end function rollDice

// Definition function startGame
int startGame( void )
{
	int sum; // sum of rolled dice
	int myPoint; // player must make this point to win
	
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
