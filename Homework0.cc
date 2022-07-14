#include <iostream>
using namespace std;
//PRE: IS contains a number, year
//POST: if the year is a leap year, contains message indicating so, otherwise message indicates not

int main () {
  int year;
  cout << "Enter year: ";
  cin >> year;

  bool leapYear; //true iff the input year is a leap year
  if(year > 0) {
  if(year % 4 == 0 and year % 100 != 0) {
    leapYear == true;
    cout << "Leap year" << endl;
  }
  if((year % 4 == 0) and (year % 100 == 0) and (year % 400 == 0)) {
      leapYear == true;
      cout << "Leap year" << endl;
  }
  else {
    leapYear == false;
    cout << "Not a leap year" << endl;
  }
  }
  else {
    cout << "Invalid year";
  }
  //ASSERT: leapYear = true iff year is a leap year
  return (0);
}
 
