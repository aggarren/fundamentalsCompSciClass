#include "StringList.h"
#include "MyString.h"
// PRE: pList is defined.
// POST: OS contains all the words (MyString objects) that appear more
//          than once in pList.
void process (StringList pList) {
  pList.printDuplicates();
}

// PRE: IS contains words (lower case letters), one on each line. Each
//        word on the IS ends with the new line character. End of file
//        denotes the end of input.
// POST: OS contains all the words that appear more than once on the IS.
int main () {
  StringList aList;
  aList.readStrings ();
  // ASSERT: aList contains an array of MyString objects, each object
  // containing one word from the IS.

  process (aList);
  // ASSERT: OS contains all the words that appear more than once on
  //            the IS.

  return (0);
}
      
