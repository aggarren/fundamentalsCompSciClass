#include "arithmetic.h"
#include "printEquation.h"
#include <iostream>
using namespace std;

//PRE: parameters include the two arrays and their length
//POST: the first array is a copy of the second
void make(int array1[], int array2[],int numLen) {
  for(int index=0; (index<numLen);index++) {
    array1[index] = array2[index];//element of index at array1 is assigned the same at array2
  }
}


//PRE: IS includes the last array outputted and the current array and the length of the arrays
//POST: returns true is a duplicate and false if it is not a duplicate
bool isDuplicate(int lastArray[], int currArray[], int numLen) {
  bool answer = false;//assume not duplicate
  int countSame = 0;//counts the number of elements that are the same
  for(int index=0; (index<numLen); index++) {
    if(lastArray[index] == currArray[index]) {//the elements are the same
      countSame++;
    }
  }
  if(countSame == numLen) {//all elements are the same so answer is true
    answer = true;
  }
  return answer;
}


//PRE: the array of numbers, the array length, and the upperbound are in the parameters
//POST: returns true if there are no more combinations of numbers, false if not
bool endIncrement(int array[], int numLen, int upperbound) {
bool end = false;
  int countNines = 0;
  for(int index=0; (index<numLen); index++) {//counts number of nines in array of numbers
    if(array[index] == upperbound-1) {
      countNines++;
    }
  }
  if(countNines == numLen) {//if all elements are nines we need to end the incrementing
    end = true;
  }
  return end;
}

//PRE: parameters include the operator and number arrays, the last array printed, its length, its upperbound, the index we are working on, and the result
//POST: the number array is amended to have a new combination of numbers
int newCombo(char operators[], int array[],int lastArray[], int numLen, int upperbound, int currIndex, int result, int limit) {
  int currElement = array[currIndex]; //element we are looking at
  bool moveRight = false;//true if can move right, false if not
  bool moveLeft = false;//true if can move left, false if not
  if(endIncrement(array,numLen,upperbound)) { //if we are done, end
    return currIndex;
    }
  if(limit < 36 and !endIncrement(array,numLen,upperbound)) {//if we are not done
    if(currIndex!=0) {
      moveLeft = true; //can move left if not at very left
    }
    if(currIndex != numLen-1) {
      moveRight = true;//can move right if not at very right
    }
    if(!isDuplicate(lastArray,array,numLen) and arithmetic(operators,array,numLen-1) == result) { //if equation satisfies result and is not a duplicate
      return currIndex;
    }
    if(!moveRight){ //cannot move to the right
      if(currElement < (upperbound-1)) { //if can increment element
	array[currIndex] = currElement+1; //increments element
	limit++; //increase count of recurses
	newCombo(operators,array,lastArray,numLen,upperbound,currIndex,result,limit); //recurses
      }
      else { //if cannot increment element
	if(moveLeft){ // can move left
	  array[currIndex] = 0; //resets current element to zero
	  currIndex--; //moves left
	  limit++; //increase count of recurses
	  newCombo(operators,array,lastArray,numLen,upperbound,currIndex,result,limit); //recurses
	}
      }
    }
    if(moveRight) { //can move right
      if(currElement < (upperbound-1)) { //can increment element
	array[currIndex] = currElement+1; //increments by 1
	currIndex++; //moves to the right	
	limit++; //increase count of recurses
	newCombo(operators,array,lastArray,numLen,upperbound,currIndex,result,limit); //recurses
      }
      else{//cannot increment more
	if(moveLeft){ //can move left
	  array[currIndex] = 0; //resets current element to zero
	  currIndex--; //moves left
	  limit++; //increase count of recurses
	  newCombo(operators,array,lastArray,numLen,upperbound,currIndex,result,limit); //recurses
	}
      }
    }
  }
  return currIndex;
}

//PRE: IS includes the operators, number array,the number of numbers, the result, and the number of equations desired
//POST: the equation is print by calling the printEquation function and will print a statement if not enough equations are found
void compute(char operators[], int array[], int numLen, int result, int upperbound, int maxEquations) {
  bool Done = false;
  int lastArray[numLen] = {}; //an array of the last equation printed
  int currIndex = numLen-1;//stores the current Index being worked on for newCombo
  int numEquations = 0;//stores the number of equations that have been calculated
  while(!Done){ //if need more equations or have not looked at all combinations
    if(numEquations == maxEquations) {//all necessary equations have been printed: we are done
      cout << "Done" << endl;
      Done = true; //will end the loop
    }
    else if(endIncrement(array,numLen,upperbound)) { //if we need to end the program
      cout << "Not enough equation possibilities" << endl;
      Done = true;//will end the loop
    }
    else if(arithmetic(operators, array, numLen-1) == result) { //if we found an equation
      printEquation(operators,array,result,numLen-1);//print it out
      numEquations++;//increase the number of equations we have found
      make(lastArray,array,numLen); //lastArray becomes a copy of array
    }
    currIndex = newCombo(operators,array, lastArray, numLen, upperbound, currIndex, result, 0); //finds a new combo of equations to check  
  }

} 
           
