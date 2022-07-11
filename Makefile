Project1: Project1.o arrayFunctions.o Dictionary.o guessing.o
	g++ Project1.o arrayFunctions.o Dictionary.o guessing.o -o Project1
Project1.o: Project1.cc arrayFunctions.h Dictionary.h constants.h guessing.h
	g++ -c Project1.cc
arrayFunctions.o: arrayFunctions.cc arrayFunctions.h constants.h
	g++ -c arrayFunctions.cc
guessing.o: guessing.cc arrayFunctions.h constants.h
	g++ -c guessing.cc
