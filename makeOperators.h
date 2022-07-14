#ifndef INCLUDED_makeOperators
#define INCLUDED_makeOperators

//PRE: the operators array consists of 0, 1, and 2's
//POST: the operators array replaces 0's with pluses, 1's with minuses, and 2's with multiplication
void makeCharacters(char operators[], int maxOp);


//PRE: parameters include the operators array, the length of the array, the index being worked on, the array for numbers, the result, and the upperbound
//POST: the array is filled with a new combination of operators and calls the compute function to print an equation
void makeOperators(char operators[], int maxOp, int currIndex, int numbers[], int result, int upperbound);

#endif
