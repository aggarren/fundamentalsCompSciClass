#ifndef INCLUDED_LIST
#define INCLUDED_LIST
#include "Node.h"
//CI:first's prev is null and last's next is null and numNodes is number of nodes in list
class LinkedList {
 protected:
  Node * first;  // pointer to the first node, if any, in this linked
		 // list object  
  Node * last;   // pointer to the last node, if any, in this linked
		 // list object 
  int numNodes;  // number of nodes in this object.

 public:
  //PRE:
  //POST:first and last are null, numNodes = 0
  LinkedList();

  //PRE:pList is defined
  //POST: this object is a deep copy of pList
  LinkedList(const LinkedList & pList);
  
  //PRE:LinkedList satisfies CI
  //POST: returns first
  Node* getFirst();
  
  //PRE:LinkedList satisfies CI
  //POST: returns last
  Node* getLast();

  //PRE:LinkedList satisfies CI
  //POST: first is Node x
  void setFirst(Node* x);
  
  //PRE:LinkedList satisfies CI
  //POST: last is Node x
  void setLast(Node* x);
  
  //PRE:LinkedList satisfies CI
  //POST:LinkedList's nodes' integers  are printed in OS
  void print();

  //PRE:LinkedList satisfies CI
  //POST:LinkedList contains all original nodes except first one
  void deleteFront();


  //PRE:LinkedList satisfies CI
  //POST:LinkedList has the Node x as the first node
  void addToFront(int x);

  //PRE:LinkedList satisfies CI
  //POST:LinkedList has the Node x as the last node
  void addToBack(int x);
  
  //PRE:LinkedList satisfies CI
  //POST:LinkedList contains all original nodes except last one
  void deleteBack();

  //PRE:LinkedList is a LinkedList with CI satisfied
  //POST:returns true if the list contains element X
  bool contains(int x);

  //PRE:LinkedList satisfies CI
  //POST:LinkedList has node with data x inserted at int position
  void insert(int x, int position);

  //PRE:LinkedList satisfies CI and contains x
  //POST: the position of x is returned
  int position(int x);
  
  //PRE:this object is defined
  //POST:The dynamic memory allocated for this object is deleted
  ~LinkedList();
  
};
#endif
                             
