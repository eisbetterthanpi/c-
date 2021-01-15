#include <iostream>
using namespace std;
/*
g++ -o F:\date "F:\date.cpp"
F:\date.exe
*/

string date() {
  cout << "day month year:";
  int day, month, year;
  cin >> day >> month >> year; year -= 1900;
  int key[12]={1,4,4,0,2,5,0,3,6,1,4,6};
  // string date[]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
  string date[7]={"saturday","sunday","monday","tuesday","wednesday","thursday","friday"};
  return date[(day+key[month-1]+year+year/4)%7];
}

int main() {

  cout << date();
  return 0;
}



/*

*/
