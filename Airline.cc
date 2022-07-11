#include "Airline.h"
#include "Airport.h"
#include "Flight.h"

//PRE:
//POST:flights and airports are empty and numFlights and numAirports are 0
Airline::Airline(){
  flights = new Flight*[1];
  code = new char[1];
  code[0] = EOS; //first element is EOS
  isNull = true;
  numFlights = 0;//we have 0 flights
}


//PRE:
//POST: airport code is set to length of int len
Airline::Airline(int len) {
  flights = new Flight*[1];
  code = new char[len];
  numFlights = 0; //we have 0 flights
  isNull = true;
}

//PRE: pAirline meets CI for Airline
//POST: this object is a deep copy of pAirline
Airline::Airline(const Airline& pAirline){
  numFlights = pAirline.numFlights;
  isNull = pAirline.isNull; //copying null
  int indexFlight = 0;//index through flights
  while(indexFlight<numFlights) {//goes through all flights
    flights[indexFlight] = pAirline.flights[indexFlight];//copies this Flight
    indexFlight++;
  }
  int indexCode = 0;//index through code
  while(pAirline.code[indexCode] != EOS) {//goes through all chars
    code[indexCode] = pAirline.code[indexCode];//copies char
    indexCode++;
  }
  code[indexCode] = EOS;//code ends in EOS
}


//PRE:the implicit and explicit parameters are airlines
//POST: the implicit is a copy of the explicit
Airline& Airline::operator=(const Airline& pAirline) {
  isNull = pAirline.isNull; //copying null
  numFlights = pAirline.numFlights;
  int indexCode = 0;
  while(pAirline.code[indexCode] != EOS) {//copy chars Ffrom code array
    code[indexCode] = pAirline.code[indexCode];
    indexCode++;
  }
  code[indexCode] = EOS; //ends code in EOS  
  int indexFlight = 0;//index through flights
  while(indexFlight<numFlights) {//goes through all flights
    flights[indexFlight] = pAirline.flights[indexFlight];//copies this Flight
    indexFlight++;
  }
  return *this;
}
  

//PRE: implicit and explicit parameters are airlines
//POST: returns true if airlines are identical
bool Airline::compare(Airline* pAirline)const{
  bool answer = true; //assume the airlines are identical
  int index = 0;
  while((code[index] != EOS) && (pAirline->code[index] != EOS)) {//goes until either end
    if(code[index] != pAirline->code[index]) {//the characters are not the same
      answer = false;
    }
    if(code[index+1] == EOS && pAirline->code[index+1] != EOS) {//this code ends the other doesn't
      answer = false;
    }
    if(code[index+1] != EOS && pAirline->code[index+1] == EOS) {//this code ends the other doesn't
      answer = false;
    }
    index++;
  }
  return answer;
}

//PRE: this is an object of Airline
//POST: isNull is returned
bool Airline::getisNull(){
  return isNull;
}


//PRE:this Aiprot meets CI and codeArray ends in EOS
//POST: returns true if codes match and false otherwise
bool Airline::compareCodes(char codeArray[])const {
  bool answer = true;//assume match
  int index = 0;
  while((codeArray[index] != EOS) && (code[index] != EOS) && answer) {//neither string has ended and answer has not changed
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
  return answer;
}

//PRE: pCode ends in EOS and airline meets CI
//POST: the code for this airline is pCode
void Airline::setCode(char pCode[]){
  int indexCount = 0;//counts number of elements in pcode
  while(pCode[indexCount] != EOS) {
    indexCount++;
  }
  char * temp;//new temporary code array
  temp = new char[indexCount];//length of number of elements in pcode
  code = temp;//code is now temp
 
  int index = 0;
  while(pCode[index] != EOS) {
    code[index] = pCode[index];
    index++;
  }
  code[index] = EOS;
  isNull = false;
}

//PRE: airline meets CI
//POST: the reference to the char array code is returned
char* Airline::getCode(){
  return code;
}
//PRE: the Airport meets CI
//POST: this flight is added to the array of flights and numFlights is updated
void Airline::addFlight(Flight* flight) {
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
  numFlights++;//increase number of flights flights[numFlights] = flight;

}

//PRE: the Airport meets CI
//POST: the reference to the Flight array for flights is returned
Flight** Airline::getFlights(){
  return flights;
}

//PRE: the Airport meets CI
//POST: all flights to this airport are returned
Flight* Airline::getFlightTo(Airport* airport){
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
                                                                                                                                       CPSC170/Projects/aggarren-Project2/test3                                                            0000664 0014416 0014416 00000000037 14224676630 020250  0                                                                                                    ustar   aggarren                        aggarren                                                                                                                                                                                                               IADX ROA UA 500
IADX IAD UA 100                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 CPSC170/Projects/aggarren-Project2/constants.h                                                      0000640 0014416 0014416 00000000162 14224143320 021422  0                                                                                                    ustar   aggarren                        aggarren                                                                                                                                                                                                               #ifndef INCLUDED_CONSTANTS
#define INCLUDED_CONSTANTS
#define EOS '\0'
#define EOL '\n'
#define SPACE ' '

#endif
                      
