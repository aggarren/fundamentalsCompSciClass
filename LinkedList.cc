#include "LinkedList.h"
#include "Node.h"
#include <iostream>
using namespace std;

//PRE:
//POST:first and last are null, numNodes = 0
LinkedList::LinkedList() {
  numNodes = 0;//numNodes is set to 0
  first = last = NULL;//first and last are null
}


//PRE:pList is defined
//POST: this object is a deep copy of pList
LinkedList::LinkedList(const LinkedList & pList){
  first = pList.first;//copies first
  last = pList.last;//copies last
  numNodes = pList.numNodes;//copies numNOdes
}

//PRE:LinkedList satisfies CI
//POST: returns first
Node* LinkedList::getFirst(){
  return first;
}
  
//PRE:LinkedList satisfies CI
//POST: returns last
Node* LinkedList::getLast(){
  return last;
}

//PRE:LinkedList satisfies CI
//POST: first is Node x
void LinkedList::setFirst(Node* x){
  first = x;
}
  
//PRE:LinkedList satisfies CI
//POST: last is Node x
void LinkedList::setLast(Node* x){
  last = x;
}
  
//PRE:LinkedList satisfies CI
//POST:LinkedList's nodes' integers  are printed in OS
void LinkedList::print(){
  if(first != NULL) {//prints the first node if not null
    first->print();
  }
}
//PRE:LinkedList satisfies CI
//POST:LinkedList contains all original nodes except first one
void LinkedList::deleteFront() {
  if(numNodes == 1) {//one node
    delete first;//deletes first node
    first = NULL;//first and last are null
    last = NULL;
  }
  else {//more than one node
    Node* newFirst = first->getNext();//second node is newFirst
    newFirst->setPrev(NULL);//newFirst's prev is null
    first->setNext(NULL);//first's next is null
    delete first;//first node is deleted
    first = newFirst;//newFirst is the new first
  }
  numNodes--;//numNodes decrements
}

//PRE:LinkedList satisfies CI
//POST:LinkedList has the Node x as the first node
void LinkedList::addToFront(int x) {
  Node* node = new Node();//node to store x
  node->setData(x);//storing x in node
  if(numNodes == 0) {//no nodes
    first = node;//first and last are this node
    last = node;
    numNodes++;//increment numNodes
  }
  else {//nodes exist
    first->setPrev(node);//first points back to node
    node->setNext(first);//node points forward to first
    first = node;//node is now first
    numNodes++;//increments numNodes
  }
}


//PRE:LinkedList satisfies CI
//POST:LinkedList has the Node x as the last node
void LinkedList::addToBack(int x) {
  Node* node = new Node();//node to store x
  node->setData(x);//storing x in node
  if(numNodes == 0) {//no nodes
    first = node;//first and last are this node
    last = node;
    numNodes++;//increment numNodes
  }
  else {//nodes exist
    last->setNext(node);//last points forward to node
    node->setPrev(last);//node points back to last
    last = node;//node is now last
    numNodes++;//increments numNodes
  }
}

//PRE:LinkedList satisfies CI
//POST:LinkedList contains all original nodes except last one
void LinkedList::deleteBack(){
  if(numNodes == 1) {//there is one node
    delete last;//last node is deleted
    first = NULL;//first and last are null
    last = NULL;
  }
  else{
    Node* newLast = last->getPrev();//stores new last's pointer
    newLast->setNext(NULL);//new last's next is null
    last->setPrev(NULL);//last's prev is null
    delete last;//delete last
    last = newLast;//new last is now last
  }
  numNodes--;//decrement numNodes
}

//PRE:LinkedList is a LinkedList with CI satisfied
//POST:returns true if the list contains element X
bool LinkedList::contains(int x){
  bool answer = false;//we assume x is not in LinkedList
  Node* node = first;//pointer to first
  while(node != NULL) {//we have not reached the end
    if(node->getData() == x) {//this node's data is x
      answer = true;
    }
    node = node->getNext();//gets next node
  }
  return answer;
}

//PRE:LinkedList satisfies CI
//POST:LinkedList has node x inserted at int position
void LinkedList::insert(int x, int position){
  Node* xNode;//new node to insert
  xNode->setData(x);//sets new node's data to x
  Node* nodeA = first;//finds the node at position
  int index = 0;//indexes through list
  while(index<=position) {//goes through list till position
    nodeA = nodeA->getNext();//moves through nodes
    index++;//increases index
  }
  Node* nodeB = nodeA->getNext();//reference to node after nodeA
  xNode->setPrev(nodeA);//xNode points back to nodeA
  xNode->setNext(nodeB);//xNode points forward to nodeB
  nodeA->setNext(xNode);//nodeA points forward to xNode
  nodeB->setPrev(xNode);//nodeB points backward to xNode
}


//PRE:LinkedList satisfies CI and contains x
//POST: the position of x is returned and if not found is -1
int LinkedList::position(int x){
  int position = -1;
  Node* node = first;//points to first node
  int index = 0;
  while(node != NULL) {//goes through nodes
    if(node->getData() == x) {//if data is x
      position = index;//this index is position
    }
    index++;
    node = node->getNext();//moves to next node
  }
  return position;
  
}

//PRE:this object is defined
//POST:The dynamic memory allocated for this object is deleted
LinkedList::~LinkedList(){
  delete first;//deletes the first node
}
 
