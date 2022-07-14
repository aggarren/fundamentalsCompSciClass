#include <iostream>
using namespace std;
#include "makeOperators.h"
#include "numberFunctions.h"

//PRE: IS includes the number of operators in the equation, the number of digits the numbers have,
//the operators, the result of the equations, and the number of equations
//POST: OS is the possible desired combinations of equations equal to the answer using the desired operators and digits
int main () {
  char * operatorArray = NULL; //array of unknown length holds the operators
  int * numbers = NULL;//array of unknown length holds the numbers
  int opLen = readNumber();//user inputs number of operators
  operatorArray = new char[opLen];//operators is set to the length entered by the user
  numbers = new int[opLen+1];//numbers is set to the length of the operator array plus 1
  int opDigits = readNumber();//user inputs number of digits
  int result = readNumber();//user inputs answer to equation
  int numEquations = 1;//we need to output one equation
  int upperbound = pow(10,opDigits); //sets the upperbound for the numbers in the array ie 100 for 2 digits
  int currIndex = opLen-1; //sets the current index for the makeOperators function
  makeOperators(operatorArray,opLen,currIndex,numbers,result,upperbound); //gets the operators and prints an equation when it does   
  delete [] operatorArray;
  delete [] numbers;
  return (0);
}
