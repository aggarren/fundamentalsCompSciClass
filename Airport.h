#ifndef INCLUDED_AIRPORT
#define INCLUDED_AIRPORT
#include "Flight.h"
#include "constants.h"
//CI: numFlights is the number of Flight objects in flights
//isNull is true if code is empty and false if contains chars
//code ends in EOS, flights ends in a Flight with isNull = true
class Flight;
class Airport {
 private:
  char * code;
  Flight* * flights;//holds the flights where this airport is the from
  int numFlights;
  bool isNull;
 public:
  //PRE:
  //POST: airport code is set to EOS and numFlights is set to 0
  Airport();

  //PRE:
  //POST: airport code is set to length of int len
  Airport(int len);

  //PRE: pAirport is an Airport and CI is met
  //POST: this object is a deep copy of pAirport
  Airport(const Airport& pAirport);

  //PRE:the implicit and explicit parameters are airports
  //POST: the implicit is a copy of the explicit
  Airport& operator=(const Airport& pAirport);
  
  //PRE:implicit and explicit parameters are airports
  //POST: returns true if they are identical
  bool compare(Airport* pAirport)const;
  
  //PRE: this is an object
  //POST: returns isNull
  bool getisNull();

  //PRE:this Aiprot meets CI and codeArray ends in EOS
  //POST: returns true if codes match and false otherwise
  bool compareCodes(char codeArray[])const;
  
  //PRE: this Airport meets CI
  //POST: the reference to the char array for code is returned
  char* getCode();

  //PRE: the char array for code has EOS
  //POST: the char array for code is made of the input and ends in EOS
  void setCode(char pcode[]);

  //PRE: the Airport meets CI
  //POST: num is set as numFlights for this object
  void setNum(int num);

  //PRE: the Airport meets CI
  //POST: numFlights int is returned
  int getNum();

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
               
