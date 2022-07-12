#ifndef INCLUDED_STRINGLIST
#define INCLUDED_STRINGLIST
#include "MyString.h"
#include "constants.h"
class StringList {
 private:
  MyString * stringsArray;
  //an array capable of holding DEFAULT_ARRAY_SIZE MyString objects
  int listSize = 0; //number of MyString objects in the array stringsArray
  int currCapacity = DEFAULT_ARRAY_SIZE; //number of spaces in the array stringsArray
 public:

  //PRE:an object of StringList is created
  //POST:this objects has the default characteristics
  StringList();

//ACCESSOR
//PRE: the object and the array are defined
//POST: the MyString object is fetched
  MyString getMyString(int index) const;
//ACCESSOR
//PRE: the StringList object is defined
//POST: the StringList's listSize is returned
  int getListSize();


//COPY CONSTRUCTOR
//PRE: pList is defined
//POST: This object is a deep copy of pList
  StringList (const StringList & pList);

  
  //PRE:the object of StringList is defined
  //POST: the MyString object is added to the StringList
  void add(MyString newstr);
  
    //PRE:IS is the strings
  //POST:the StringList is composed of the inputted strings
  void readStrings();

//PRE:StringList is defined
//POST:prints all MyStrings that appear more than once
  void printDuplicates() const;


  
//Destructor
//PRE: the StringList object is defined
//POST: the StringList's array is deleted when it goes out of scope
  ~StringList ();
};
#endif
                  
