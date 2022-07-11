#ifndef INCLUDED_FLIGHT
#define INCLUDED_FLIGHT
#include "Airport.h"
#include "Airline.h"
#include "constants.h"
//CI: from and to are airports, airline is an airline
//cost is >= 0; stops >= 0
//isNull is true if Airport from isNull and false otherwise
class Airport;
class Airline;
class Flight {
 private:
  Airport* from;//the airport this flight departs from
  Airport* to;//the airport this flight lands at
  Airline* airline;//the airline that supports this flight
  int cost;//how much this flight costs
  int stops;//how many stops before the final destination
  bool isNull; //denotes if this is null
 public:
  //PRE:
  //POST:flight object is created where from, to, and airline are null and the cost is 0
  Flight();

  //PRE: pFlight is a flight object that meets CI
  //POST: this object is a deep copy of pFlight
  Flight(const Flight* pFlight);

  //PRE:the implicit and explicit parameters are flights
  //POST: the implicit is a copy of the explicit
  Flight& operator=(const Flight& pFlight);
  
  //PRE: implicit and explicit parameters are both Flights
  //POST: returns true if flights are identical
  bool compare(Flight* pFlight);

  //PRE: this is a flight object
  //POST: isNull is returned
  bool getisNull();
  
  //PRE: this object meets CI
  //POST: the number of stops are returned
  int getStops();
  
  //PRE: this object meets CI
  //POST: the number of stops is set to x
  void setStops(int x);
  
  //PRE:this object meets CI
  //POST: the cost is returned
  int getCost();

  //PRE: this object meets CI
  //POST: the airport reference for from is returned
  Airport* getFrom();

  //PRE: this object meets CI
  //POST: the airport reference for from is returned
  Airport* getTo();

  //PRE: this object meets CI
  //POST: the airline reference is returned
  Airline* getAirline();

  //PRE:this object meets CI
  //POST:the cost is set to pCost
  void setCost(int pCost);

  //PRE:this object meets CI
  //POST: from is set to fromAirport
  void setFrom(Airport* fromAirport);

  //PRE:this object meets CI
  //POST: to is set to toAirport
  void setTo(Airport* toAirport);

  //PRE: this object meets CI
  //POST: airline is set to line
  void setAirline(Airline* line);
};
#endif
               
