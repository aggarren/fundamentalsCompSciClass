#include <iostream>
using namespace std;
#include "numberFunctions.h"
//PRE: IS is the number to be stored
//POST OS is the number
int readNumber() {
  int num;
  cin >> num;
  return num;
}

//PRE: parameters include the base and power
//POST: outputs the base to the power of the exponent
int pow(int base, int exponent) {
  int answer = 1;//stores the answer to the problem
  for(int mult=0; (mult<exponent); mult++) {
    answer *= base; //multiplies the base by itself exponent times
  }
  return answer;
}
