#ifndef INCLUDED_GUESSING
#define INCLUDED_GUESSING
#include "constants.h"
#include "Dictionary.h"
//PRE: the word, notChars, feedback arrays are all defined and end in EOS, currIndex is defined
//POST: word contains a word in the dictionary
bool guess(char word[], char notChars[],char uncertainChars[MAX_CHARS][MAX_CHARS], char feedback[], int currIndex, Dictionary dict);

//PRE: word, uncertainChars, notChars, and feedback are all defined and end in EOS,
//POST: word contains a word in the dictionary containing all uncertainChars
void getWord(char word[], char uncertainChars[MAX_CHARS][MAX_CHARS], char notChars[], char feedback[], Dictionary dict);
#endif
