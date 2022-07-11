#include <iostream>
using namespace std;
#include "constants.h"

//PRE: the array of ints are defined
//POST: OS contains the char values of the ASCII ints
void print(char arr[]) {
  int index = 0;
  while(arr[index] != EOS) {//goes through the indicies of array
    cout << arr[index];//prints each element
    index++;
  }
  cout << endl;
}

//PRE: the feedback array is defined
//POST: returns true if all ! and false if not
bool done(char feedback[]) {
  int index = 0;
  bool answer = true; //assume that we are done
  while(feedback[index] != EOS && answer){
    if(feedback[index] != RIGHT) {//not a ! indicates we are not done
      answer = false;
    }
    index++;
  }
  return answer;
}


//PRE: source and destination arrays are declared with size MAX_CHARS+1
//POST: destination array is a copy of source array
void copy(char source[], char dest[]) {
  int index = 0;//indexes through source array
  while(source[index] != EOS) {//goes through source array till the end
    dest[index] = source[index];//copies this element to dest array
    index++;//moves to next index
  }
  dest[index] = EOS;//puts EOS at end of destination array
}


//PRE: uncertainChars (of size MAX_CHARS by MAX_CHARS), feedback, and word arrays are all defined
//POST: uncertainChars are filled with the characters that got '-' for feedback at that position they were tried
void fillUncertainChars(char uncertainChars[MAX_CHARS][MAX_CHARS], char feedback[], char word[]) {
  for(int column=0; column<MAX_CHARS;column++) {//goes through the columns
    if(feedback[column] == UNCERTAIN) {//if we got uncertain feedback
      int row = 0;
      bool filled = false; //we have not filled this char in uncertainChars
      while(row<MAX_CHARS && !filled) {//goes through the rows until it's filled
	if(uncertainChars[column][row] == DELETED) {//if the space is clear
	  uncertainChars[column][row] = word[column];//put the character in this space
	  filled = true; //we have now filled this uncertainChar
	}
	row++;
      }
    }
  }
}

//PRE: uncertainChars is defined with size MAX_CHARS by MAX_CHARS
//POST: all elements of uncertainChars is DELETED
void initUncertainChars(char uncertainChars[MAX_CHARS][MAX_CHARS]) {
  for(int row=0; row<MAX_CHARS;row++) {
    for(int column=0; column<MAX_CHARS;column++) {
      uncertainChars[row][column] = DELETED;
    }
  }
}

//PRE:notChars,feedback,and word array are all defined; word and feedback arrays end in EOS
//POST:notChars are filled with the characters that got 'x' for feedback; notChars array ends in EOS
void fillRuledOut(char notChars[], char feedback[], char word[]) {
  int position = 0; //keeps track of the position in the word
   while(word[position] != EOS) {//goes through word till end
     if(feedback[position] == WRONG) {//we got x as a feedback for this position
       int notPos = 0;//index for finding next empty index in notChars
       int lastIndex = 0;//last index in notChars
       bool foundEOS = false;//becomes true when found index for EOS
       while(notPos < MAX_LETTERS && !foundEOS) {//goes through notChars until found EOS
	 if(notChars[notPos] == EOS) {//we have found EOS
	   foundEOS = true;
	 }
	 lastIndex = notPos;//this is the last index
	 notPos++;//move on
      }
       notChars[lastIndex] = word[position];//put this char in the last space
       notChars[lastIndex+1] = EOS;//end in EOS
    }
    position++;
  }
}

//PRE: character notChars uncertainChars and position are defined\
//POST: returns true if isRuledOut and false if is not ruled out
bool isRuledOut(char notChars[], char uncertainChars[MAX_CHARS][MAX_CHARS], char character, int position) {
  //CHECK NOTCHARS FOR CHARACTER
  bool answer = false; //we assume character is not ruled out
  int index = 0; //starting to look for char at index 0
  while(notChars[index] != EOS && !answer) {//look at elements until end or until found
    if(notChars[index] == character) {//we found the character in the list
      answer = true;
    }
    index++;//move on to next index
  }
  //IF IN NOTCHARS MAKE SURE ITS NOT IN UNCERTAINCHARS
  if(answer) {
    for(int row=0;row<MAX_CHARS;row++) {//goes through rows of uncertainChars
      for(int column=0; column<MAX_CHARS; column++) {//goes through columns of uncertainChars
	if(uncertainChars[row][column] == character) {//this character is an uncertainChars
	  answer = false;//it is not ruled out
	}
      }
    }
  }
  
  //CHECK UNCERTAINCHARS FOR CHARACTER AT THIS POSITION
  int answer2 = false; //we assume character is not ruled out
  for(int row=0; row<MAX_CHARS; row++) {//goes through the rows
    if(uncertainChars[position][row] == character) {//char found at this index
      answer2 = true;
    }
  }
  bool finalAnswer = false; //we assume it is not ruled out
  if(answer || answer2) {//the character was found either in notChars or in uncertainChars at this position
    finalAnswer = true;
  }
  //  cout << "RuledOut at position " << position << " for " << character << " is " << finalAnswer << endl;
  return finalAnswer;
}

//PRE: word and notChars are defined and end in EOS
//POST: returns true if word contains an element in notChars and false otherwise
bool hasRuledOut(char word[], char notChars[]) {
  bool answer = false;//assume word does not have ruled out chars
  int index = 0;//indexes through word
  while(word[index] != EOS) {//goes through word till end
    char character = word[index];//holds the current letter
    int indexChars = 0;//indexes through notChars
    while(notChars[indexChars] != EOS) {//goes through notChars till end
      if(notChars[indexChars] == character) {//this letter has a notChars character
	answer = true;
      }
      indexChars++;
    }
    index++;
  }
  return answer;
}

//PRE:notChars,uncertainChars,feedback,and word are all defined with feedback and word ending in EOS and notChars and uncertainChars with a length of MAX_CHARS
//POST:returns true if there are a correct number of appearances of uncertainChars and false if otherwise
bool correctAppearances(char notChars[], char uncertainChars[MAX_CHARS][MAX_CHARS], char feedback[], char word[], char ogWord[]) {
  bool allCorrect = true; //assume there are correct number of all uncertainChars
  int row = 0;
  int column = 0;
  while(column<MAX_CHARS && allCorrect) {//goes through rows of uncertainChars until finds an incorrect
    while(row<MAX_CHARS && allCorrect) {//goes through columns of uncertainChars until finds an incorrect

      if(uncertainChars[row][column] != DELETED) {//this is an uncertainChar
	bool correct = true; //assume there are correct number of this uncertainChars
	int countUncertain = 0;//counts number of this uncertainChar's uncertain feedback
	int countWrong = 0;//counts number of this uncertainChar's wrong feedback
	
	int index = 0;//goes through feedback
	while(feedback[index] != EOS) {//goes through feedback
	  if(feedback[index] == UNCERTAIN && ogWord[index] == uncertainChars[row][column]) {//the feedback is uncertain for this letter
	    countUncertain++;//increase count of uncertain
	  }
	  if(feedback[index] == WRONG && ogWord[index] == uncertainChars[row][column]) {//the feedback is wrong for this letter
	    countWrong++;//increase count of wrong
	  }
	  index++;
	}
        
	//We know how many of this uncertain are in the word
	if(countUncertain>0 && countWrong>0) {//if we counted both uncertains and wrongs for this character
	  int appearances = 0; //counts how many times thiss letter appears in the word
	  int indexWord = 0;//goes through the current word
	  while(word[indexWord] != EOS) {//goes through the current word
	    if(feedback[indexWord] != RIGHT && word[indexWord] == uncertainChars[row][column]) {//this is an appearance of the uncertainChar not certain
	      appearances++;
	    }
	    indexWord++;
	  }
	  if(appearances != countUncertain) {//we have exactly the number of appearances we must have
	    correct = false;
	  }
	  if(!correct) {//we have too many or too few appearances
	    allCorrect = false;
	  }
	}
	//We know the minimum number of this uncertain are in the word
	if(countUncertain>0 && countWrong == 0) {//we counted only uncertains for this character
	  int appearances2 = 0;//counts how many times this letter appears in the word
	  int indexWord2 = 0;//goes through the current word
	  while(word[indexWord2] != EOS) {//goes through the current word
	    if(feedback[indexWord2] != RIGHT && word[indexWord2] == uncertainChars[row][column]) {//this is an appearance of the uncertainChar not certain
	      appearances2++;
	    }
	    indexWord2++;
	  }
	  if(appearances2 < countUncertain) {//we have less appearances than allowed
	    correct = false;
	  }
	  if(!correct) {//we have too few appearances
	    allCorrect = false;
	  }
	}
	
      }
      row++;
    }
    column++;
  }
  return allCorrect;
}
