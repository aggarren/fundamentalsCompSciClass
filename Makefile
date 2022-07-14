Homework4: Homework4.o compute.o arithmetic.o printEquation.o 
	g++ Homework4.o compute.o arithmetic.o printEquation.o -o Homework4
Homework4.o: Homework4.cc compute.h 
	g++ -c Homework4.cc
compute.o: compute.cc arithmetic.h printEquation.h
	g++ -c compute.cc
arithmetic.o: arithmetic.cc 
	g++ -c arithmetic.cc
printEquation.o: printEquation.cc
	g++ -c printEquation.cc
