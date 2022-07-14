#include "Stack.h"
#include "LinkedList.h"
#include "Node.h"
//PRE:the implicit Stack meets CI
//POST:x is put on the stack
void Stack::push(int x){
  addToFront(x); //adds x to the back calling the LinkedList addtoBack function
}

//PRE:the implicit Stack meets CI
//POST:the top int is returned
int Stack::top() const{
  return first->getData(); //gets data for the first node
}

//PRE:the implicit Stack meets CI
//POST:the top int is removed from the stack
void Stack::pop(){
  deleteFront();//LinkedList's deleteFront function is called
}

//PRE: the implicit Stack meets CI
//POST: returns true if there are no ints on the stack
bool Stack::empty() const{
  bool answer = false;//we assume its not empty
  if(numNodes == 0) {//there are no ints in this list
    answer = true;
  }
  return answer;
}
                            
