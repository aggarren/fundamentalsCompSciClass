#include <iostream>
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
