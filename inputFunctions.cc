#include <iostream>
using namespace std;
#include "inputFunctions.h"
#include "Airline.h"
#include "Airport.h"
#include "Flight.h"

//PRE: code ends in EOS and allAirlines ends in null
//POST:an airline object is constructed with data implemented
void makeAirline(Airline* allAirlines[], char inputCode[],int num){
  Airline* line;
  int indexCount = 0;//counts number of elements in pcode
    while(inputCode[indexCount] != EOS) {
      indexCount++;
    }
  line = new Airline(indexCount+1);
  line->setCode(inputCode);
  int index = 0;//goes through allAirlines
  if(num>0) {//there are airports
    while(!allAirlines[index]->getisNull()) {//goes until null
      index++;
    }
  }
  //ASSERT: index is at the last element of the array
  Airline* * newAllAirlines;
  newAllAirlines = new Airline*[index+2];
  int indexAir = 0;
  if(num>0) {//there are airports
    while(!allAirlines[indexAir]->getisNull()) {//goes until null
      newAllAirlines[indexAir] = allAirlines[indexAir];//copes into new array
      indexAir++;
    }
  }
  
  newAllAirlines[index] = line; //adds line to the array
  Airline* newline; //null airport
  newAllAirlines[index+1] = newline;//array ends in null
  allAirlines = newAllAirlines;
}

//PRE: inputCode ends in EOS and allAirports ends in null
//POST:an airport object is constructed with the data implemented
void makeAirport(Airport* allAirports[], char inputCode[], int num){
  Airport* port;
  int indexCount = 0;//counts number of elements in pcode
    while(inputCode[indexCount] != EOS) {
      indexCount++;
    }
  port = new Airport(indexCount+1);
  port->setCode(inputCode);
  int index = 0;//goes through allAirlines
  if(num>0) {//there are airports
    while(!allAirports[index]->getisNull()) {//goes until null
      index++;
    }
  }
  //ASSERT: index is at the last element of the array
  Airport* * newAllAirports;
  newAllAirports = new Airport*[index+2];

  if(num>0) {//there are airports
    int indexAir = 0;
    while(!allAirports[indexAir]->getisNull()) {//goes until null
      newAllAirports[indexAir] = allAirports[indexAir];//copes into new array
      indexAir++;
    }
  }
  
  newAllAirports[index] = port; //adds line to the array
  Airport* newport; //null airport
  newAllAirports[index+1] = newport;//array ends in null
  allAirports = newAllAirports;
}

//PRE: from and to are Airports following CI, cost is greater than 0, allFlights ends in null
//POST: a flight object is constructed with the data implemented; reference to flight is returned
Flight* makeFlight(Flight* allFlights[], int pCost, Airport* fromAir, Airport* toAir, Airline* line,int num){
  cout<<"MAKING FLIGHT"<< endl;
  Flight* flight;//makes a new flight
  cout << "pCost: " << pCost << endl;
  flight->setCost(pCost);//adds the cost
  cout << "set cost" << endl;
  flight->setFrom(fromAir);//adds the from airport
  flight->setTo(toAir);//adds the to airport
  flight->setAirline(line);//adds the airline

  int index=0; //goes through allFlights
  if(num>0) {//there are flights
    while(!allFlights[index]->getisNull()) {//goes until null
      index++;
    }
  }
  //ASSERT: index is at the last element of the array
  Flight* * newAllFlights;
  newAllFlights = new Flight*[index+2];

  newAllFlights[index] = flight; //adds line to the array
  Flight* newflight; //null airline
  newAllFlights[index+1] = newflight;//array ends in null
  allFlights = newAllFlights;
  return flight;
}

//PRE: airport array is initialized
//POST: returns true if an airport with this code already exists and false otherwise
bool airportMade(Airport* allAirports[], char code[]){
  bool answer = false; //assume this airport has not been made
  int index = 0; //indexes through allAirports
  while(!allAirports[index]->getisNull() && !answer) {
    if(allAirports[index]->compareCodes(code)) {//this airport's code equals the code we are looking for
      answer = true;
    }
    index++;
  }
  cout << "exiting airport made" << endl;
  return answer;
}

//PRE: airline array is initialized
//POST: returns true if an airline with this code already exists and false otherwise
bool airlineMade(Airline* allAirlines[], char code[]){
  bool answer = false; //assume this airline has not been made
  int index = 0; //indexes through allAirline
  while(!allAirlines[index]->getisNull() && !answer) {
    if(allAirlines[index]->compareCodes(code)) {//this airline's code equals the code we are looking for
      answer = true;
    }
    index++;
  }
  return answer;
}

//PRE: the code is defined and allAirports are defined and final airport is null
//POST: a reference to the airport with the matching code is made
Airport* findAirport(Airport* allAirports[], char code[]){
  cout<<"FINDING AIRPORT"<<endl;
  Airport* port;
  bool done = false;
  int index = 0; //indexes through allAirports
  while(!allAirports[index]->getisNull() && !done) {
    cout << "code: " << code << endl;
    if(allAirports[index]->compareCodes(code)) {//this airport's code equals the code we are looking for
      port = allAirports[index];
      done = true;
      index++;
    }
  }
  return port;
}

//PRE: the code is defined and allAirlines are defined and final airline is null
//POST: a reference to the airline with the matching code is made
Airline* findAirline(Airline* allAirlines[], char code[]){
  cout<<"FINDING AIRLINE"<<endl;
  Airline* line;
  bool done = false;
  int index = 0; //indexes through allAirline
  while(!allAirlines[index]->getisNull() && !done) {
    if(allAirlines[index]->compareCodes(code)) {//this airline's code equals the code we are looking for
      line = allAirlines[index];
      done = true;
      index++;
    }
  }
  return line;
}
