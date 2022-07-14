#ifndef INCLUDED_NODE
#define INCLUDED_NODE

//CI: at initialization, next=prev=NULL and data is zero
class Node {

 private:
  
  int data;      // the data item in this node
  Node * next;   // pointer to the next node, if any, in the linked list
  Node * prev;   // pointer to the previous node, if any, in the linked list.

 public:
  
  //PRE:
  //POST: data = 0 and next and prev = null
  Node();

  //PRE:pNode is defined
  //POST: this object is a deep copy of pNode
  Node(Node & pNode);

  //PRE:Node satisfies CI
  //POST:node's data is printed and so are all nodes after it
  void print();
  
  //PRE:Node satisfies CI
  //POST: data from node is returned
  int getData();

  //PRE:Node satisfies CI
  //POST: data is set to int x
  void setData(int x);
  
  //PRE:Node satisfies CI
  //POST: pointer to next node is returned
  Node* getNext();

  //PRE:Node satisfies CI
  //POST: next is set to Node x
  void setNext(Node* x);
 
  //PRE:Node satisfies CI
  //POST: pointer to prev node is returned
  Node* getPrev();
 
  //PRE:Node satisfies CI
  //POST: prev is set to Node x
  void setPrev(Node* x);

  //PRE:this object is defined
  //POST:The dynamic memory allocated for this object is deleted
  ~Node();
};
#endif
  
                                    
