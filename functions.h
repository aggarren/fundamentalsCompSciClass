#ifndef INCLUDED_FUNCTIONS
#define INCLUDED_FUNCTIONS
#include "Simulator.h"
#include "Teller.h"
//PRE:teller array is defined with noTellers
//POST: returns true if all queues are empty and false otherwise
bool allEmpty(Teller* * tellers, int noTellers);

//PRE:teller array is defined with noTellers
//POST: returns the average of all queue lengths
int allLen(Teller* * tellers, int noTellers);

//PRE:tellers array is defined with noTellers
//POST: returns the Teller with the shortest queue
Teller* shortestQueue(Teller* * tellers, int noTellers);

//PRE: base and power are defined
//POST: base to the powerth power is returned
int pow(int base, int power);


//PRE: integer is an int
//POST: integer is converted into the char equivalent
char intToStr(int integer);

//PRE:str is a char array
//POST:str is converted into the integer equivalent
int strToInt(char * str);

//PRE: filename is defined
//POST: pSim is populated with data from file is error is false
void populateSim(char * data, Simulator& pSim, bool error);

//PRE: argc defined, argv[0]...arg[argc+1]
//POST: error True iff arguments false
//if any correct, pSim populated
void prepareSim(int argc, char * argv[], bool& error, Simulator &Sim);
#endif
