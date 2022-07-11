#include "Flight.h"
#include "Airport.h"
#include "Airline.h"
#include "constants.h"
//PRE:
//POST:flight object is created where the cost and stops are 0 and isNull is true
Flight::Flight(){
  from = new Airport();
  to = new Airport();
  airline = new Airline();
  cost = 0;
  stops = 0;
  isNull = true;
}

//PRE: pFlight is a flight object that meets CI
//POST: this object is a deep copy of pFlight
Flight::Flight(const Flight* pFlight){
  from = pFlight->from;
  to = pFlight->to;
  cost = pFlight->cost;
  stops = pFlight->stops;
  airline = pFlight->airline;
  isNull = pFlight->isNull;
}
//PRE:the implicit and explicit parameters are flights
//POST: the implicit is a copy of the explicit
Flight& Flight::operator=(const Flight& pFlight){
  from = pFlight.from;
  to = pFlight.to;
  airline = pFlight.airline;
  cost = pFlight.cost;
  stops = pFlight.stops;
  isNull = pFlight.isNull;
  return *this;
}

//PRE: implicit and explicit parameters are both Flights
//POST: returns true if flights are identical
bool Flight::compare(Flight* pFlight) {
  bool answer = true; //assume identical
  if(!from->compare(pFlight->from)) {//froms are not the same
    answer = false;
  }
  if(!to->compare(pFlight->to)) {//froms are not the same
    answer = false;
  }
  if(!airline->compare(pFlight->airline)) {//airlines are not the same
    answer = false;
  }
  if(cost != pFlight->cost) {//costs are not the same
    answer = false;
  }
  if(stops != pFlight->stops) {//stops are not the same
    answer = false;
  }
  if(isNull != pFlight->isNull) {
    answer = false;
  }
  return answer;
}


//PRE: this is a flight object
//POST: isNull is returned
bool Flight::getisNull(){
  return isNull;
}

//PRE: this object meets CI
//POST: the number of stops are returned
int Flight::getStops(){
  return stops;
}

//PRE: this object meets CI
//POST: the number of stops is set to x
void Flight::setStops(int x) {
  stops = x;
}

//PRE:this object meets CI
//POST: the cost is returned
int Flight::getCost(){
  return cost;
}

//PRE: this object meets CI
//POST: the airport reference for from is returned
Airport* Flight::getFrom(){
  return from;
}

//PRE: this object meets CI
//POST: the airport reference for from is returned
Airport* Flight::getTo() {
  return to;
}

//PRE: this object meets CI
//POST: the airline reference is returned
Airline* Flight::getAirline(){
  return airline;
}

//PRE:this object meets CI
//POST:the cost is set to pCost
void Flight::setCost(int pCost){
  cost = pCost;
}

//PRE:this object meets CI
//POST: from is set to fromAirport
void Flight::setFrom(Airport* fromAirport){
  isNull = false;
  from = fromAirport;
}

//PRE:this object meets CI
//POST: to is set to toAirport
void Flight::setTo(Airport* toAirport){
  to = toAirport;
}

//PRE: this object meets CI
//POST: airline is set to line
void Flight::setAirline(Airline* line){
  airline = line;
}
                    
