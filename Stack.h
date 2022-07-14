#ifndef INCLUDED_STACK
#define INCLUDED_STACK
#include "LinkedList.h"
class Stack : public LinkedList {
  
 public:
  //PRE:the implicit Stack meets CI
  //POST:x is put on the stack
  void push(int x);

  //PRE:the implicit Stack meets CI
  //POST:the top int is returned
  int top() const;

  //PRE:the implicit Stack meets CI
  //POST:the top int is removed from the stack
  void pop();

  //PRE: the implicit Stack meets CI
  //POST: returns true if there are no ints on the stack
  bool empty() const;
};
#endif
