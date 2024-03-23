#include <stdio.h>
#define FIRST_CLASS 1
#define ECONOMY 2
#define MAX_SEATS 10
#define SIZE 11
// Function prototypes
int assignSeatsInFirstClass( int seats[] );
int assignSeatsInEconomySection( int seats[] ); 
void printArray1D( int array[], int size );

int passengersCounter = 0; // count the number of passengers

// Function main begins program execution 
int main( void )
{
    int choosenSection;
    int places[ SIZE ] = { 0 };
    int seatsCounter = 1;

    do
    {
        // input section
        printf( "%s", "\n\nPlease type 1 for first class\nPlease type 2 for economy"
                    "\nEnter your choice: " );
        scanf( "%d", &choosenSection );
        getchar();

        // which section was choosen
       switch( choosenSection )
       {
           case FIRST_CLASS: 
                assignSeatsInFirstClass( places ); // reserve a seat in the first class
                break;
            case ECONOMY: 
                assignSeatsInEconomySection( places ); // reserve a seat in the economy section
                break;
            default:
                printf( "%s", "\nPlease enter a correct number." );
                break;
       } // end switch 

       seatsCounter = passengersCounter;
    } while( seatsCounter < MAX_SEATS );

    printf( "%s", "\n\nThe plan is full complete.\nAll the seats are already assigned.\n" );
    printArray1D( places, SIZE );    
} // end main

// Definition function assignSeatsInFirstClass
int assignSeatsInFirstClass( int seats[] )
{
    static int firstClassSeats = 0; // count the number of seats in first class
    char choice;

    // count the number of seats in the first class section
    ++firstClassSeats;

    // check if all the seats in the first class already assigned
    if( firstClassSeats > MAX_SEATS / 2 )
    {
        printf( "%s", "\n\nThe first class is full complete.\n"
                    "Is it acceptable for you to be placed in the economy section ( y or n? ): " );
        choice = getchar();

        if( choice == 'n' ) // Is choice = no?
        {
            printf( "%s", "\nNext flight leaves in 3 hours." );
        } // end if
        else
        {
            assignSeatsInEconomySection( seats ); // reserve a seats in the economy section
        } // end else  

        return 0;
    } // end if

    // reserve a seat
    seats[ firstClassSeats ] = 1;

    // count the number of seats already assigned
    ++passengersCounter;

    // print a boarding pass
    printf( "\nPassenger number %d.", passengersCounter );
    printf( "\nSeat number %d\nIn the first class section", firstClassSeats );

    return 0;
} // end function assignSeatsInFirstClass

// Definition function assiSeatsInEconomySection
int assignSeatsInEconomySection( int seats[] )
{
    static int economySectionSeats = 5; // initialize the economy section seats counter
    char choice;

    ++economySectionSeats; // count the number of seats in the economy 
    
    // check if all the seats in the economy section are already assigned
    if( economySectionSeats > MAX_SEATS )
    {
        printf( "%s", "\n\nThe economy section is full complete.\n"
                    "Is it acceptable for you to be placed in the first class section( y or n? ): " );
        choice = getchar();

        // is choice = 'n'
        if( choice == 'n' )
        {
            printf( "%s", "\nNext flight leaves in 3 hours." );
        } // end if
        else
        {
            assignSeatsInFirstClass( seats ); // reserve a seat in the first class section
        } // end else
        
        return 0;
    } // end if

    // reserve a seat
    seats[ economySectionSeats ] = 1;

    // coun the number of passengers
    ++passengersCounter;

    // print a boarding pass
    printf( "\nPassenger number %d", passengersCounter );
    printf( "\nSeat number %d\nIn the economy secion", economySectionSeats );

    return 0;

} // end function assignSeatsInEconomySection

// Definition function printArray1D
void printArray1D( int array[], int size )
{
    for( int i = 1; i < size; ++i )
    {
        printf( "%3d", array[ i ] );
    } // end for
} // end function printArray1D
