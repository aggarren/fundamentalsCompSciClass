#include "stringFunctions.h"
#include "constants.h"
#include "StringList.h"
#include "MyString.h"
#include <iostream>
#define EOS '\0'
using namespace std;
// PRE: sourceStr is defined with s characters and sourceStr[s] = EOS.
//      destStr is allocated space for at least s+1 characters.
// POST: destStr is a deep copy of sourceStr.
void copy (char source[], char dest[]) {
  int index = 0;
  while(source[index] != EOS) {
    dest[index] = source[index];
    index++;
  }
  dest[index] = EOS;
}

//PRE: sourceList is defined with listSize MyStrings and destList is allocated space for at least listSize+1 characters
//POST: destList's elements are a copy of sourceList elements
void copyList(MyString sourceList[], MyString destList[], int listLength) {
  int index = 0;
  while(index < listLength) {
    destList[index] = sourceList[index];
    index++;
  }
}


//PRE: two arrays are defined
//POST: returns true if both same array and false if not
bool checkThis(char arr1[], char arr2[]) {
  bool answer = true; //assume same array
  int index = 0;
  bool done = false; //ends the loop when done
  while(arr1[index] != EOS && !done) {//we are not at the end of string and are not done
    if(arr1[index] != arr2[index]) { //elements aren't equal
      answer = false;//the answer is false
      done = true; //we have found one false so we are done
    }
    index++;
  }
  return answer;
}
 
