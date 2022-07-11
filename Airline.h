#ifndef INCLUDED_AIRLINE
#define INCLUDED_AIRLINE
#include "constants.h"
#include "Flight.h"
#include "Airport.h"
//CI:isNull is true if code is empty and false if contains chars
//code ends in EOS
class Flight;
class Airport;
class Airline {
 private:
  char * code;//holds the chars for the code
  Flight* * flights;
  int numFlights;
  bool isNull; //denotes if this is a null object
 public:
  //PRE:
  //POST:flights and airports are empty and numFlights and numAirports are 0
  Airline();

  //PRE:
  //POST: airline code is set to length of int len
  Airline(int len);
  
  //PRE: pAirline meets CI for Airline
  //POST: this object is a deep copy of pAirline
  Airline(const Airline& pAirline);

  //PRE:the implicit and explicit parameters are airlines
  //POST: the implicit is a copy of the explicit
  Airline& operator=(const Airline& pAirline);
  
  //PRE: implicit and explicit parameters are airlines
  //POST: returns true if airlines are identical
  bool compare(Airline* pAirline)const;

  //PRE: this is an object of Airline
  //POST: isNull is returned
  bool getisNull();


  //PRE:this Aiprot meets CI and codeArray ends in EOS
  //POST: returns true if codes match and false otherwise
  bool compareCodes(char codeArray[])const;
  
  //PRE: pCode ends in EOS and airline meets CI
  //POST: the code for this airline is pCode
  void setCode(char pCode[]);

  //PRE: airline meets CI
  //POST: the reference to the char array code is returned
  char* getCode();

  //PRE: the Airport meets CI
  //POST: this flight is added to the array of flights and numFlights is updated
  void addFlight(Flight* flight);

  //PRE: the Airport meets CI
  //POST: the reference to the Flight array for flights is returned
  Flight** getFlights();

  //PRE: the Airport meets CI
  //POST: a Flight reference is returned where to is airport
  Flight* getFlightTo(Airport* airport);
  
};
#endif
          
