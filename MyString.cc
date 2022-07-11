#include "MyString.h"
#include <iostream>
#define EOS '\0'
using namespace std;

// PRE: sourceStr is defined with s characters and sourceStr[s] = EOS.
//      destStr is allocated space for at least s+1 characters.
// POST: destStr is a deep copy of sourceStr.
void copy (char sourceStr[], char destStr[]) {
  int index = 0;
  while(sourceStr[index] != EOS) {
    destStr[index] = sourceStr[index];
    index++;
  }
  destStr[index] = EOS;
}



// Default constructor

// PRE:
// POST: This object is a string with 0 characters. C = 1. s = 0.
MyString::MyString () {
  currCapacity = 1;
  theString = new char[currCapacity];
  theString[0] = EOS;
  strSize = 0;
  
}


// Constructor, given an array of characters
// PRE: pStr is defined and ends with EOS
// POST: This object has the characters of pStr.
//       s = number of characters in pStr (not including EOS)
//       C > s.
MyString::MyString (char pStr[]) {
  currCapacity = 1;
  theString = new char[currCapacity];
  theString[0] = EOS;
  strSize = 0;
  int index = 0;
  while (pStr[index] != EOS) {
    // ASSERT: there is one more character of pStr that needs to be
    //           appended to this MyString object
    append (pStr[index]);
    index++;
  }
  // ASSERT: All the charaters of pStr have been added to this object,
  //           and this object satisfies the CI.
}

// COPY CONSTRUCTOR
// PRE: pStr is defined.
// POST: This object is a deep copy of pStr
MyString::MyString (const MyString & pStr) {
  // This object is being constructed, and thus not defined.
  // We will first allocate space for this object based on the space
  // needed, i.e., the number of characters in pStr
  strSize = pStr.strSize;
  theString = new char[strSize+1];
  currCapacity = strSize+1;
  // Now there is adequate space allocated to this object's theString
  //   so that we can copy all the characters (including EOS) of
  //   pStr.theString to theString.
  copy (pStr.theString, theString);
}

// Modifier
// PRE: This object is defined with s characters and currCapacity C > s.
//      ch is defined
// POST: This object is defined with s+1 characters and currCapacity
//            C' > (s+1)
//       theString[s] = ch and theString[s+1] = EOS.
//       This object satisfies the CI.
void MyString::append (char ch) {
  if (currCapacity <= (strSize + 1)) {
    // ASSERT: theString does not have space for another character
    char * temp = new char[currCapacity+1];
    // ASSERT: temp has one more space than this object.
    copy (theString, temp);
    // temp is a deep copy of theString
    delete [] theString; // memory for the current theString array is deleted.
    theString = temp;
    // ASSERT: theString has the same characters as before, and one
    //           more space for an additional character.
    currCapacity = currCapacity+1;
  }
  // ASSERT: theString has space for one more character, i.e.,
  //            currCapacity > (s+1).
  theString[strSize] = ch; // add the character to theString
  theString[strSize+1] = EOS; // add the EOS character
  strSize = strSize+1;
}

  // PRE: pStr is defined.
  //      This MyString object (the implicit parameter) is defined.
  // POST: This MyString object is a deep copy of pStr.
  //       RV is a reference to this MyString object.
MyString & MyString::operator= (const MyString & pStr) {
  // BEGIN FILLING HERE
  // This MyString object (the implicit parameter) is defined. So,
  //   there is some space allocated to theString.
  // Make a deep copy of pStr, i.e., the member data object
  //   pStr.theString into this object's theString.
  if(currCapacity >= pStr.currCapacity){
    copy(theString,pStr.theString);
  }
  else {
    char * temp = new char[pStr.currCapacity];
    // ASSERT: temp has one more space than this object.
    copy (theString, temp);
    // temp is a deep copy of theString
    delete [] theString; // memory for the current theString array is deleted.
    theString = temp;
    // ASSERT: theString has the same characters as before, and one
    //           more space for an additional character.
    currCapacity = pStr.currCapacity;
    strSize = pStr.strSize;
  }
  // Remember to appropriately take care of the situation where this
  //   object's theString does not have enough space for
  //   pStr.theString.
  // Update the values for currCapacity and strSize.
  // END FILLING HERE

  // We need to return a reference to this object (the implicit
  //   parameter). The reserved word "this" is a pointer to this
  //   object. We dereference the pointer to return the object.
  return (*this);
}

// Input/Output member functions
// PRE: This object is defined.
// POST: The string held by this object is printed (without a space
// or the newline character after it.
void MyString::print () {
  int index = 0;
  while(theString[index] != EOS) {
    cout << theString[index];
    index++;
  }
}

//PRE: implicit and explicit parameters defined
//POST: returns true if equivalent and false otherwise
bool MyString::operator==(const MyString & pStr){
  bool answer = true; //assume both are equivalent
  if(currCapacity == pStr.currCapacity) {//have same length
    int index = 0;
    while(index < currCapacity) {//goes through strings
      if(theString[index] != pStr.theString[index]) {//characters are not the same
	answer = false;
      }
      index++;
    }
  }
  return answer;
}

// DESTRUCTOR
// PRE: This object is defined.
// POST: The dynamic memory allocated for this object is deleted.
MyString::~MyString(){
  // We need to delete any dynamic memory allocated for this object.
  delete [] theString;
}
