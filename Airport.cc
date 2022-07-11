#include "Airport.h"
#include "Airline.h"
#include "Flight.h"
#include "constants.h"
#include <iostream>
using namespace std;
//PRE:
//POST: airport code is set to EOS and numFlights is set to 0
Airport::Airport(){
  flights = new Flight*[1];
  code = new char[1];
  code[0] = EOS;
  numFlights = 0; //we have 0 flights
  isNull = true;
}

//PRE:
//POST: airport code is set to length of int len
Airport::Airport(int len) {
  flights = new Flight*[1];
  code = new char[len];
  numFlights = 0; //we have 0 flights
  isNull = true;
}

//PRE: pAirport is an Airport and CI is met
//POST: this object is a deep copy of pAirport
Airport::Airport(const Airport& pAirport){
  numFlights = pAirport.numFlights;//copy numFlights
  isNull = pAirport.isNull; //copy isNull
  int indexFlight = 0;//index through flights
  while(indexFlight<numFlights) {//goes through all flights
    flights[indexFlight] = pAirport.flights[indexFlight];//copies this Flight
    indexFlight++;
  }
  int indexCode = 0;//index through code
  while(pAirport.code[indexCode] != EOS) {//goes through all chars
    code[indexCode] = pAirport.code[indexCode];//copies char
    indexCode++;
  }
  code[indexCode] = EOS;//code ends in EOS
}

//PRE:the implicit and explicit parameters are airports
//POST: the implicit is a copy of the explicit
Airport& Airport::operator=(const Airport& pAirport) {
  numFlights = pAirport.numFlights;//copies numFlights
  isNull = pAirport.isNull; //copies isNull
  int index = 0;
  while(pAirport.code[index] != EOS) {//copies codes
    code[index] = pAirport.code[index];
    index++;
  }
  return *this;
}

//PRE:implicit and explicit parameters are airports
//POST: returns true if they are identical
bool Airport::compare(Airport* pAirport)const{
  bool answer = true; //assume airports are identical
  if(numFlights != pAirport->numFlights || isNull != pAirport->isNull) {//number of flights not identical
    answer = false;
  }
  int index=0;
  while(code[index] != EOS && code[index] != EOS) {//both codes are not done
    if(code[index] != pAirport->code[index]) {//these characters are not identical
      answer = false;
    }
    if(code[index+1] == EOS && pAirport->code[index+1] != EOS) {//do not end at same time
      answer = false;
    }
    if(code[index+1] != EOS && pAirport->code[index+1] == EOS) {//do not end at same time
      answer = false;
    }
    index++;
  }
  return answer;
}

  
//PRE: this is an object
//POST: returns isNull
bool Airport::getisNull(){
  return isNull;
}

//PRE:this Aiprot meets CI and codeArray ends in EOS
//POST: returns true if codes match and false otherwise
bool Airport::compareCodes(char codeArray[])const {
  cout << "Comparing codes" << endl;
  bool answer = true;//assume match
  int index = 0;
  cout << "got here " << endl;
  while((codeArray[index] != EOS) && (code[index] != EOS) && answer) {//neither string has ended and answer has not changed
    cout << "got here" << endl;
    if(codeArray[index] != code[index]) {//this char doesn't match
      answer = false;
    }
    if(codeArray[index+1] == EOS && code[index+1] != EOS) {//one ends before the other
      answer = false;
    }
    if(codeArray[index+1] != EOS && code[index+1] == EOS) {//one ends before the other
      answer = false;
    }
    index++;
  }
  cout << "Exiting comparing codes" << endl;
  return answer;
}

//PRE: this Airport meets CI
//POST: the reference to the char array for code is returned
char* Airport::getCode(){
  return code;
}

//PRE: code's length is pcode's length
//POST: the char array for code is made of the input and ends in EOS
void Airport::setCode(char pcode[]){
  int indexCode = 0;//index through code
  while(pcode[indexCode] != EOS) {//goes through all chars
    code[indexCode] = pcode[indexCode];//copies char
    indexCode++;
  }
  code[indexCode] = EOS;//code ends in EOS
  isNull = false;
  cout << "code is set" << code << endl;
}

//PRE: the Airport meets CI
//POST: num is set as numFlights for this object
void Airport::setNum(int num){
  numFlights = num;
}

//PRE: the Airport meets CI
//POST: numFlights int is returned
int Airport::getNum(){
  return numFlights;
}

//PRE: the Airport meets CI
//POST: this flight is added to the array of flights and numFlights is updated
void Airport::addFlight(Flight* flight) {
  Flight* * newFlights; //new array for flights
  newFlights = new Flight*[numFlights+2];
  int index = 0;
  while(index<numFlights) {//copies elements of flights into newFlights
    newFlights[index] = flights[index];
    index++;
  }
  flights = newFlights;//reassign pointer
  
  flights[numFlights] = flight;//add flight
  Flight * null;
  flights[numFlights+1] = null;//add null flight
  numFlights++;//increase number of flights
}

//PRE: the Airport meets CI
//POST: the reference to the Flight array for flights is returned
Flight** Airport::getFlights(){
  return flights;
}

//PRE: the Airport meets CI
//POST: all flights to this airport are returned
Flight* Airport::getFlightTo(Airport* airport){
  Flight * listOfFlights;//list of flights to be returned
  listOfFlights = new Flight[0];//sets length to 0
  int numOfFlights = 0;//sets number in array to 0
  int indexFlights = 0;//indexes through flights
  while(indexFlights < numFlights) {//goes through all flights from this airport
    if(flights[indexFlights]->getTo()->getCode() == airport->getCode()) {//this flight's to matches the desired airport's code
      listOfFlights[numOfFlights] = flights[indexFlights];//add this flight to the list
      numOfFlights++;//increase number of flights in this list
    }
  }
  return listOfFlights;
}
