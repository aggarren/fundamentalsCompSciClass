#include "makeOperators.h"
#include "compute.h"
#include <iostream>
using namespace std;
#define plus '+'
#define minus '-'
#define multiplication '*'
#define PLUS '0'
#define MINUS '1'
#define MULTIPLICATION '2'
//PRE: the operators array consists of 0, 1, and 2's
//POST: the operators array replaces 0's with pluses, 1's with minuses, and 2's with multiplication
void makeCharacters(char operators[], int maxOp) {
  for(int index=0; index<maxOp; index++) {
    if(operators[index] == PLUS) {
      operators[index] = plus;
    }
    else if(operators[index] == MINUS) {
      operators[index] = minus;
    }
    else if(operators[index] == MULTIPLICATION) {
      operators[index] = multiplication;
    }
  }
}

//PRE: parameters include the operators array, the length of the array, the index being worked on, the array for numbers, the result, and the upperbound
//POST: the array is filled with a new combination of operators and calls the compute function to print an equation
void makeOperators(char operators[], int maxOp, int currIndex, int numbers[], int result, int upperbound) {
  if(currIndex == -1) {//we have all filled
    makeCharacters(operators,maxOp);//turns 0,1,2's into plus,minus,multiplication
    cout << operators << " ";//prints out the current operators
    compute(operators,numbers,maxOp+1,result,upperbound);//call the computing function that goes through the numbers and prints the equations
  }
  else{
    char currElement = PLUS; //we want our current element to start at +
    while(currElement <= MULTIPLICATION) { //while we can increase the current index and have not found all operators
      operators[currIndex] = currElement; //our current element increases by 1
      makeOperators(operators,maxOp,currIndex-1,numbers,result,upperbound);//find at last index
      currElement = char(int(currElement+1));//we increase the element
    }
  }
}
         
