Homework7: LinkedList.o Node.o Stack.o Homework7.o
	g++ LinkedList.o Node.o Stack.o Homework7.o -o Homework7
LinkedList.o: LinkedList.h LinkedList.cc
	g++ -c LinkedList.cc
Node.o: Node.h Node.cc LinkedList.h
	g++ -c Node.cc
Stack.o: Stack.h Stack.cc LinkedList.h Node.h
	g++ -c Stack.cc
Homework7.o: Homework7.cc Stack.h Node.h LinkedList.h
	g++ -c Homework7.cc
