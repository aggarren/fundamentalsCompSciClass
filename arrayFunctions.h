#ifndef INCLUDED_Project1
#define INCLUDED_Project1
#include "constants.h"
//PRE: the array of chars are defined
//POST: OS contains the array
void print(char arr[]);

//PRE: the feedback array is defined
//POST: returns true if all ! and false if not
bool done(char feedback[]);

//PRE: source and destination arrays are declared with size MAX_CHARS+1
//POST: destination array is a copy of source array
void copy(char source[], char dest[]);

//PRE: uncertainChars (of size MAX_CHARS by MAX_CHARS), feedback, and word arrays are all defined
//POST: uncertainChars are filled with the characters that got '-' for feedback at that position they were tried
void fillUncertainChars(char uncertainChars[MAX_CHARS][MAX_CHARS], char feedback[], char word[]);

//PRE: uncertainChars is defined with size MAX_CHARS by MAX_CHARS
//POST: all elements of uncertainChars is DELETED
void initUncertainChars(char uncertainChars[MAX_CHARS][MAX_CHARS]);

//PRE:notChars,feedback,and word array are all defined; word and feedback arrays end in EOS
//POST:notChars are filled with the characters that got 'x' for feedback; notChars array ends in EOS
void fillRuledOut(char notChars[], char feedback[], char word[]);


//PRE: character notChars uncertainChars and position are defined\
//POST: returns true if isRuledOut and false if is not ruled out
bool isRuledOut(char notChars[], char uncertainChars[MAX_CHARS][MAX_CHARS], char character, int position);


//PRE: word and notChars are defined and end in EOS
//POST: returns true if word contains an element in notChars and false otherwise
bool hasRuledOut(char word[], char notChars[]);

//PRE:notChars,uncertainChars,feedback,and word are all defined with feedback and word ending in EOS and notChars and uncertainChars with a length of MAX_CHARS
//POST:returns true if there are a correct number of appearances of uncertainChars and false if otherwise
bool correctAppearances(char notChars[], char uncertainChars[MAX_CHARS][MAX_CHARS], char feedback[], char word[], char ogWord[]);

#endif
