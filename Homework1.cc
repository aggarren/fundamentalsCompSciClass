#include <iostream>
using namespace std;
//PRE: input stream gets two non-zero positive numbers, X and Y
//POST: output stream outputs the common prime factors of X and Y multiplied together
//Otherwise, if there are no common prime factors the OS outputs 1

bool isPrime(int number) {//function to check if prime
    int i = 2;//starts above 1
    while(i<number) {//goes up until number
      if(i % number == 0){//if i is a factor
	return false;//isPrime is false
    }
    else {
      return true;//otherwise isPrime is true
    }
      i++;
    }
  }

int main () {
  int number1;
  int number2;
  cout << "Enter two positive non-zero numbers: " << endl;
  cin >>number1;//user inputs first number
  cin >>number2;//user inputs second number
  int smaller; //holds smaller number of number1 and number2
  if(number1<number2) {//if number1 is smaller then number1 = smaller
    smaller = number1;
  }
  else{
    smaller = number2;//else number2 is smaller
  }
    int i = 1;//index for while loop
    int product = 1;//product of the common prime factors
    while(i<smaller) {//goes through the integers up until the smallest numbers 
      if(isPrime(i) and (number1%i==0 and number2%i==0)) {//if integer is prime and common factor
	product *=i; //if so, multiplies to product
    }
      i++;
  }

    cout << "Product: " << product << endl;//prints out product
  return (0);
  
}


    
  
