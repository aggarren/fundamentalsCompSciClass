How to play:
think of a 5 letter word, type it into the computer to check if it is in the dictionary
the computer will guess a word:
type ! for a correct letter in the correct place
type a x for a letter that does not appear in the word
type a - for a letter that appears in the word but is not in the correct place
------------------------------------------------------------------------------------------------------------------------------
Rationale of program:
when a user types feedback for a word, it stores it in an array
the program takes the feedback
    if the feedback character is a -:
       stores the letter at the first available space for that index in which the character was tried at in a matrix

    if the feedback character is a x:
       stores it at the first available space in an array

the program finds a new combination of letters that makes a word
    not changing the letters that gave a ! for feedback
    not putting letters that gave a x in feedback into the word
    once it finds a word, it checks if it is a good guess
    	 it is a good guess if it:
	    does not contain a char that has been ruled out
	    contains all chars that returned a - , but not at indicies they have already been tried
	    contains an appropriate number of appearances of - feedback characters
	    	     if feedback gave several -'s for a certain character it will contain at least that many of that charactr
		     if feedback gave - and x for a certain character, it will contain exactly - many of that character
prints the word if it is a good guess
user provides feedback: if it is not all !, it tries again until it is
------------------------------------------------------------------------------------------------------------------------------
File contents:
Project1.cc: contains main function
guessing.cc: gets new word
arrayFunctions.cc: manages arrays
guessing.h: header file for guessing.cc
arrayFunctions.h: header file for arrayFunctions.cc
constants.h: contains constants
Makefile: instructions to compile and link files
Dictionary.h: header file for dictionary class
Dictionary.o: enables program to have access to a dictionary
------------------------------------------------------------------------------------------------------------------------------
To make file:
type in command prompt: make Project1
      
