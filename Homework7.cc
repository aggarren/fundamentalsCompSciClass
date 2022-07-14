#include <iostream>
using namespace std;
#include "LinkedList.h"
#include "Node.h"
#include "Stack.h"
#define PLUS -1
#define MULT -2

int main () {
  Stack stack; //stack for the numbers
  int num = 0;//number that is inputted
  cin >> num;//gets first number
  while(!cin.eof()){//while not end of file
    int result = 0; //result of the operands and operator
    if(num != PLUS && num != MULT) {//this is an operand
      stack.push(num);//add the number to the stack
    }
    else {//this is an operator
      int operand1 = stack.top();//get the top int
      stack.pop();//pop operand1
      int operand2 = stack.top();//get the top int
      stack.pop();//pop operand2
      if(num == PLUS) {//operator is +
	result = operand1 + operand2;//performs operation
	stack.push(result);//put result on stack
      }
      else if(num == MULT) {//operators is *
	result = operand1 * operand2;//perform operation
	stack.push(result);//put result on stack
      }
    }
    cin >> num;
  }
  cout << stack.top() << endl; //prints the final result
  stack.pop(); //pops the final result off the stack
  return 0;
}
