
#include <iostream>
// #include 'filename'
// #include <cmath>
using namespace std;
/*
g++ -o F:\c++\same "F:\c++\kattis\greetings.cpp"
F:\c++\same.exe
*/

int main(){
  string s;
  cin >> s;
  // char e = s.at(1)
  int l=s.length();
  // s.begin()
  // s.end()
  char begin =s[0];
  char end =s[l-1];
  string mid=string(2*(l-2), s[1]);
  // string(5, '.')
  // char p =s.begin();
  // cout<<s.begin()<<endl;
  // cout<<p<<endl;
  cout<<begin<<mid<<end<<endl;
  return 0;
}
