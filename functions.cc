#include "Exception.h"
#include "Cust.h"
#include "CustData.h"
#include "Teller.h"
#include "Simulator.h"
#include "MyString.h"
#include <iostream>
#define debug "d"
#define sim "s"
#define EOS '\0'
using namespace std;
#include <fstream>
//PRE:teller array is defined with noTellers
//POST: returns true if all queues are empty and false otherwise
bool allEmpty(Teller* * tellers, int noTellers){
  bool answer = true; //assume all are empty
  int i = 0;
  while(i<noTellers) {
    if(tellers[i]->getServing() == NULL) {//this teller is serving a customer
      answer = false;
    }
    if(!tellers[i]->getLine()->empty()) {//this teller's line is not empty
      answer = false;
    }
    i++;
  }
  return answer;
}

//PRE:teller array is defined with noTellers
//POST: returns the average of all queue lengths
int allLen(Teller* * tellers, int noTellers){
  int sum = 0;
  for(int i=0; i<noTellers; i++) {
    sum += tellers[i]->getLine()->getNumNodes();
  }
  return sum;
}

//PRE:tellers array is defined with noTellers
//POST: returns the Teller with the shortest queue
Teller* shortestQueue(Teller* * tellers, int noTellers){
  Teller* shortest = NULL;
  for(int i=0; i<noTellers; i++) {
    if(tellers[i]->getLine()->getNumNodes() < shortest->getLine()->getNumNodes() || shortest == NULL) {
      shortest = tellers[i];
    }
  }
  return shortest;
}

//PRE: base and power are defined
//POST: base to the powerth power is returned
int pow(int base, int power) {
  int num = 1;
  int index = 0;
  while(index<power) {
    num *= base;
    index++;
  }
  return num;
}

//PRE:str is a char array
//POST:str is converted into the integer equivalent
int strToInt(char * str) {
  MyString* Str = new MyString(str);
  int max = Str->getSize();
  int num = 0;
  int index=0;
  while(index<max) {
    int integer;
    if(str[index] == '0') { integer = 0; };
    if(str[index] == '1') { integer = 1; };
    if(str[index] == '2') { integer = 2; };
    if(str[index] == '3') { integer = 3; };
    if(str[index] == '4') { integer = 4; };
    if(str[index] == '5') { integer = 5; };
    if(str[index] == '6') { integer = 6; };
    if(str[index] == '7') { integer = 7; };
    if(str[index] == '8') { integer = 8; };
    if(str[index] == '9') { integer = 9; };
    num += integer*pow(10,max-index);
    index++;
  }
  num = num/10;
  return num;
}

//PRE: integer is an int
//POST: integer is converted into the char equivalent
char intToStr(int integer) {
  char character;
  if(integer == 0) { character = '0'; };
  if(integer == 1) { character = '1'; };
  if(integer == 2) { character = '2'; };
  if(integer == 3) { character = '3'; };
  if(integer == 4) { character = '4'; };
  if(integer == 5) { character = '5'; };
  if(integer == 6) { character = '6'; };
  if(integer == 7) { character = '7'; };
  if(integer == 8) { character = '8'; };
  if(integer == 9) { character = '9'; };
  return character;
}

//PRE: filename is defined
//POST: pSim is populated with data from file is error is false
void populateSim(char * data, Simulator& pSim, bool error) {
  cout << "populating simulation" << endl;
  ifstream inFile(data);
  if(inFile.is_open()) {
    int duration;
    inFile >> duration;
    if(duration > 0) {
      pSim.setDuration(duration);
    }
    else {//duration is 0 or less
      Exception E((char *)"duration must be greater than 0");
      error = true;
    }
    int numTellers;
    inFile >> numTellers;
    if(numTellers > 0) {
      pSim.setTellers(numTellers);
    }
    else {//numTellers is 0 or less
      Exception E1((char *)"number of tellers must be greater than 0");
      error = true;
    }
    cout << "making customers" << endl;
    while(!cin.eof()) {
      Cust* customer = new Cust();
      int arrival;
      inFile >> arrival;
      if(arrival > 0) {
	customer->setArrival(arrival);
      }
      else {//arrival is 0 or less
	Exception E2((char *)"customer arrival must be greater than 0");
	error = true;
      }
      int service;
      inFile >> service;
      if(service > 0) {
	customer->setService(service);
      }
      else {//service is 0 or less
	Exception E3((char *)"service time must be greater than 0");
	error = true;
      }
      cout << "adding cust" << endl;
      pSim.addCust(customer);
    }
    inFile.close();
  }
  else {
    Exception e0((char *)"no file named data");
    error = true;
  }

}


//PRE: argc defined, argv[0]...arg[argc+1]
//POST: error True iff arguments false
//if any correct, pSim populated
void prepareSim(int argc, char * argv[], bool& error, Simulator &pSim){
  error = false;
  if(argc>1) {
    cout << "preparing simulator" << endl;
    MyString argv1(argv[1]);//make MyString object for argv[1]
    MyString Debug((char *)debug);//make MyString object for d
    MyString Simulation((char *)sim);//make MyString object for s
    
    if(argv1 == Debug) {//debug mode
      cout << "debug mode" << endl;
      if(argc == 3) {//three arguments
	populateSim(argv[2],pSim,error);
      }
      else {//argc != 3
	Exception e((char *)"wrong number of arguments");
	error = true;
      }
    }
    if(argv1 == Simulation) {//simulation mode
      cout << "simulation mode" << endl;
      if(argc == 5) {//five arguments
	int numIter = strToInt(argv[2]);//number of iterations is the second argument
	pSim.setIter(numIter);
	int duration = strToInt(argv[3]);//number of duration is the third argument
	pSim.setDuration(duration);
	int tellers = strToInt(argv[4]);//number of tellers is the fourth argument
	pSim.setTellers(tellers);
      }
      else {//argc != 5
	Exception e1((char *)"wrong number of arguments");
	error = true;
      }
    }
    else {//argv[1] != s or d
      Exception e2((char *)"please enter d or s as argument 1");
      error = true;
    }
  }
}
                                                                                                                                                                                                                                                                                                                                                                                                   CPSC170/Projects/aggarren-Project3/Simulator.cc                                                     0000664 0014416 0014416 00000031750 14232107075 021547  0                                                                                                    ustar   aggarren                        aggarren                                                                                                                                                                                                               #include "Simulator.h"
#include "CustData.h"
#include "Cust.h"
#include "functions.h"
#include "MyString.h"
#include "Teller.h"
#include "stdlib.h" //library for random number generator
#include <fstream>
#define MAX 100
#include <iostream>
using namespace std;
//PRE:Simulator is declared and seed is either 0 or -1
//POST: Simulator is populated with data from random num generator and returns total num of custs
int Simulator::makeData(int seed){
  int totalCusts = 0;
  if(seed != -1) {
    cout << "enter a positive number" << endl;
    cin >> seed;
    srandom(seed);//seed the random number generator
  }
  int unitTime = 1;
  while(unitTime <= duration) {//customers created for each unitTime
    int probability = random() % 100 +1;
    int numCusts;
    if(probability <=50) {
      numCusts = 0;
    }
    if(probability >50 && probability <=90) {
      numCusts = 1;
      totalCusts += 1;
    }
    if(probability > 90 && probability <=97) {
      numCusts = 2;
      totalCusts += 2;
    }
    if(probability > 97 && probability <=100) {
      numCusts = 3;
      totalCusts += 3;
    }
    int index = 0;
    while(index < numCusts) {//number made is less than decided number of customers
      Cust* customer = new Cust();
      customer->setArrival(unitTime);//customer comes at this unitTime
      int service;
      service = (random() % 10 + 1)/2;
      customer->setService(service);
      addCust(customer);
      index++;
    }
    unitTime++;
  }
  return totalCusts;
}
//PRE:data is full of customers with arrivalTime during duration
//POST:Simulation is run and information is added to output file and outputted in OS
void Simulator::run(){
  Teller* * tellerArray1;
  Teller* * tellerArray2;
  //[] position 0 is teller 1, position 1 is teller 2, etc
  tellerArray1 = new Teller*[noTellers];
  tellerArray2 = new Teller*[noTellers];
  for(int a=0; a<noTellers;a++) {
    tellerArray1[a] = new Teller();
    tellerArray2[a] = new Teller();
  }
  //optimal output
  int optWait = -1;//optimal wait time
  int optTellersWait = -1;//teller number for optWait
  int optMethodWait = -1;//method number for optWait
  int optLen = -1;//optimal length of queue
  int optTellersLen = -1;//teller number for optTeller
  int optMethodLen = -1;//method number for optLen

  //for teller-i averages outputs
  int sumWait1 = 0;//to compute the average wait for Method1
  int sumLength1 = 0;//to compute the average length for Method1
  int sumNumCusts1 = 0;//to compute the average wait for Method1
  int sumWait2 = 0;//to compute the average wait for Method2
  int sumLength2 = 0;//to compute the average length for Method2
  int sumNumCusts2 = 0;//to compute the average wait for Method2
  
  int totalCusts = 0; //keeps track of total number of customers for this run
  int numCusts = 0;//number of customers for this iteration
  int totalTime = 0;
  int tellers = noTellers;
  while(tellers > 0) {//goes through having each number of tellers
    int itersDone = 1;//zero iterations done
    while(itersDone < iter) {//goes through several iterations
      if(itersDone == 1) {//first iteration
	numCusts = makeData(0);//need to seed the random number generator
      }
      else {//not first iteration
	numCusts = makeData(-1); //make new customers and keep note of number of them
      }
      totalCusts += numCusts;//add number of customers to total
      cout << "making data with " << numCusts << " number of customers" << endl;
      //METHOD 1
      cout << "METHOD 1" << endl;
      int tellers = noTellers;//number of tellers
      
      //averages output for optimization
      int sumTime = 0;//total time used
      int sum = 0;//total amount waited
      int mainLen = 0; //mainQueue's length
      int sumLen = 0; //sum of mainQueue's length at the end of each unitTime
      
      CustData* data1; //copy of data for first method
      data1 = data;
      CustData* mainQueue = data;
      bool done = false; //denotes when we are done
      int unitTime = 1;//start at unitTime of 1
      sumNumCusts1 += numCusts; //add number of customers to the number for this teller
      while(!done) {
	//move customers from data to mainQueue
	while(data1->top()->getArrival() == unitTime) {//the next customer has this time
	  cout << "adding to main queue at " << unitTime << endl;
	  mainQueue->push(getNextCust()); //add this customer to the main queue
	  mainLen++;
	  data1->pop(); //remove this customer from data
	}
	//move finished customers along and get Tellers new customers
	for(int i=0; i<noTellers; i++) {//goes through all tellers
	  Cust* customer = tellerArray1[i]->getServing();//the customer this teller is serving
	  if(customer != NULL) {//the customer is not null
	    if(customer->getService() + customer->getServed() == unitTime) {//this customer is done
	      totalTime += customer->getService(); //add to total time served
	      sum += unitTime - mainQueue->top()->getArrival(); //add to the sum the wait time for the next customer
	      sumWait1 += unitTime - mainQueue->top()->getArrival(); //add to the wait for the next customer
	      tellerArray1[i]->setServing(mainQueue->top());//teller is serving the next customer
	      mainQueue->top()->setServed(unitTime);
	      cout << "teller " << i << " is serving customer at time " << unitTime << endl;
	      mainQueue->pop();//customer leaves mainQueue line
	      mainLen--;
	    }
	  }
	  else {//customer is null
	    if(!mainQueue->empty()){//main queue is not empty
	      tellerArray1[i]->setServing(mainQueue->top());//teller is serving next in line
	      mainQueue->top()->setServed(unitTime);
	      cout << "teller " << i << " is serving customer at time " << unitTime << endl;
	      mainQueue->pop();//customer leaves line
	    }
	    else {//main queue is empty
	      tellerArray1[i]->incIdling();
	    }
	  }
	}
	
	if(unitTime >= duration) {//we are done if mainQueue is empty and unitTime is more than or equal to the duration
	  done = true;
	}
	else {//mainQueue is not empty
	  sumLen += mainLen; //add the queue's length to the sum
	  sumLength1 += mainLen; //add the queue's length to the sum for using this many tellers
	}
	unitTime++;//a unit of time has passed
	sumTime++;
      }
       //calculte optimal waits and lengths
      int avgLen = sumLen / itersDone; //average queue length
      int avgWait = sum / numCusts; //average wait time
      int avgDur = sumTime / itersDone;//average duration
      if((optWait == -1 || avgWait < optWait) || (avgWait == optWait && tellers < optTellersWait)) {//this is optimal wait time or optimal tellers if equivalent
	optWait = avgWait;
	optTellersWait = tellers;
	optMethodWait = 2;
      }
      if(optLen == -1 || avgLen < optLen || (avgWait == optWait && tellers < optTellersWait)) {//this is optimal length of queue or optimal tellers if equivalent
	optLen = avgLen;
	optTellersLen = tellers;
	optMethodLen = 2;
      }
    
      //METHOD 2
      cout << "METHOD 2" << endl;
      int len = 0;//for calculating optimal length
      if(tellers > 1) {//do all number of tellers except when there's one
	//averages output for optimization
	int sumTime = 0;//total time used
	int sum = 0;//total amount waited
	int count = 0;//number of customers
	int mainLen = 0; //mainQueue's length
	int sumLen = 0; //sum of mainQueue's length at the end of each unitTime
	CustData* data2; //copy of data for second method
	data2 = data;
	int unitTime = 1;
	itersDone = 1;//zero iterations done
	sumNumCusts2 += numCusts; //add number of customers to the number for this teller
	bool done = false;
	while(!done) {
	  //move customers from data to shortest queue
	  while(data2->top()->getArrival() == unitTime) {//the next customer has this time
	    cout << "adding to teller queue at time " << unitTime << endl;
	    Teller* teller = shortestQueue(tellerArray2,tellers);
	    teller->addLine(getNextCust()); //add this customer to the main queue
	    len++;
	    data2->pop(); //remove this customer from data
	  }
	  //move finished customers along and get Tellers new customers
	  for(int i=0; i<noTellers; i++) {//goes through all tellers
	    Cust* customer = tellerArray2[i]->getServing();//the customer this teller is serving
	    if(customer != NULL) {//the customer is not null
	      if(customer->getService() + customer->getServed() == unitTime) {//this customer is done
		totalTime += customer->getService(); //add to total time served
		count++; //increase count of customers served
		sum += unitTime - tellerArray2[i]->getNext()->getArrival(); //add to the sum the wait time for the next customer
		sumWait2 += unitTime - tellerArray2[i]->getNext()->getArrival();//add to the wait for the next customer
		cout << "teller " << i << " is serving customer at time " << unitTime << endl;
		tellerArray2[i]->setServing(tellerArray2[i]->getNext());//teller is serving next customer
		tellerArray2[i]->getNext()->setServed(unitTime);
		tellerArray2[i]->popServing();//customer leaves this teller's line
		mainLen--;
	      }
	    }
	    else {//customer is null
	      if(!tellerArray2[i]->getLine()->empty()){//queue is not empty
		cout << "teller " << i << " is serving customer at time " << unitTime << endl;
		tellerArray2[i]->setServing(tellerArray2[i]->getNext());//teller is serving next in line
		tellerArray2[i]->getNext()->setServed(unitTime);
		tellerArray2[i]->popServing();//customer leaves this teller's line
	      }
	      else {//main queue is empty
		tellerArray2[i]->incIdling();
	      }
	    }
	  }
	  if(allEmpty(tellerArray2,tellers) && unitTime >= duration) {//we are done if all queues are empty and unitTime is more than or equal to the duration
	    done = true;
	  }
	  else {//one queue is not empty
	    sumLen += allLen(tellerArray2,tellers); //add the all queue lengths to the sum
	    sumLength2 += allLen(tellerArray2,tellers); //add to the average queue length for this number of tellers
	  }
	  unitTime++;//a unit of time has passed
	  sumTime++;
	}
     
	int avgLen = sumLen / iter; //average queue length
	int avgWait = sum / count; //average wait time
	if((optWait == -1 || avgWait < optWait) || (avgWait == optWait && tellers < optTellersWait)) {//this is optimal wait time or optimal tellers if equivalent
	  optWait = avgWait;
	  optTellersWait = tellers;
	  optMethodWait = 2;
	}
	if(optLen == -1 || avgLen < optLen || (avgWait == optWait && tellers < optTellersWait)) {//this is optimal length of queue or optimal tellers if equivalent
	  optLen = avgLen;
	  optTellersLen = tellers;
	  optMethodLen = 2;
	}
    
      }
      itersDone++;
    }

    MyString* title = new MyString((char *)"Teller-");
    title->append(intToStr(tellers));
    title->append('.');title->append('r');title->append('e');title->append('s');
    title->append('u');title->append('l');title->append('t');title->append('s');
    ofstream outFile;
    outFile.open(title->getTheString());
    //add following to file: Teller-i : where i=tellers      
    outFile << "Method 1: " << endl << "-----" << endl;
    outFile << "Average waiting time per customer: " << sumWait1 / totalCusts << endl;//average waiting time is sum of waiting times divided by number of customers for this number of tellers
    outFile << "Average queue length: " << sumLength1 / tellers << endl;//average queue length is sum of lengths divided by number of tellers for this number of tellers
    for(int k=0; k<noTellers; k++) {
      outFile << "Teller " << k << ": " << endl;
      outFile << "Average no. of customers served: " << tellerArray1[k]->getnumServed()/iter << endl;
      outFile << "Average idle time: " << tellerArray1[k]->getIdling()/iter << endl;
    }
      
    outFile << "Method 2: " << endl << "-----" << endl;
    outFile << "Average waiting time per customer: " << sumWait2 / totalCusts << endl;//average waiting time is sum of waiting times divided by number of customers for this number of tellers
    outFile << "Average queue length: " << sumLength2 / noTellers << endl;//average queue length is sum of lengths divided by number of tellers for this number of tellers
      
    for(int j=0; j<noTellers; j++) {
      outFile << "Teller " << j << ": " << endl;
      outFile << "Average no. of customers served: " << tellerArray2[j]->getnumServed()/iter << endl;
      outFile << "Average idle time: " << tellerArray2[j]->getIdling()/iter << endl;
    }
     
    tellers--;
  }
  
  //output into OS
  cout << endl;
  cout << "Optimal average waiting time: " << optWait << endl;
  cout << "No. of tellers: " << optTellersWait << endl;
  cout << "Method " << optMethodWait << endl;
  cout << endl;
  cout << "Optimal average queue length: " << optLen << endl;
  cout << "No. of tellers: " << optTellersLen << endl;
  cout << "Method " << optMethodLen << endl;

  ofstream OutFile;
  OutFile.open((char *)"Customers.results"); 
  //add to Customers.results
  OutFile << endl;
  OutFile << "No. of iterations: " << iter << endl;
  OutFile << "Simulation Duration: " << duration << endl;
  OutFile << "Average Simulation Time: " << totalTime / iter << endl;
  OutFile << "Average number of customers served: " << totalCusts*2 / iter << endl;
  OutFile << "Average service time for customers: " <<  totalTime / totalCusts*2 << endl;


  delete tellerArray1;
  delete tellerArray2;

}            
