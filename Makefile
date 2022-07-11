Project2:  Airline.o Airport.o Flight.o Project2.o inputFunctions.o functions.o MergeSort.o
	g++ Airline.o Airport.o Flight.o Project2.o inputFunctions.o functions.o MergeSort.o -o Project2
functions.o: functions.h functions.cc Airport.h Flight.h Airline.h constants.h
	g++ -c functions.cc
inputFunctions.o: inputFunctions.h inputFunctions.cc Airport.h Flight.h Airline.h constants.h
	g++ -c inputFunctions.cc
MergeSort.o: MergeSort.h MergeSort.cc Airport.h Airline.h
	g++ -c MergeSort.cc
Airport.o: Airport.h Airport.cc Flight.h Airline.h constants.h
	g++ -c Airport.cc
Airline.o: Airline.h Airline.cc Airport.h Flight.h constants.h
	g++ -c Airline.cc
Flight.o: Flight.h Flight.cc Airport.h Airline.h constants.h
	g++ -c Flight.cc
Project2.o: Project2.cc functions.h functions.cc inputFunctions.cc inputFunctions.h
	g++ -c Project2.cc
