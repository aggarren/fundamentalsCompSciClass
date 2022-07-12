#ifndef INCLUDED_MyString
#define INCLUDED_MyString

class MyString {

  // CI: currCapacity = C >= 1
  //     strSize = s < C
  //     theString[0]..theString[s-1] are the string characters, and
  //        theString[s] = EOS.
  
 private:
  char * theString;   // dynamic array to hold a string
  int strSize;        // number of characters in the string (not
		      // including EOS)
  int currCapacity;   // number of spaces for characters allocated for
		      // theString

 public:

  // Default constructor

  // PRE:
  // POST: This object is a string with 0 characters. C = 1. s = 0.
  MyString ();

  // Constructor, given an array of characters
  // PRE: pStr is defined and ends with EOS
  // POST: This object has the characters of pStr.
  //       s = number of characters in pStr (not including EOS)
  //       C > s.
  MyString (char pStr[]);

  // COPY CONSTRUCTOR
  // *************************************************************
  // NOTE: The copy constructor is never called explicitly in a
  // program. It is automatically invoked by C++ when an object is
  // passed to a function by value.
  // *************************************************************


  
  // PRE: pStr is defined.
  // POST: This object is a deep copy of pStr.
  MyString (const MyString & pStr);

//PRE: takes in two MyStrings as a parameter
//POST: returns the boolean returned from the stringFunctions check function
  bool check(MyString string2);
  
  // Modifier
  // PRE: This object is defined with s characters and currCapacity C.
  //      ch is defined
  // POST: This object is defined with s+1 characters and currCapacity
  //            C' > (s+1).
  //       theString[s] = ch and theString[s+1] = EOS.
  //       This object satisfies the CI.
  void append (char ch);
  
  // OVERLOADED OPERATOR

  // ********************************************************************
  // Such an operator is useful so that the client can have the following:
  // MyString str1;
  // MyString str2;
  //  ...
  // str1 = str2;
  //     
  // In this case, str1 will be the implicit parameter to the
  // assignment operator, and str2 will be the explicit parameter
  // (passed as the formal parameter pStr)
  //
  // The reason for returning a reference to this MyString object from
  // the operator is so that the user can have:
  // MyString str1;
  // MyString str2;
  // MyString str3;
  //  ...
  // str1 = str2 = str3;
  //
  // In this case, first, str2 is the implicit parameter and str3 is
  // the explicit parameter. str2 is thus a deep copy of str3, and the
  // operator returns a reference to this new value of str2. Then,
  // str1 is the implicit parameter and the new value of str2 is the
  // explicit parameter. The operator then causes str1 to be a deep
  // copy of str2 (which is a deep copy of str3), and the return value
  // of the operator is a reference to the new value of str1.
  // ********************************************************************
  
  // PRE: pStr is defined.
  //      This MyString object (the implicit parameter) is defined.
  // POST: This MyString object is a deep copy of pStr.
  //       RV is a reference to this MyString object.
  MyString & operator= (const MyString & pStr);

  // Input/Output member functions
  // PRE: This object is defined.
  // POST: The string held by this object is printed (without a space
  // or the newline character after it.
  void print ();



  
//ACCESSOR
//PRE: the object is defined
//POST: returns the array of chars for MyString
  char* getArray();


  
  // DESTRUCTOR
  // *************************************************************
  // NOTE: The destructor is never called explicitly in a program. It is
  //         automatically invoked by C++ when an object goes out of scope.
  //       Just like constructors, the destructor has no return type.
  // *************************************************************

  // PRE: This object is defined.
  // POST: The dynamic memory allocated for this object is deleted.
  ~MyString();

};
#endif
