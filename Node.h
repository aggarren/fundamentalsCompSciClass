#ifndef INCLUDED_NODE
#define INCLUDED_NODE
#include <iostream>
using namespace std;
//CI: at initialization, next=prev=NULL and data is zero
template <class T>
class Node {
 private:
  T* data;      // the data item in this node
  Node<T> * next;   // pointer to the next node, if any, in the linked list
  Node<T> * prev;   // pointer to the previous node, if any, in the linked list.

 public:
  //PRE:
  //POST: data = 0 and next and prev = null
  Node(){
    next = prev = NULL;//next and prev are null
  };
  Node(T* pData){
    next = prev = NULL;
    data = pData;
  };

  //PRE: implicit and explicit parameters defined
  //POST: implicit is a deep copy of explicit
  Node<T>& operator=(const Node<T> & pNode) {
    data = pNode->data;//copy data
    next = prev = NULL;
  };
 
  //PRE:pNode is defined
  //POST: this object is a deep copy of pNode
  Node(Node<T> & pNode){
    data = pNode.getData();//copy data
    next = prev = NULL;
  };

  //PRE:Node satisfies CI
  //POST: pointer to next node is returned
  Node<T>* getNext(){
    return next;
  };

  //PRE: implicit parameter is defined
  //POST: data is returned
  T* getData () { return (data); };

  //PRE: implicit parameter and pData defined
  //POST: data is set as pData
  void setData(T* pData) { data = pData; };

 
  //PRE:Node satisfies CI
  //POST: next is set to Node x
  void setNext(Node<T>* x){
    next = x;
  };

  //PRE:Node satisfies CI
  //POST: pointer to prev node is returned
  Node<T>* getPrev(){
    return prev;
  };

  //PRE:Node satisfies CI
  //POST: prev is set to Node x
  void setPrev(Node<T>* x){
    prev = x;
  };
  //PRE:this object is defined
  //POST:The dynamic memory allocated for this object is deleted
  ~Node(){
    delete next;//deletes the next node
  };


};
#endif
  
