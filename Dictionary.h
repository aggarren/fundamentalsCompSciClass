#ifndef INCLUDED_Dictionary
#define INCLUDED_Dictionary

// CI: Words contains size words. Each word is a 5 letter word ending
//       with EOS.

class Dictionary {
 
private:
  static char ** Words;  // An array of arrays of 5 letter words.
  int size;              // Number of words in the dictionary

  // PRE:
  // POST: size = N. Words is populated with N 5 letter words, each
  //         word ending with EOS.
  void initDictionary (); // Initialize the dictionary with 5 letter words.

public:
  // PRE:
  // POST: size = N. This object is a dictionary of N 5 letter words,
  //         each word ending with EOS. 
  Dictionary ();  // Construct the dictionay object

  // PRE: word has space allocated for a 5 letter word (6 spaces so
  //         that the word can end in EOS)
  // POST: word contains a random word from the dictionary.
  void getRandomWord (char word[]);

  // PRE: word is a defined 5 letter word ending in EOS
  // POST: RV is true iff word in in the dictionary.
  bool isInDictionary (char word[]);
};
#endif
             
