#include "arithmetic.h"
#include "printEquation.h"
#include <iostream>
using namespace std;

//PRE: the operators, array, the result, and length of the operators are defined
//POST: returns true if they equal the result
bool check(char operators[], int array[], int numOp, int result) {
  bool correct = false; //assume that the array and operators do not produce the result
  if(arithmetic(operators, array, numOp) == result) { //the correct result is produced
    correct = true;//boolean returned is true
  }
  return correct;
}

//PRE: parameters include the operator and number arrays, its length, its upperbound, the index we are working on, and the result
//POST: the number array is amended to have a new combination of numbers, returns true if we found an equation and false if we haven't
bool find(char operators[], int array[],int numLen, int upperbound, int currIndex, int result) {
  bool found = false; //boolean is true if we have found numbers to satisfy the equation and false if not
  if(currIndex == -1) {//we have all filled
    found = check(operators,array,numLen-1,result);//check this combination
  }
  else{
    int currElement = 0; //we want our current element to start at 0
    while((currElement < upperbound) && !found) { //while we can increase the current index and have not found an equation
      array[currIndex] = currElement; //our current element increases by 1
      found = find(operators,array,numLen,upperbound,currIndex-1,result);//find at last index
      currElement = currElement + 1;
    }
  }
  return found;
}

//PRE: IS includes the operators, number array,the number of numbers, the result, and the number of equations desired
//POST: the equation is print by calling the printEquation function and will print a statement if not enough equations are found
void compute(char operators[], int array[], int numLen, int result, int upperbound) {
  int currIndex = numLen-1;//stores the current Index being worked on for find
  bool completed = find(operators,array, numLen, upperbound, currIndex, result); //goes through combinations: if returns true it found a combination that works
  if(!completed) {
    cout << "No possible equation" << endl;
  }
  else {
    printEquation(operators,array,result,numLen-1);//print equation if completed
  }
} 

