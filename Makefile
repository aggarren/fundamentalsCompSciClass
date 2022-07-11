Project3: Project3.o functions.o Simulator.o  MyString.o
	g++ Project3.o functions.o Simulator.o  MyString.o -o Project3
Project3.o: Project3.cc functions.h functions.cc Simulator.h Simulator.cc Queue.h LinkedList.h Node.h 
	g++ -c Project3.cc
functions.o: functions.cc functions.h Exception.h Cust.h CustData.h Teller.h Simulator.h Simulator.cc MyString.h MyString.cc LinkedList.h Queue.h Node.h
	g++ -c functions.cc
Simulator.o: functions.cc functions.h Exception.h Cust.h CustData.h Teller.h Simulator.h Simulator.cc Queue.h LinkedList.h Node.h
	g++ -c Simulator.cc
MyString.o: MyString.h MyString.cc
	g++ -c MyString.cc
