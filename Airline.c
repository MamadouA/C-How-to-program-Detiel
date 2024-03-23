// Airline Reservations System
#include <stdio.h>
#define FIRST_CLASS 1
#define ECONOMY 2
#define MAX_SEATS 10
#define SIZE 11

// Function prototypes
void assignSeats( int places[], int section );
int getAnotherChoice( int class );
void print1DArray( int array[], size_t size );

int passengersCounter = 0;
int choosenSection;

// Function main begins program execution
int main( void )
{
    int seatsCounter = 0;
    int seats[ SIZE ] = { 0 };

    do
    {   
        // input the user's choice
        printf( "%s", "\n\nPlease type 1 for first class.\nPlease type 2 for economy section." );
        printf( "%s", "\nEnter your choice: " );
        scanf( "%d", &choosenSection );
        getchar();

        // assign a seat
        assignSeats( seats, choosenSection );

        // count the number of seats already assigned
        seatsCounter = passengersCounter;
    } while ( seatsCounter < MAX_SEATS );

    printf( "%s", "\n\nAll the seats are already assigned.\nThe plan is full.\n" );
    print1DArray( seats, SIZE ); 
} // end main

// Definition function assignSeats
void assignSeats( int places[], int section )
{
    static int firstClassSeats = 0;
    static int economySeats = 5;

    // check if the user's choosen section is full
    if( ( ( section == FIRST_CLASS ) && ( firstClassSeats == MAX_SEATS / 2 ) ) ||

            ( section == ECONOMY ) && ( economySeats == MAX_SEATS ) )
    {
        section = getAnotherChoice( section );
    } // end if

    switch( section )
    {
        case FIRST_CLASS:
            // count first class seats
            ++firstClassSeats;

            // reserve a seat
            places[ firstClassSeats ] = 1;

            // count the number of passengers
            ++passengersCounter;

            // display a boarding pass
            printf( "\nPassengers number %d", passengersCounter );
            printf( "\nSeats number %d.\nIn the first class section.", firstClassSeats );
            break;
        case ECONOMY:
            // count economy section seats
            ++economySeats;

            // reserve a seat
            places[ economySeats ] = 1;

            // count the number of passengers
            ++passengersCounter;

            // display a boading pass
            printf( "\nPassengers number %d", passengersCounter );
            printf( "\nSeats number %d.\nIn the economy section.", economySeats );
            break;
        default:
            printf( "%s", "\nNext flight leaves in 3 hours." );
            break;
    } // end switch
} // end function assignSeats

// Defintion function getAnotherChoice
int getAnotherChoice( int class )
{
    char choice;

    switch( class )
    {
        case FIRST_CLASS:
            // display message and input choice
            printf( "%s", "\nThe first class section is full.\n"
                    "Is it acceptable for you to be placed in the economy section ( y or n)?: " );
            scanf( "%c", &choice );

            // Is choice = 'y'?
            if( choice == 'y' )
                return ECONOMY;
            else 
                return 0;
            break;
        case ECONOMY:
            // display message and input choice
            printf( "%s", "\nThe economy secion is full.\n"
                    "Is it acceptable for you to be placed in the first class section( y or n )?: " );
            scanf( "%c", &choice );

            // Is choice = 'y'?
            if( choice == 'y' )
                return FIRST_CLASS;
            else
                return 0;
            break;
    } // end switch

    return 0;
} // end function getAnotherChoice

void print1DArray( int array[], size_t size )
{
    // print the array elements
    for( int i = 1; i < size; ++i )
    {
        printf( "%3d", array[ i ] );
    } // end for
} // end function print1DArray
