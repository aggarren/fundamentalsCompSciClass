#include <iostream>
using namespace std;
//PRE: parameters include character and word
//POST: returns index of character in word
int findPlace(string character, string word) {
  int index = 0;
  int place = -1;
  if(word.length() != 0) { //will only run if word is not empty
    if(character != word.substr(0,1)) {//if the first character of word is not character
      if(word.length() == 1) {//if this is the last character
	index++;//will increase index to the length value and end
      }
      else{ //if there are more characters to check
	index+=1;//increments index 
	index+=findPlace(character,word.substr(1)); //will continue to check
      }
    }
  }
  return index;
}
//PRE: parameters include the matching characters, the first word, and the second word
//POST: OS returns the characters with the same placement in both words
bool samePlace(string character, string firstWord, string secondWord) {
  int firstIndex = findPlace(character,firstWord); //finds the character's index in the first word
  int secondIndex = findPlace(character,secondWord);//finds the character's index in the second word
  bool value;
  if(firstIndex == secondIndex) {//if the character has the same index in both words
   value = true;//returns true if have the same index
  }
  else {
    value = false;
  }
  return value;
}
//PRE: parameters include the two words and a string holding the characters that exist in both in addition, has the original second word string for placement comparison
//POST: returns output with a ^ for same place, a - for existing in both, and nothing of neight
string existBoth(string firstWord, string secondWord, string ogSecondWord) {
  string output;
  string character = secondWord.substr(0,1); //string holds the first character of second word
  if(secondWord.length() > 0) {
    if(findPlace(character,firstWord) != firstWord.length()) {//if character exists in first word
      if(samePlace(character,firstWord,ogSecondWord)) {//if character is found in first word it searches for its placement
	output += "^";//outputs a carat for the same placement in both words
    }
      else {
	output += "-";//outputs a dash for existing in both words but not same placement      
    }
  }
  else {
    output += " ";//outputs nothing for no match
    }
  secondWord = secondWord.substr(1); //gets rid of that character in the second word
  output += existBoth(firstWord,secondWord,ogSecondWord); //compares the first and second word again through recursion
  }
  return output; //returns the characters that exist in both
}
//PRE: IS includes two Strings, w1 and w2
//POST: OS includes the two words and which characters match
//a character should be underlined in the second word if it's in the first word but not the same place
//a character should be bent underlined in the second word if it's in the first word in the same place
int main() {
  string firstWord;
  //ASSERT: firstWord = w1
  string secondWord;
  //ASSERT: secondWord = w2
  cout << "Enter first word: " << endl; //Prompts for first word
  cin >> firstWord; //User inputs first word
  cout << "Enter second word: " << endl; //Prompts for second word
  cin >> secondWord; //User inputs second word
  string output;  //holds the characters to underline the output
  output = existBoth(firstWord,secondWord,secondWord);
  cout << firstWord << endl << secondWord << endl << output << endl;
  return (0);
}
            
