#ifndef INCLUDED_INPUTFUNCTIONS
#define INCLUDED_INPUTFUNCTIONS
#include "Airport.h"
#include "Airline.h"
#include "Flight.h"
#include "constants.h"

//PRE: code ends in EOS and allAirlines ends in null
//POST:an airline object is constructed with data implemented
void makeAirline(Airline* allAirlines[], char inputCode[],int num);

//PRE: inputCode ends in EOS and allAirports ends in null
//POST:an airport object is constructed with the data implemented
void makeAirport(Airport* allAirports[], char inputCode[], int num);


//PRE: from and to are Airports following CI, cost is greater than 0, allFlights ends in null
//POST: a flight object is constructed with the data implemented; reference to flight is returned
Flight* makeFlight(Flight* allFlights[], int pCost, Airport* fromAir, Airport* toAir, Airline* line,int num);

//PRE: airport array is initialized
//POST: returns true if an airport with this code already exists and false otherwise
bool airportMade(Airport* allAirports[], char code[]);

//PRE: airline array is initialized
//POST: returns true if an airline with this code already exists and false otherwise
bool airlineMade(Airline* allAirlines[], char code[]);

//PRE: the code is defined and allAirports are defined and final airport is null
//POST: a reference to the airport with the matching code is made
Airport* findAirport(Airport* allAirports[], char code[]);

//PRE: the code is defined and allAirlines are defined and final airline is null
//POST: a reference to the airline with the matching code is made
Airline* findAirline(Airline* allAirlines[], char code[]);

#endif
