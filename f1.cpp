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
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define MAX_FLIGHTS 10
#define MAX_INPUT_BYTES 30


#define UNIMPLEMENTED(n) return n //Remove before submission!

//------------------------------------------------------------------------------
typedef struct {
    char* destination;
    char* departureDate;
} FlightInfo;

void fillFlightInfo(FlightInfo*, char*, char*);
void printFlightInfo(FlightInfo*);

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
        This function does not return anything (returning a status int may be good).
*/
void fillFlightInfo(FlightInfo* flight, char* destination, char* departureDate) {
    UNIMPLEMENTED();
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
void printFlightInfo(FlightInfo* flights) {
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
    UNIMPLEMENTED();
}
