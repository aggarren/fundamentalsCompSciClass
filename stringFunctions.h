#ifndef INCLUDED_stringFunctions
#define INCLUDED_stringFunctions
#include "StringList.h"
// PRE: sourceStr is defined with s characters and sourceStr[s] = EOS.
//      destStr is allocated space for at least s+1 characters.
// POST: destStr is a deep copy of sourceStr.
void copy (char source[], char dest[]);


//PRE: sourceList is defined with listSize MyStrings and destList is allocated space for at least listSize+1 characters
//POST: destList is a deep copy of sourceList
void copyList(MyString sourceList[], MyString destList[],int listLength);


//PRE: two arrays are defined
//POST: returns true if both same array and false if not
bool checkThis(char arr1[], char arr2[]);
#endif
               
