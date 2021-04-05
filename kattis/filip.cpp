
#include <iostream>
// #include 'filename'
// #include <cmath>
using namespace std;
/*
g++ -o F:\c++\same "F:\c++\kattis\flip.cpp"
F:\c++\same.exe
*/

int reverse(int n){
  int r=0;
  while(n>0){
    r=10*r+n%10;
    n=n/10;
  }
  return r;
}


int main(){
  int a,b;
  cin >> a >> b;
  // cin >> a;
  // a=2453;
  // cout<<reverse(a);
  int reva=reverse(a);
  int revb=reverse(b);
  cout<<max(reva,revb)<<endl;
  return 0;
}
