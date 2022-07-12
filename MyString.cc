#include "MyString.h"
#include "stringFunctions.h"
#include "constants.h"
#include <iostream>
using namespace std;
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
  copy(pStr,theString);
    // ASSERT: there is one more character of pStr that needs to be
    //           appended to this MyString object
   
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
  theString = new char[strSize];
  currCapacity = pStr.currCapacity;
  // Now there is adequate space allocated to this object's theString
  //   so that we can copy all the characters (including EOS) of
  //   pStr.theString to theString.
  copy (pStr.theString,theString);
}

//PRE: takes in two MyStrings as a parameter
//POST: returns the boolean returned from the stringFunctions check function
bool MyString::check(MyString string2) {
  bool answer = checkThis(theString,string2.theString);
  return answer;
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
    copy(pStr.theString,theString);
  }
  else {
    char * temp = new char[pStr.currCapacity];
    // ASSERT: temp has one more space than this object.
    copy (pStr.theString, temp);
    // temp is a deep copy of pStr's theString
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

// DESTRUCTOR
// PRE: This object is defined.
// POST: The dynamic memory allocated for this object is deleted.
MyString::~MyString(){
  // We need to delete any dynamic memory allocated for this object.
  delete [] theString;
}
