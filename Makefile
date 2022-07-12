Homework6: stringFunctions.o MyString.o useStrings.o StringList.o
	g++ stringFunctions.o MyString.o useStrings.o StringList.o -o Homework6
stringFunctions.o: stringFunctions.cc stringFunctions.h constants.h StringList.h
	g++ -c stringFunctions.cc
MyString.o: MyString.cc MyString.h stringFunctions.h constants.h
	g++ -c MyString.cc
useStrings.o: StringList.h MyString.h stringFunctions.h
	g++ -c useStrings.cc
StringList.o: StringList.cc StringList.h stringFunctions.h MyString.h constants.h
	g++ -c StringList.cc
