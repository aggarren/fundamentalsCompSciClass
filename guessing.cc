#include "arrayFunctions.h"
#include "constants.h"
#include "Dictionary.h"
#include <iostream>
using namespace std;

//PRE: the word, notChars, feedback arrays are all defined and end in EOS, currIndex is defined
//POST: word contains a word in the dictionary 
bool guess(char word[], char notChars[], char uncertainChars[MAX_CHARS][MAX_CHARS],char feedback[], int currIndex, Dictionary dict) {
  bool isWord = false;//this word is not in dictionary
  if(currIndex == -1) {//all spaces have been filled
    isWord = dict.isInDictionary(word);//checks if it is in the dictionary
  }
  else {
    if(feedback[currIndex] != RIGHT) {//we don't know this index's char
      char currLetter = (char)(((int)word[currIndex])+1); //this is the letter we are using
      if(currLetter>Z) {//we are at the end of the alphabet
	currLetter = A;//cycle back to the beginning
      }
      char firstLetter = currLetter; //keeps track of first letter
      bool allChecked = false; //we have not checked all letters
      while(!allChecked && !isWord) {//this letter is less than Z and this is not a word
	if(!isRuledOut(notChars,uncertainChars,currLetter,currIndex)) {//if this letter is not ruled out at this index and we don't know this letter
	  word[currIndex] = currLetter; //we fill this index with currLetter
	}
	isWord = guess(word,notChars,uncertainChars,feedback,currIndex-1,dict);//move to next index
	currLetter++; //move on to the next letter
	if(currLetter>Z) {//we are at the end of the alphabet
	  currLetter = A;//cycle back to the beginning
	}
	if(currLetter == firstLetter) {//we have cycled through all letters
	  allChecked = true;
	}
      }
    }
    else {//we do know this index's char
      isWord = guess(word,notChars,uncertainChars,feedback,currIndex-1,dict);//move to next index
    }
  }
  
  return isWord;
}

//PRE: word, uncertainChars, notChars, and feedback are all defined and end in EOS,
//POST: word contains a word in the dictionary containing all uncertainChars
void getWord(char word[], char uncertainChars[MAX_CHARS][MAX_CHARS], char notChars[], char feedback[], Dictionary dict) {
  bool goodGuess = false; //we do not have a dictionary word with uncertainChars
  char ogWord[MAX_CHARS+1];//array holds word that gave feedback
  copy(word,ogWord);//copies current word into ogWord
  int currIndex = MAX_CHARS-1; //starting filling 
  while(!goodGuess) {//word is not a good guess
    cout << "Thinking... Please Wait" << endl;
    //CHANGE WORD BEFORE GOING INTO GUESS
    int index = currIndex; //start at end
    bool filled = false; //we have not changed the last available char in the word
    while((index > -1) && !filled) {//until we hit the end
      if(feedback[index] != RIGHT) {//we don't know this char
	word[index]++; //increase this char
	filled = true;
      }
      else {//we know this char
	index--;//move to last index
      }
    }
    //FILL THE WORD WITH UNCERTAINS
    bool aWord = dict.isInDictionary(word); //evaluates if word is in dictionary
    while(!aWord) {//word is not in the dictionary
      aWord = guess(word,notChars,uncertainChars,feedback,currIndex,dict);//get a new guess to try
    }
    //ASSERT: word is in the dictionary
    if(!hasRuledOut(word,notChars) && correctAppearances(notChars,uncertainChars,feedback,word,ogWord)) {//there are a correct number of all uncertains
      goodGuess = true;//it is a good guess
    }
  }
  cout << "My next guess is: ";
  print(word);
}
                                                                                                                                      CPSC170/Projects/aggarren-Project1/constants.h                                                      0000640 0014416 0014416 00000000370 14215102263 021423  0                                                                                                    ustar   aggarren                        aggarren                                                                                                                                                                                                               #ifndef INCLUDED_CONSTANTS
#define INCLUDED_CONSTANTS
#define A 'a'
#define Z 'z'
#define MAX_TRIES 10
#define MAX_CHARS 5
#define MAX_LETTERS 26
#define EOS '\0'
#define RIGHT '!'
#define WRONG 'x'
#define UNCERTAIN '-'
#define DELETED '.'
#endif
                                                                                                                                                                                                                                                                        CPSC170/Projects/aggarren-Project1/Project1.cc                                                      0000640 0014416 0014416 00000005122 14216462117 021244  0                                                                                                    ustar   aggarren                        aggarren                                                                                                                                                                                                               #include <iostream>
#include "arrayFunctions.h"
#include "constants.h"
#include "guessing.h"
#include "Dictionary.h"
using namespace std;
//PRE: the word is initiallized with size MAX_CHARS+1
//POST: array contains inputted by user
void getWord(char word[]) {
  int letters = 0;
  while(letters<MAX_CHARS) {//keeps getting letters to fill the word
    word[letters] = cin.get();
    letters++; //increments to next letter
  }
  char junk = cin.get(); //gets the EOL char
  word[MAX_CHARS] = EOS; //array ends in EOS
 
}


//PRE: the feedback is initiallized with size MAX_CHARS+1
//POST: feedback array contains inputted by user
void getFeedback(char feedback[]) {
  int letters = 0;
  while(letters<MAX_CHARS) {//keeps getting letters to fill the word
    feedback[letters] = cin.get();
    letters++; //increments to next letter
  }
  char junk = cin.get(); //gets the EOL char
  feedback[MAX_CHARS] = EOS; //array ends in EOS
 }

int main () {
  char word[MAX_CHARS + 1]; //array for outputting our guess
  Dictionary dict;
  char checkWord[MAX_CHARS + 1];//array to input word to check
  checkWord[MAX_CHARS] = EOS;//ends in EOS
  bool aWord = false; //says if inputted word is in dictionary
  while(!aWord) {//not a word
    cout << "Check your word: ";
    getWord(checkWord);//get a word from the user
    if(dict.isInDictionary(checkWord)) {//word is in dictionary
      aWord = true;//aWord becomes true
    }
  }
  dict.getRandomWord(word); //puts a random word in the word
  char feedback[MAX_CHARS+1];//holds the feedback inputted from user
  char uncertainChars[MAX_CHARS][MAX_CHARS]; //holds the chars we know are in the word but don't know where at the position we know they are not at
  initUncertainChars(uncertainChars); //fill uncertainChars with DELETED
  char notChars[MAX_LETTERS];//array to hold ruled out characters
  notChars[0] = EOS; //we put EOS in notChars
  print(word);//we print the word
  getFeedback(feedback);//we get the feedback
  int tries = 1; //we have tried to guess the word 1 time
  while((tries < MAX_TRIES) && !done(feedback)) {//loop to keep trying until max tries or gotten the correct word   
    //RECORDING CHARACTERS WITH - AND x FEEDBACK
    fillUncertainChars(uncertainChars,feedback,word); //fills the uncertainChars with the characters that got a - on feedback
    fillRuledOut(notChars,feedback,word); //fills the notchars with the characters that got a x on feedback
    //GETS A NEW WORD AND PRINTS IT
    getWord(word,uncertainChars,notChars,feedback,dict);
    //FEEDBACK
    getFeedback(feedback);//we get the feedback
    tries++;//we have tried one more time
  }
  return (0);
}
