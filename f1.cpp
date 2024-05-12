/*
    FILE          : f1.cp
    PROJECT       : Focused Assignment #1 - SENG1050
    PROGRAMMER    : Tristin A. Manson - Student ID: 8988333
    FIRST VERSION : May 12th, 2024
    DESCRIPTION   :
          This program prompts the user for 10 pairs of strings; the first
          of a pair representing a destination for a flight, and the second
          representing the departure date of that flight.

          The program then outputs the formatted contents of all inputted
          flights.
*/
//------------------------------------------------------------------------------
#pragma warning(disable: 4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define MAX_FLIGHTS 10
#define MAX_INPUT_BYTES 30
#define NEWLINE '\n'

#define UNIMPLEMENTED(n) return n //Remove before submission!

//------------------------------------------------------------------------------
typedef struct {
    char* destination;
    char* departureDate;
} FlightInfo;

int fillFlightInfo(FlightInfo*, char*, char*);
void printFlightInfo(FlightInfo*, int);
void clearBuffer(char*, size_t); // May be un-needed.
void cleanNewlines(char*, size_t);

//------------------------------------------------------------------------------
int main(void) {
    FlightInfo flights[MAX_FLIGHTS] = { 0 };

    // Prompt user for MAX_FLIGHTS pairs of strings;
    /* LOOP until MAX_FLIGHTS:
        
        Get FlightInfo @ current index

        Declare destinationBuffer
        Get destination string from user into buffer.

        Declare departureDateBuffer
        Get departure date from user into buffer.

        Call fillFlightInfo(gottenFlightInfo, destinationBuffer, departureDateBuffer)
    */

    // Call printFlightInfo(flights)

    // Free memory allocated for each FlightInfo field.


    // Get ten pairs of destination - departure date strings from the user:
    printf("Please enter %d pairs of flight destination-departure date pairs:\n", MAX_FLIGHTS);
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        printf("Flight #%d:\n", i + 1);

        char destinationInput[MAX_INPUT_BYTES] = { 0 };
        printf("\tPlease enter a flight destination > ");
        fgets(destinationInput, MAX_INPUT_BYTES, stdin);
        cleanNewlines(destinationInput, MAX_INPUT_BYTES);

        char departureInput[MAX_INPUT_BYTES] = { 0 };
        printf("\tPlease enter a departure date > ");
        fgets(departureInput, MAX_INPUT_BYTES, stdin);
        cleanNewlines(destinationInput, MAX_INPUT_BYTES);

        fillFlightInfo(&flights[i], destinationInput, departureInput);
        printf("flights[%d]: dest = %s, dept = %s\n", i, flights[i].destination, flights[i].departureDate);
    }

    // Free allocated heap memory for each FlightInfo:
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        if (flights[i].destination) {
            free(flights[i].destination);
        }
        if (flights[i].departureDate) {
            free(flights[i].departureDate);
        }
    }
    return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
/*
    FUNCTION    : fillFlightInfo
    DESCRIPTION :
        This function allocates memory for the destination and departureDate
        strings, then initializes the provided flight with the returned pointers.
    PARAMETERS  :
        flight        : pointer to the FlightInfo struct to initialize.
        destination   : pointer to string representing the flight destination.
        departureDate : pointer to string representing the flight departure date.
    RETURNS     :
        This function returns a status integer 1 indicating success, or
        0 indicating failure.
*/
int fillFlightInfo(FlightInfo* flight, char* destination, char* departureDate) {

    char* pDestination = (char*)malloc(strlen(destination) + 1); // +1 to account for '\0'
    char* pDepartureDate = (char*)malloc(strlen(departureDate) + 1);

    if (!pDestination || !pDepartureDate) {
        return 0;
    }

    strcpy(pDestination, destination);
    flight->destination = pDestination;

    strcpy(pDepartureDate, departureDate);
    flight->departureDate = pDepartureDate;

    return 1;
}


/*
    FUNCTION    : fillFlightInfo
    DESCRIPTION :
        This function prints formatted output for each FlightInfo struct
        contained with the flights array provided as an argument. The
        destination will be printed within the first 32 characters, and the
        departure date will be printed within the next 32 characters, both
        left-aligned.
    PARAMETERS  :
        flights : an array of FlightInfo structs to display.
    RETURNS     :
        This function does not return anything.
*/
void printFlightInfo(FlightInfo* flights, int flightCount) {
    UNIMPLEMENTED();
}


/*
    FUNCTION    : clearBuffer
    DESCRIPTION :
        Resets all the fields in a char array to '\0'.
    PARAMETERS  :
        buffer     : the char array to clear.
        bufferSize : the size of buffer.
    RETURNS     :
        This function does not return anything.
*/
void clearBuffer(char* buffer, size_t bufferSize) {
    // May be un-needed
    UNIMPLEMENTED();
}


/*
    FUNCTION    : cleanNewlines
    DESCRIPTION :
        Sets all newlines found in a string to '\0', up to the
        provided number of characters.
    PARAMETERS  :
        str    : the string to covert newlines from
        strLen : the length of the string, or number of characters to
            convert up to.
    RETURNS     :
        This function does not return anything.
*/
void cleanNewlines(char* str, size_t strLen) {
    for (int i = 0; i < strLen; i++) {
        if (str[i] == NEWLINE) {
            str[i] = NULL;
        }
    }
    return;
}

