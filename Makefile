Homework5: Homework5.o compute.o arithmetic.o printEquation.o makeOperators.o numberFunctions.o
	g++ Homework5.o compute.o arithmetic.o printEquation.o makeOperators.o numberFunctions.o -o Homework5
Homework5.o: Homework5.cc makeOperators.h numberFunctions.h
	g++ -c Homework5.cc
compute.o: compute.cc arithmetic.h printEquation.h
	g++ -c compute.cc
arithmetic.o: arithmetic.cc 
	g++ -c arithmetic.cc
printEquation.o: printEquation.cc
	g++ -c printEquation.cc
makeOperators.o: makeOperators.cc compute.h
	g++ -c makeOperators.cc
numberFunctions.o: numberFunctions.cc
	g++ -c numberFunctions.cc
