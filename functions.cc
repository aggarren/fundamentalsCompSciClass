#include <iostream>
using namespace std;
#include "functions.h"
#include "Flight.h"
#include "Airport.h"
#include "Airline.h"
#include "constants.h"
#include "MergeSort.h"
//PRE: allAirports is defined and end in NULL
//POST: the array is in lexicographic order
void lexicographicPorts(Airport* allAirports[], int numAirports){
  sortPort(allAirports,0,numAirports);
}

//PRE: allAirports is defined and end in NULL
//POST: the array is in lexicographic order
void lexicographicLines(Airline* allAirlines[], int numAirlines){
  sortLine(allAirlines,0,numAirlines);
}

//PRE:flights array ends in NULL
//POST:flights are ordered by the cost using bubble sort
void byCost(Flight* flights[], int numFlights) {
  int k = 0;
  while(k < numFlights-1) {//goes from 0 up until last flight
    int j = k + 1;
    while(j<numFlights-k) {//goes from k+1 to numFlights-k
      if(flights[j]->getCost() > flights[k]->getCost()) {//flight j is more than flight k
	Flight* temp = flights[k];//stores flight k in a tempoarary flight
	flights[k] = flights[j];//flight k becomes flight j
	flights[j] = temp;//flight j becomes the original flight k
      }
      j++;
    }
    k++;
  }
}

//PRE:source and destination are aiports that meet CI; 
//POST:returns the cheapest flight that takes to the destination; returns null if none is found
Flight* existsFlightTo(Airport* source, Airport* destination){
  Flight* answer; //holds a reference to the found flight; its initial is NULL
  Flight* * flights;//creates a reference of an array of flights
  flights = source->getFlights();//assigns flights to the array of flights from this airport
  int index = 0;//indexes through flights
  while(!flights[index]->getisNull()) {//goes through all flights until end or until found
    if(destination->compare(flights[index]->getTo())) {//this flight's to equals the destination 
      if(answer->getisNull() || flights[index]->getCost() < answer->getCost()) {//answer is null or this flight is less than previous found flight
	answer = flights[index]; //stores this flight
      }
      
    }
  }
  return answer;
}

//PRE:source and destination are aiports that meet CI; line is either null or an airline
//POST:returns the cheapest flight that takes to the destination from the source with the specified airline; returns null if none is found
Flight* existsFlightToRestricted(Airport* source, Airport* destination, Airline* line){
 Flight* answer; //holds a reference to the found flight; its initial is NULL
  Flight* * flights;//creates a reference of an array of flights
  flights = line->getFlights();//assigns flights to the array of flights from this airport
  int index = 0;//indexes through flights
  while(!flights[index]->getisNull()) {//goes through all flights until end or until found
    if(source->compare(flights[index]->getFrom()) && destination->compare(flights[index]->getTo())) {//this flight's to equals the destination and source
      if(answer->getisNull() || flights[index]->getCost() < answer->getCost()) {//answer is null or this flight is less than previous found flight
	answer = flights[index]; //stores this flight
      }
      
    }
  }
  return answer;
}

//PRE:matrix is defined with all costs to and from airports
//POST:matrix is amended incorporating floyd-warshall algorithm
void floydWarshall(int numAirports, Flight* ** matrix) {
  bool done = false; //denotes when we've gone through a cycle without amendments
  while(!done) {
    done = true; //resets between cycles
    for(int k=0; k<numAirports; k++) {//intermediate airport
      for(int i=0; i<numAirports; i++){//from airport
	for(int j=0; j<numAirports; j++) {//to airport
	  if((i != k) && (k != j) && (i != j)) {
	    if(matrix[i][k]->getCost() + matrix[k][j]->getCost() < matrix[i][j]->getCost() || matrix[i][j]->getisNull()) {//this way is less than the current way or is the first way
	      matrix[i][j]->setCost(matrix[i][k]->getCost() + matrix[k][j]->getCost());//add the costs
	      matrix[i][j]->setStops(matrix[i][k]->getStops()+matrix[k][j]->getStops()+1); //add stops and increase stops by 1
	      done = false; //we made an amendment so we must cycle again
	    }
	  }
	}
      }
    }
  }
}

//PRE: flight is defined
//POST: a newflight is returned that is a copy of flight
Flight* copy(Flight* flight) {
  Flight* newFlight;
  newFlight = flight;
  return newFlight;
}

//PRE: allAirports is defined and numAirports is greater than 1, line is defined
//POST:a matrix of cheapest flight between two airports using line is returned
Flight*** makeMatrixRestrict(Flight* ** matrix, Airport* allAirports[], Airline* line, int numAirports) {
  int source =0;
  int dest = 0;
  while(source<numAirports) {
    while(dest<numAirports) {
      Flight* flight = existsFlightToRestricted(allAirports[source],allAirports[dest], line);
      flight = copy(flight);
      matrix[source][dest] = flight;//add to matrix
      dest++;
    }
    source++;
  }

  floydWarshall(numAirports, matrix);//find cheapest paths
  return matrix;
}

//PRE: allAirports is defined and numAirports is greater than 1
//POST:a matrix of cheapest flight between two airports is returned
Flight*** makeMatrix(Flight* ** matrix, Airport* allAirports[], int numAirports) {
  int source =0;
  int dest = 0;
  while(source<numAirports) {
    while(dest<numAirports) {
      Flight* flight = existsFlightTo(allAirports[source],allAirports[dest]);
      flight = copy(flight);
      matrix[source][dest] = flight;//add to matrix
      dest++;
    }
    source++;
  }

  floydWarshall(numAirports, matrix);//find cheapest paths
  return matrix;
}


//PRE: flight is a Flight and flights is an array of Flights
//POST: flight is added to the end of flights
void add(Flight* flight, Flight* flights[], int numFlights){
  Flight* * newFlights;//temporary Flight array
  newFlights = new Flight*[numFlights+2];//size is number of flights + 2

  int indexcopy=0;
  while(indexcopy < numFlights) {//copy flights into newFlights
    newFlights[indexcopy] = flights[indexcopy];
    indexcopy++;
  }
  flights = newFlights;//reassign pointer
  flights[numFlights] = flight;//adds flight to the end of flights
  Flight* null;
  flights[numFlights+1] = null;//adds null flight to end
}

//PRE: allAirports is defined and ends in null, line is an airline, and numAirports is more than 1
//POST: flights are printed by source and if applicable, by airline
void getFlights(Airport* allAirports[], Airline* line, int numAirports) {
  Flight* ** Matrix;
  Matrix = new Flight**[numAirports];
  if(!line->getisNull()) {//we have a specified airline
    makeMatrixRestrict(Matrix,allAirports,line,numAirports);//make a matrix of flights with only this airline
  }
  else {//we do not have a specified airline
    makeMatrix(Matrix,allAirports,numAirports);//make a matrix of flights
  }
  
  int sourceIndex = 0;
  while(sourceIndex<numAirports) {//goes through all airports as sources
    int destIndex = 0;
    Flight* * flights; //array of flights for this source
    int numFlights = 0; //tracks number of flights for this airport
    while(destIndex<numAirports) {//goes through all airports as destinations
      Flight* flight = Matrix[sourceIndex][destIndex]; //gets the cheapest flight for this combo
      add(flight,flights,numFlights); //adds this flight to the array
      numFlights++; //flight has been added
    }
    byCost(flights, numFlights);//order the flight array by cost
    
    cout << allAirports[sourceIndex]->getCode() << ": "; //prints the source aiport's code
    int indexPrint = 0;
    while(indexPrint < numFlights) {//goes through all flights for this airport
      if(flights[indexPrint]->getCost() > 0) {//this flight existed
	cout << flights[indexPrint]->getTo()->getCode(); //prints the destination
	cout << "(" << flights[indexPrint]->getCost() << "/" << flights[indexPrint]->getStops() << ")";
	if(indexPrint+1<numFlights) {//this is not the last flight
	  cout << ", ";
	}
      }
      indexPrint++;
    }
    cout << endl; //ends line
  }
}
                 
