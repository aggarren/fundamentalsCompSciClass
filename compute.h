#ifndef INCLUDED_compute
#define INCLUDED_compute
#define INCLUDED_makeOperators


//PRE: the operators, array, the result, and length of the operators are defined
//POST: returns true if they equal the result
bool check(char operators[], int array[], int numOp, int result);

//PRE: parameters include the operator and number arrays, its length, its upperbound, the index we are working on, and the result
//POST: the number array is amended to have a new combination of numbers, returns true if we found an equation and false if we haven't
bool find(char operators[], int array[],int numLen, int upperbound, int currIndex, int result);


//PRE: IS includes the operators, number array,the number of numbers, the result, and the number of equations desired
//POST: the equation is print by calling the printEquation function and will print a statement if not enough equations are found
void compute(char operators[], int array[], int numLen, int result, int upperbound);
  
#endif
                                          CPSC170/Homework/aggarren-Homework5/printEquation.cc                                                0000640 0014416 0014416 00000001271 14207222666 022616  0                                                                                                    ustar   aggarren                        aggarren                                                                                                                                                                                                               #include <iostream>
using namespace std;
//PRE: IS includes the operators and the numbers that satisfy the equation and the result
//POST: OS prints the equation using the operators, numbers, and result correctly
void printEquation(char operators[], int numberArray[], int result, int maxOp) {
  cout<<numberArray[0] << " ";
  for(int index = 0; (index<maxOp); index++) {
    char currOperator = operators[index]; //char stores the operator currently being used
    int currNum = numberArray[index+1]; //int stores the number currently being used
    cout << currOperator << " " << currNum << " ";
  }
    cout<< " = "; //prints the = sign
    cout <<  result << " " << endl;//prints the result
}
                  
