#ifndef INCLUDED_EXCEPTION
#define INCLUDED_EXCEPTION
#include <iostream>
using namespace std;
class Exception {
 private:
  char * message;
 public:
  Exception(char * mess) { message = mess; };
  void handle() { cout << "Exception " << message << endl; };
  ~Exception() { delete message; };
};
#endif
