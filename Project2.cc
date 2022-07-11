#include <iostream>
using namespace std;
#include "Airport.h"
#include "Flight.h"
#include "Airline.h"
#include "constants.h"
#include "inputFunctions.h"
#include "functions.h"
//PRE:code ends in EOS
//POST:character is added to code
void add(char code[], char ch) {
  int index = 0;
  while(code[index] != EOS){
    index++;
  }
  char * newCode;
  newCode = new char[index+2];//temp char array with index +2 size

  int indexCopy=0;
  while(indexCopy < index) {//copy elements from code to newCode
    newCode[indexCopy] = code[indexCopy];
    indexCopy++;
  }
  newCode = code;
  //ASSERT: index is the end of code
  code[index] = ch;//add ch to code
  code[index+1] = EOS;//ends in EOS 
}

//PRE: code is defined with EOS ending it
//POST: the input is code
void inputCode(char code[]) {
  bool done = false; //ends loop
  int index = 0;//indexes through codeFrom
  while(!done) {//goes until we are done
    char character = cin.get();
    if(character == SPACE) {//we are done
      done = true;
    }
    else {//we are not done
      add(code,character);//adds input to array
      index++;
    }
  }  code[index] = EOS; //ends array in EOS
}


//PRE:allFlights, allAirports, allAirlines are defined and end in NULL
//POST:new flights, airlines, and airports are created based on user input, pre conditions persist; number of aiports and airlines are returned
int* input(Flight* allFlights[], Airport* allAirports[], Airline* allAirlines[], int nums[]) {
  char * codeFrom;//array for the code for from
  codeFrom = new char[1];
  codeFrom[0] = EOS;
  inputCode(codeFrom);//inputs code for from
  char * codeTo; //array for the code for to
  codeTo = new char[1];
  codeTo[0] = EOS;
  inputCode(codeTo);//inputs code for to
  char * codeAirline;//array for the code for the airline
  codeAirline = new char[1];
  codeAirline[0] = EOS;
  inputCode(codeAirline);//inputs code for airline
  int cost;
  cin >> cost;//inputs cost
    if(nums[0] > 0) { //there are airports
    if(!airportMade(allAirports,codeFrom)){//the from airport has not been made
      makeAirport(allAirports,codeFrom,nums[0]); //make this airport
      nums[0]++;//increase count of number of airports
    }
    cout<<"MADE FROM AIRPORT"<<endl;
    if(!airportMade(allAirports,codeTo)){//the to airport has not been made
      makeAirport(allAirports,codeTo,nums[0]);//make this airport
      nums[0]++; //increase count of number of airports
    }
  }
  else {//there are not airports
    cout<<"MADE AIRPORTS"<<endl;
    makeAirport(allAirports,codeFrom,nums[0]); //make this airport
    makeAirport(allAirports,codeTo,nums[0]);//make this airport
    nums[0] = nums[0] + 2;//increase number of airports by 2
  }
  cout<<"MADE TO AIRPORT"<<endl;
  if(nums[1]>0) {//there are airlines
    if(!airlineMade(allAirlines,codeAirline)) {//this airline has not been made
      makeAirline(allAirlines,codeAirline,nums[1]);//make this airline
      nums[1]++; //increase count of number of airlines
    }
  }
  else {//there are not airlines
    cout<<"MADE Airlines"<<endl;
    makeAirline(allAirlines,codeAirline,nums[1]);//make this airline
    nums[1]++; //increase count of number of airlines
  }
  Airport* From = findAirport(allAirports, codeFrom);//finds the from airport for this code
  Airport* To = findAirport(allAirports, codeTo);//finds the to airport for this code
  Airline* Line = findAirline(allAirlines, codeAirline);//finds the airline for this code
  Flight* Flight = makeFlight(allFlights,cost,From,To,Line,nums[2]);//makes a flight for this input
  nums[2]++;//increment number of flights
  From->addFlight(Flight); //adds this flight to the from airport
  Line->addFlight(Flight); //adds this flight to the airline
  return nums;
}


int main () {
  Flight* * allFlights;//an array to store all flights inputted
  allFlights = new Flight*[1];//sets size of allFlights
  Flight* newflight; //null flight
  allFlights[0] = newflight; //add null flight to end
  Airport* * allAirports;//an array to store all airports inputted
  allAirports = new Airport*[1];//sets size of allAirports
  Airport* newairport; //null airport
  allAirports[0] = newairport;//add null airport to end
  Airline* * allAirlines;//an array to store all airlines inputted
  allAirlines = new Airline*[1];//sets size of allAirlines
  Airline* newairline; //null airline
  allAirlines[0] = newairline; //add null airline to end
  int * nums;
  nums = new int[3]; //element 0 is numAirports and element 1 is numAirlines and element 2 is numFlights
  nums[0] = 0;//numAirports is 0
  nums[1] = 0;//numAirlines is 0
  nums[2] = 0;//numFlights is 0
  char endOfLine;
  while(!cin.eof()) {//until we have reached the end of the file
    nums = input(allFlights,allAirports,allAirlines,nums);//take in IS and add flight to allFlights, adds to number of airports and airlines
    cin >> endOfLine;
  }
  //ASSERT:there are at least 2 airports and at least 1 airline and at least 1 flight
  
  lexicographicPorts(allAirports,nums[0]);//puts array in lexicographic order
  lexicographicLines(allAirlines,nums[1]);//puts array in lexicographic order

  Airline* line; //null airline object for use in getFlights
  getFlights(allAirports,line,nums[0]);//print all flights to and from all airports
  cout << "Airline Specific: " << endl;
  cout << "==================" << endl;
  
  int indexAirline = 0;//cycles through all airlines
  while(indexAirline < nums[1]) {//goes through all airlines
    cout << allAirlines[indexAirline]->getCode() << endl;//print
    getFlights(allAirports,allAirlines[indexAirline],nums[0]);//prints all flights for this airline
    indexAirline++;
  }
  return (0);
}
