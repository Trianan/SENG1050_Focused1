/*
    FILE           : f1.cp
    PROJECT        : Focused Assignment #1 - SENG1050
    PROGRAMMER     : Tristin A. Manson - Student ID: 8988333
    FIRST VERSION  : May 12th, 2024
    REPOSITORY URL : https://github.com/Trianan/SENG1050_Focused1
        -> NOTE: this is a private repository; I'll have to add you as a
          collaborator or take screenshots if you want to see it.
    DESCRIPTION    :
          This program prompts the user for 10 pairs of strings; the first
          of a pair representing a destination for a flight, and the second
          representing the departure date of that flight. The program then
          outputs the formatted contents of all inputted flights.
*/

//------------------------------------------------------------------------------
#pragma warning(disable: 4996)
#include <stdlib.h> // malloc, free
#include <stdio.h> // printf, fgets
#include <string.h> // strlen, strcpy

// Return codes for main
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

// Return codes for fillFlightInfo:
#define MALLOC_SUCCESS 1
#define MALLOC_FAILURE 0

// Return codes for getUserInput:
#define READ_SUCCESS 1
#define READ_FAILURE 0

// Constraints:
#define MAX_FLIGHTS 10
#define MAX_INPUT_BYTES 30
#define PRINT_FIELD_WIDTH 35

// Constants:
#define NEWLINE '\n'

//------------------------------------------------------------------------------
typedef struct {
    char* destination;
    char* departureDate;
} FlightInfo;

int fillFlightInfo(FlightInfo*, char*, char*);
void printFlightInfo(FlightInfo*, int);
void cleanString(char*, size_t);
int getUserInput(char*, size_t = MAX_INPUT_BYTES);


//------------------------------------------------------------------------------
int main(void) {
    FlightInfo flights[MAX_FLIGHTS] = { 0 };

    // Get MAX_FLIGHTS pairs of destination - departure date strings from the user:
    printf("Please enter %d pairs of flight destination-departure date pairs:\n", MAX_FLIGHTS);
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        printf("Flight #%d:\n", i + 1);

        char destinationInput[MAX_INPUT_BYTES] = { 0 };
        printf("\tPlease enter a flight destination > ");
        if (!getUserInput(destinationInput)) {
            printf("Could not get destination input!\n");
            return EXIT_FAILURE;
        }

        char departureInput[MAX_INPUT_BYTES] = { 0 };
        printf("\tPlease enter a departure date > ");
        if (!getUserInput(departureInput)) {
            printf("Could not get departure input!\n");
            return EXIT_FAILURE;
        }

        if (!fillFlightInfo(&flights[i], destinationInput, departureInput)) {
            printf("Out of memory! Terminating...\n");
            return EXIT_FAILURE;
        }
    }

    // Call printFlightInfo(flights)
    printFlightInfo(flights, MAX_FLIGHTS);


    // Free allocated memory for each field in each FlightInfo:
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
        This function returns a status integer MALLOC_SUCCESS indicating success, or
        MALLOC_FAILURE indicating failure.
*/
int fillFlightInfo(FlightInfo* flight, char* destination, char* departureDate) {

    char* pDestination = (char*)malloc(strlen(destination) + 1); // +1 to account for '\0'
    char* pDepartureDate = (char*)malloc(strlen(departureDate) + 1);

    if (!pDestination || !pDepartureDate) {
        return MALLOC_FAILURE;
    }

    strcpy(pDestination, destination);
    flight->destination = pDestination;

    strcpy(pDepartureDate, departureDate);
    flight->departureDate = pDepartureDate;

    return MALLOC_SUCCESS;
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
    for (int i = 0; i < flightCount; i++) {
        printf(
            "%-*s%-*s\n",
            PRINT_FIELD_WIDTH, flights[i].destination,
            PRINT_FIELD_WIDTH, flights[i].departureDate
            );
    }
}


/*
    FUNCTION    : cleanString
    DESCRIPTION :
        Sets all newlines found in a string to '\0', up to the
        provided number of characters. Sets last char to '\0' as
        well to ensure string is in appropriate C-style format.
    PARAMETERS  :
        str    : the string to covert newlines from
        strLen : the length of the string, or number of characters to
            convert up to.
    RETURNS     :
        This function does not return anything.
*/
void cleanString(char* str, size_t strLen) {
    for (int i = 0; i < strLen; i++) {
        if (str[i] == NEWLINE) {
            str[i] = NULL;
        }
    }
    // Set last char to null to ensure it's null-terminated:
    str[strLen - 1] = NULL; // might error for null strings!
}


/*
    FUNCTION    : getUserInput
    DESCRIPTION :
        Reads a string of user input into a buffer, then sanitizes it; it
        ensures the user input does not contain newlines and is null-terminated,
        making it a valid C-style string.
    PARAMETERS  :
        buffer: the char arraay to read user input into.
        buffer: the size of buffer.
    RETURNS     :
        Returns READ_SUCCESS on successfully obtaining user input; otherwise
        returns READ_FAILURE.
*/
int getUserInput(char* buffer, size_t bufferSize) {
    if (!fgets(buffer, bufferSize, stdin)) {
        return READ_FAILURE;
    }
    cleanString(buffer, bufferSize);
    return READ_SUCCESS;
}
