#include "StringList.h"
#include "MyString.h"
#include "stringFunctions.h"
#include "constants.h"
#include <iostream>
using namespace std;
//Constructor
//PRE:an object of StringList is created
//POST:this objects has the default characteristics of a currCapacity of MAXCAP, a listSize of 0, and a stringsArray of capacity currCapacity
StringList::StringList() {
  currCapacity = MAXCAP;
  listSize = 0;
  stringsArray = new MyString[currCapacity];
}


//ACCESSOR
//PRE: the StringList object is defined
//POST: the StringList's listSize is returned
int StringList::getListSize() {
  return listSize;
}


//COPY CONSTRUCTOR
//PRE: pList is defined
//POST: This object is a deep copy of pList
StringList::StringList (const StringList & pList) {
  currCapacity = pList.currCapacity;
  listSize = pList.listSize;
  stringsArray = new MyString[listSize+1];
  copyList(pList.stringsArray, stringsArray, listSize);
}

//PRE:the object of StringList is defined
//POST: the MyString object is added to the StringList
void StringList::add(MyString newStr) {
  if(listSize >= currCapacity-1) {//there's no more room in this StringList
    MyString * temp = new MyString[listSize+1]; //temp is a MyString array of size list+1
    copyList(stringsArray,temp,listSize+1);//copies implicit's array into temporary's array
    temp[listSize+1] = newStr; //adds new MyString to the StringList
    delete [] stringsArray;//deletes implicit's array
    stringsArray = temp; //changes pointer for the implicit's array to temp
    listSize++; //updates the list size for this StringList
    currCapacity++;//increases current capacity by 1 for this StringList
  }
  else {//there's more room in this stringlist
    stringsArray[listSize+1] = newStr; //adds new MyString to the StringList;
    listSize++; //updates the list size for this StringList
  }
 }

//PRE:IS is the strings
//POST:the StringList is composed of the inputted strings
void StringList::readStrings(){
  MyString inputString;//the my string object being inputted
  char input;//the char being inputted to be stored in the inputString
  while(!cin.eof()) {
    input = cin.get();
    if(input == EOL) {
      add(inputString);//add the inputString to this StringList
      inputString = MyString(); //makes new empty MyString object
    }
    else {
      inputString.append(input); //adds the input to the MySTring inputString
    }
  }
}


//PRE:StringList is defined
//POST:prints all MyStrings that appear more than once
void StringList::printDuplicates () const{
  int thisString = 0; //we are comparing this string to all others
  while(thisString<listSize) {//we have more strings to check
    int checkingThis = thisString+1; //we are comparing the checkingThis string to thisString
    while(checkingThis<listSize) {//we have more strings to check
      MyString MyString1 = stringsArray[thisString];
      MyString MyString2 = stringsArray[checkingThis];
      if((MyString1.check(MyString2))) {//thisSTring and checkingThis are the same string
	stringsArray[thisString].print();//print this MyString object
      }
      checkingThis++; //we move on to the next string to check
    }
    thisString++; //we move on to the next string
  }
}

//Destructor
//PRE: the StringList object is defined
//POST: the StringList's array is deleted when it goes out of scope
StringList::~StringList () {
  delete [] stringsArray;
}
