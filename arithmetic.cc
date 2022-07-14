#include "arithmetic.h"
#define plus '+'
#define minus '-'
#define multiply '*'
//PRE: parameters include the operators, an array to store the appropriate number of integares, and the length of the operator array
//POST: function will compute the output 
int arithmetic(char operators[], int numArray[], int maxOp) {
  int answer = numArray[0];//answer starts as first number because we are building
  for(int index = 0; (index<maxOp); index++) {
    char currOperator = operators[index]; //char stores the operator currently being used
    int currNum = numArray[index+1]; //int stores the number currently being used
    if(currOperator == plus) {
      answer += currNum;
    }
    if(currOperator == minus) {
      answer -= currNum;
    }
    if(currOperator == multiply) {
      answer *= currNum;
    }
  }
  return answer;
}
