#ifndef INCLUDED_SIMULATOR
#define INCLUDED_SIMULATOR
#include "Cust.h"
#include "CustData.h"
class Simulator {
 private:
  int duration;
  int noTellers;
  int iter;
  CustData* data;
 public:
  Simulator() { data = new CustData();};
  void setDuration(int dur) { duration = dur; };
  void setTellers(int num) { noTellers = num; };
  void setIter(int iters) { iter = iters; };
  int getDuration() { return duration; };
  int getTellers() { return noTellers; };
  int getIter() { return iter; };
  void addCust(Cust* customer) { data->push(customer); };
  Cust* getNextCust() { return data->top(); };
  void popCust() { data->pop(); };
  bool emptyCust() { return data->empty(); };
  
  //PRE:Simulator is declared
  //POST: Simulator is populated with data from random num generator and returns total num of custs
  int makeData(int seed);

  //PRE:data is full of customers with arrivalTime during duration
  //POST:Simulation is run and information is added to output file and outputted in OS
  void run();

  ~Simulator() { delete data; };
};
#endif
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  CPSC170/Projects/aggarren-Project3/LinkedList.h                                                     0000664 0014416 0014416 00000014755 14232021240 021467  0                                                                                                    ustar   aggarren                        aggarren                                                                                                                                                                                                               #ifndef INCLUDED_LIST
#define INCLUDED_LIST
#include "Node.h"
#include <iostream>
using namespace std;
//CI:first's prev is null and last's next is null and numNodes is number of nodes in list
template <class T>
class LinkedList {
 protected:
  Node<T> * first;  // pointer to the first node, if any, in this linked
		 // list object  
  Node<T> * last;   // pointer to the last node, if any, in this linked
       	 // list object 
  int numNodes;  // number of nodes in this object.

 public:
//PRE:
//POST:first and last are null, numNodes = 0
LinkedList() {
  numNodes = 0;//numNodes is set to 0
  first = last = NULL;//first and last are null
 };

//PRE:pList is defined and last's next is NULL
//POST: this object is a deep copy of pList
LinkedList(const LinkedList & pList){
  first = last = NULL;
  numNodes = 0;
  Node<T>* node = pList.first;
  while(node != NULL) {
    Node<T> * newNode = new Node<T>(node->getData());
    addToBack(newNode);
    node = node->getNext();
  }
 };

//PRE: the implicit and explicit parameters are LinkedLists
//POST: this object is a deep copy of pLL
 LinkedList& operator=(const LinkedList& pLL){
  first = last = NULL;
  numNodes = 0;
  Node<T>* node = pLL.first;
  while(node != NULL) {
    Node<T> * newNode = new Node<T>(node->getData());
    addToBack(newNode);
    node = node->getNext();
  }
 };

//PRE: the implicit and explicit parameters are LinkedLists
//POST: this object is a deep copy of pLL
bool operator==(const LinkedList& pLL) {
  bool answer = true;
  bool done = false;
  Node<T>* node = first;
  Node<T>* pNode = pLL.first;
  while(!done) {
    if(!(node->getData() == pNode->getData())) {
      answer = false;
    }
    if(node->getNext() == NULL && pNode->getNext() != NULL) {
      answer = false;
    }
    if(node->getNext() != NULL && pNode->getNext() == NULL) {
      answer = false;
    }
    if(node->getNext() == NULL && pNode->getNext() == NULL) {
      done = true;
    }
  }
  return answer;
};

 int getNumNodes() { return numNodes; };

 
//PRE:LinkedList satisfies CI
//POST: returns first
Node<T>* getFirst(){
  return first;
 };
  
//PRE:LinkedList satisfies CI
//POST: returns last
Node<T>* getLast(){
  return last;
 };

//PRE:LinkedList satisfies CI
//POST: first is Node x
void setFirst(Node<T>* x){
  first = x;
};
  
//PRE:LinkedList satisfies CI
//POST: last is Node x
void setLast(Node<T>* x){
  last = x;
};
  
//PRE:LinkedList satisfies CI
//POST:LinkedList's nodes' integers  are printed in OS
void print(){
  if(first != NULL) {//prints the first node if not null
    first->print();
  }
};
//PRE:LinkedList satisfies CI
//POST:LinkedList contains all original nodes except first one
void deleteFront() {
  if(numNodes == 1) {//one node
    delete first;//deletes first node
    first = NULL;//first and last are null
    last = NULL;
  }
  else {//more than one node
    Node<T>* newFirst = first->getNext();//second node is newFirst
    newFirst->setPrev(NULL);//newFirst's prev is null
    first->setNext(NULL);//first's next is null
    delete first;//first node is deleted
    first = newFirst;//newFirst is the new first
  }
  numNodes--;//numNodes decrements
};

//PRE:LinkedList satisfies CI
//POST:LinkedList has the Node x as the first node
void addToFront(T* x) {
  Node<T>* node = new Node<T>();//node to store x
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
};


//PRE:LinkedList satisfies CI
//POST:LinkedList has the Node x as the last node
void addToBack(T* x) {
  Node<T>* node = new Node<T>();//node to store x
  node->setData(x);//storing x in node
  if(numNodes == 0) {//no nodes
    first = node;//first and last are this node
    last = node;
    first->setPrev(NULL);
    last->setNext(NULL);
    numNodes++;//increment numNodes
  }
  else {//nodes exist
    last->setNext(node);//last points forward to node
    node->setPrev(last);//node points back to last
    last = node;//node is now last
    last->setNext(NULL);
    numNodes++; //increments numNodes
  }
};

//PRE:LinkedList satisfies CI
//POST:LinkedList contains all original nodes except last one
void deleteBack(){
  if(numNodes == 1) {//there is one node
    delete last;//last node is deleted
    first = NULL;//first and last are null
    last = NULL;
  }
  else{
    Node<T>* newLast = last->getPrev();//stores new last's pointer
    newLast->setNext(NULL);//new last's next is null
    last->setPrev(NULL);//last's prev is null
    delete last;//delete last
    last = newLast;//new last is now last
  }
  numNodes--;//decrement numNodes
};

//PRE:LinkedList is a LinkedList with CI satisfied
//POST:returns true if the list contains element X
bool contains(T* x){
  bool answer = false;//we assume x is not in LinkedList
  Node<T>* node = first;//pointer to first
  while(node != NULL) {//we have not reached the end
    if(node->getData() == x) {//this node's data is x
      answer = true;
    }
    node = node->getNext();//gets next node
  }
  return answer;
};

//PRE:LinkedList satisfies CI
//POST:LinkedList has node x inserted at int position
void insert(T* x, int position){
  Node<T>* xNode;//new node to insert
  xNode->setData(x);//sets new node's data to x
  Node<T>* nodeA = first;//finds the node at position
  int index = 0;//indexes through list
  while(index<=position) {//goes through list till position
    nodeA = nodeA->getNext();//moves through nodes
    index++;//increases index
  }
  Node<T>* nodeB = nodeA->getNext();//reference to node after nodeA
  xNode->setPrev(nodeA);//xNode points back to nodeA
  xNode->setNext(nodeB);//xNode points forward to nodeB
  nodeA->setNext(xNode);//nodeA points forward to xNode
  nodeB->setPrev(xNode);//nodeB points backward to xNode
};


//PRE:LinkedList satisfies CI and contains x
//POST: the position of x is returned and if not found is -1
int position(int x){
  int position = -1;
  Node<T>* node = first;//points to first node
  int index = 0;
  while(node != NULL) {//goes through nodes
    if(node->getData() == x) {//if data is x
      position = index;//this index is position
    }
    index++;
    node = node->getNext();//moves to next node
  }
  return position;
  
};

//PRE:this object is defined
//POST:The dynamic memory allocated for this object is deleted
~LinkedList(){
  delete first;//deletes the first node
 };
  
};
#endif
                   CPSC170/Projects/aggarren-Project3/Project3.cc                                                      0000640 0014416 0014416 00000000571 14232060570 021246  0                                                                                                    ustar   aggarren                        aggarren                                                                                                                                                                                                               #include "functions.h"
#include "Simulator.h"
#include "Exception.h"
int main(int argc, char * argv[]) {
  Simulator sim;
  bool error = false;
  try {
    cout << "trying" << endl;
    prepareSim(argc,argv,error,sim);
  }
  catch(Exception e) {
    cout << "catching" << endl;
    e.handle();
  }
  if(!error) {
    cout << "running" << endl;
    sim.run();
  }
  return 0;
}
