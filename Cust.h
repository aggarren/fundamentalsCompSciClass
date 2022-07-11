#ifndef INCLUDED_CUST
#define INCLUDED_CUST
#include <iostream>
using namespace std;
class Cust {
 private:
  int arrivalTime;
  int serviceTime;
  int servedTime;
public:
  Cust() { };
  
  //PRE: pCust is a Cust and CI is met
  //POST: this object is a deep copy of pCust
  Cust(const Cust& pCust) { arrivalTime = pCust.arrivalTime; serviceTime = pCust.serviceTime; servedTime = pCust.servedTime;};
  
  //PRE: the implicit and explicit parameters are Custs
  //POST: returns true if parameters are equivalent and false otherwise
  bool operator==(const Cust* pCust){ bool answer = true; if(arrivalTime != pCust->arrivalTime || serviceTime != pCust->serviceTime) { answer = false; } return answer;};
  
  void setArrival(int arrival){ arrivalTime = arrival; };
  void setService(int service){ serviceTime = service; };
  void setServed(int served){ servedTime = served; }
  int getArrival() { return arrivalTime; };
  int getService() { return serviceTime; };
  int getServed() { return servedTime; };
  ~Cust();
};
#endif
