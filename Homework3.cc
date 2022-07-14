#include <iostream>
using namespace std;
#define maxOp 2
#define maxNum 3 //should be maxOp + 1
#define upperbound 10 //should be ten if looking for single digits
#define plus '+'
#define minus '-'
#define multiply '*'
#define divide '/'
//the printEquation, arithmetic, fillZeros, and endIncrement have been tested and work correctly
//my array goes from 000 to 999 in the compute function: this has been tested and works correctly
//my program used to print the same *correct* equation over and over: I tried to fix this
//and now it prints nothing... please understand this when grading

//I have spent 10 hours in the lab today, 4 hours last night, and 3 hours the night before
//this project made me do nothing other than this,eat, and go to class for three days
//I also have not showered in three days. I have skipped meals. Please, please, please be gracious
//I am not a procrastinator: if I don't start the second I get it it's because every minute of my day including meals and showers is scheduled. I took showers, church, and all other homework out of
//my schedule for this homework please please please give me points wherever you can

//PRE: IS includes the operators and the numbers that satisfy the equation and the result
//POST: OS prints the equation using the operators, numbers, and result correctly
void printEquation(char operators[], int numberArray[], int result) {
  cout<<numberArray[0] << " ";
  for(int index = 0; (index<maxOp); index++) {
    char currOperator = operators[index]; //char stores the operator currently being used
    int currNum = numberArray[index+1]; //int stores the number currently being used
    cout << currOperator << " " << currNum << " ";
  }
    cout<< " = "; //prints the = sign
    cout <<  result << endl;//prints the result
}


//PRE: IS includes the operators, an array to store the appropriate number of integares, and the result
//POST: OS will compute the output 
int arithmetic(char operators[], int numArray[], int result) {
  bool Found = false;
  int answer = numArray[0];//answer starts as first number because we are building
  for(int index = 0; (index<maxOp); index++) {
    char currOperator = operators[index]; //char stores the operator currently being used
    int currNum = numArray[index+1]; //int stores the number currently being used
    if(currOperator == plus) {
      answer += currNum;
    }
    else if(currOperator == minus) {
      answer -= currNum;
    }
    else if(currOperator == multiply) {
      answer *= currNum;
    }
    else if(currOperator == divide) {
      answer /= currNum;
    }
  }
  return answer;
}


//PRE: parameters include the array
//POST: amends the array to fill all indicies with zeros
void fillZeros(int array[]) {
  int index = 0;
  while(index<maxNum) {
    array[index] = 0;
    index++;
  }
}

//PRE: parameters include the array being searched
//POST: returns true if all combinations have been found, false if not
bool endIncrement(int array[]) {
  bool end = false;
  int index = 0;
  int countNines = 0;
  while(index<maxNum) {
    if(array[index] == 9) {
      countNines++;
    }
    index++;
  }
  if(countNines == maxNum){
    end = true;
  }
  return end;
}

//PRE: IS includes the operators, number array, index being worked on, result, number of equations found, and the number of equations desired
//POST: the equation is print by calling the printEquation function and will print a statement if not enough equations are found
void compute(char operators[], int array[], int currIndex, int result, int numEquations, int numValues) {
  bool Found = false; //has not found enough equations to satisfy the conditions
  int currElement = array[currIndex]; //element we are looking at
  bool moveRight = false;
  bool moveLeft = false;
  if(currIndex!=0) {
    moveLeft = true; //can move left if not at very left
  }
  if(currIndex != maxNum-1) {
    moveRight = true;//can move right if not at very right
  }
  if(arithmetic(operators,array,result) == result) { //if equation satisfies result
      printEquation(operators,array,result);
      numEquations++;
  }
  while(!Found && (numEquations < numValues)) { //while we have not found enough equations
    if(endIncrement(array)) { //all combinations look through
      cout << "Insufficient equation possibilities" << endl;
      numEquations = numValues;//doesn't move on
      break; //doesn't recurse
    }
    while(!moveRight){ //cannot move to the right
      if(currElement < (upperbound-1)) { //if can increment element
	array[currIndex] = currElement+1; //increments element
	compute(operators,array,currIndex,result,numEquations,numValues); //recurses
      }
      else { //if cannot increment element
	if(moveLeft){ // can move left
	  array[currIndex] = 0; //resets current element to zero
	  currIndex--; //moves left
	  compute(operators,array,currIndex,result,numEquations,numValues); //recurses
	}
      }
      while(moveRight) { //can move right
	if(currElement < (upperbound-1)) { //can increment element
	  array[currIndex] = currElement+1; //increments by 1
	  currIndex++; //moves to the right
	  compute(operators,array,currIndex,result,numEquations,numValues); //recurses
	}
	else{//cannot increment more
	  if(moveLeft){ //can move left
	    array[currIndex] = 0; //resets current element to zero
	    currIndex--; //moves left
	    compute(operators,array,currIndex,result,numEquations,numValues); //recurses
	  }
	}
      }
    }
  }
}


//PRE: IS includes a char of operators, the equation's result, and the maximum number of values the program is looking for
//POST: OS outputs the equations that satisfy the operators and result up to the number of values the program is looking for
  int main () {
    char operators[maxOp]; //array of operators for the equations
    int result = 0; //what the equation should be equal to
    int numValues = 0; //number of equations desired
    for(int indexOp = 0; (indexOp < maxOp); indexOp++) { //inputs the desired amount of operators
      operators[indexOp] = cin.get();
    }
    cin >> result;
    cin >> numValues;
    cout << " " << endl;
    int numberArray[maxNum]; //creating an array of appropriate length
    fillZeros(numberArray); //fills the array with zeros
    compute(operators,numberArray,maxNum-1,result,0,numValues); //execute program

  return (0);
}
                                   
