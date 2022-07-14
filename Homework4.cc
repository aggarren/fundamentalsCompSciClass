#include <iostream>
using namespace std;
#include "compute.h"

//PRE: IS is the number to be stored
//POST OS is the number
int readNumber() {
  int num;
  cin >> num;
  return num;
}

//PRE: IS are the characters to be stored and the parameters are the array and size 
//POST: function amends the array to include the inputted characters
void readNumbers(char array[], int size) {
  for(int index=0; (index<size); index++) {
      cin >> array[index];
    }
}

//PRE: IS includes the base and power
//POST: OS includes the base to the power of the exponent
int pow(int base, int exponent) {
  int answer = 1;//stores the answer to the problem
  for(int mult=0; (mult<exponent); mult++) {
    answer *= base; //multiplies the base by itself exponent times
  }
  return answer;
}

//PRE: array and length are parameters
//POST: the array is filled with zeros
void fillNum(int array[], int length, int num) {
  for(int index = 0; (index<length); index++) {
    array[index] = num;
  }
}

//PRE: IS includes the number of operators in the equation, the number of digits the numbers have,
//the operators, the result of the equations, and the number of equations
//POST: OS is the possible desired combinations of equations equal to the answer using the desired operators and digits
int main () {
  char * operatorArray = NULL; //array of unknown length holds the operators
  int * numbers = NULL;//array of unknown length holds the numbers
  int opLen = readNumber();//user inputs number of operators
  operatorArray = new char[opLen];//operators is set to the length entered by the user
  numbers = new int[opLen+1];//numbers is set to the length of the operator array plus 1
  fillNum(numbers,opLen+1,0); //fills the number array with zeros
  int opDigits = readNumber();//user inputs number of digits
  readNumbers(operatorArray,opLen);//user inputs the operators to be used
  int result = readNumber();//user inputs answer to equation
  int numEquations = readNumber();//user inputs how many equations
  int upperbound = pow(10,opDigits); //sets the upperbound for the numbers in the array ie 100 for 2 digits
  compute(operatorArray,numbers,opLen+1,result,upperbound,numEquations);//call the computing function that goes through the numbers and prints the equations
  return (0);
}
