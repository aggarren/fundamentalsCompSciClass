#ifndef INCLUDED_QUEUE
#define INCLUDED_QUEUE
#include "LinkedList.h"
#include <iostream>
using namespace std;
template <class T>
class Queue : public LinkedList<T> {
 public:
  //PRE:the implicit Stack meets CI
  //POST:the top int is returned
  T* top() const { return this->first->getData(); };
  
  //PRE:the implicit Stack meets CI
  //POST:x is put on the stack
  void push(T* x) { this->addToBack(x); };

  //PRE:the implicit Stack meets CI
  //POST:the top int is removed from the stack
  void pop(){ this->deleteFront(); };

  //PRE: the implicit Stack meets CI
  //POST: returns true if there are no ints on the stack
  bool empty() const{
    bool answer = false;//we assume its not empty
    //cout << this->numNodes << endl;
    if(this->numNodes == 0) {//there are no ints in this list
      answer = true;
    }
    return answer;
  };

};
#endif
