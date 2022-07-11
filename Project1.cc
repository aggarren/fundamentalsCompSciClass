#include <iostream>
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
    cout << "Check your word ";
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
                        
