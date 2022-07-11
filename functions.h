#ifndef INCLUDED_FUNCTIONS
#define INCLUDED_FUNCTIONS
#include "Airport.h"
#include "Flight.h"
#include "Airline.h"
#include "constants.h"

//PRE: allAirports array are defined and end in NULL; numAirports > 0
//POST: the arrays are in lexicographic order
void lexicographicPorts(Airport* allAirports[],int numAirports);


//PRE: allAirlines is defined and end in NULL; numAirlines >0
//POST: the array is in lexicographic order
void lexicographicLines(Airline* allAirlines[],int numAirlines);

//PRE:flights array ends in NULL
//POST:flights are ordered by the cost
void byCost(Flight* flights[]);

//PRE:source and destination are aiports that meet CI
//POST:returns the flight that takes to the destination from the source; returns null if none is found
Flight* existsFlightTo(Airport* source, Airport* destination);

//PRE:source and destination are aiports that meet CI; line is either null or an airline
//POST:returns the cheapest flight that takes to the destination from the source with the specified airline; returns null if none is found
Flight* existsFlightToRestricted(Airport* source, Airport* destination, Airline* line);

//PRE:matrix is defined with all costs to and from airports
//POST:matrix is amended incorporating floyd-warshall algorithm
void floydWarshall(int numAirports, Flight* ** matrix);

//PRE: flight is defined
//POST: a newflight is returned that is a copy of flight
Flight* copy(Flight* flight);

//PRE: allAirports is defined and numAirports is greater than 1, line is defined
//POST:a matrix of cheapest flight between two airports using line is returned
Flight*** makeMatrixRestrict(Flight* ** matrix, Airport* allAirports[], Airline* line, int numAirports);

//PRE: allAirports is defined and numAirports is greater than 1
//POST:a matrix of cheapest flight between two airports is returned
Flight*** makeMatrix(Flight* ** matrix, Airport* allAirports[], int numAirports);

//PRE: flight is a Flight and flights is an array of Flights 
//POST: flight is added to the end of flights 
void add(Flight* flight, Flight* flights[], int numFlights);

//PRE: allAirports is defined and ends in null, line is an airline, and numAirports is more than 0
//POST: flights are printed by source and if applicable, by airline
void getFlights(Airport* allAirports[], Airline* line, int numAirports);
#endif
