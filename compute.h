#ifndef INCLUDED_compute
#define INCLUDED_compute

//PRE: parameters include the two arrays and their length
//POST: the first array is a copy of the second
void make(int array1[], int array2[],int numLen); 

//PRE: the array of numbers, the array length, and the upperbound are in the parameters
//POST: returns true if there are no more combinations of numbers, false if not
bool endIncrement(int array[], int numLen, int upperbound);

//PRE: parameters include the operator and number arrays, the last array printed, its length, its upperbound, the index we are working on, and the result
//POST: the number array is amended to have a new combination of numbers
int newCombo(char operators[], int array[], int lastArray[], int numLen, int upperbound, int currIndex, int result, int limit);

//PRE: IS includes the operators, number array,the number of numbers, the result, and the number of equations desired
//POST: the equation is print by calling the printEquation function and will print a statement if not enough equations are found
void compute(char operators[], int array[], int numLen, int result, int upperbound, int maxEquations);
#endif
           
