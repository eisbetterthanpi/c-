
#include <iostream>
// #include 'filename'
#include <cmath>
using namespace std;
/*
g++ -o F:\c++\same "F:\c++\kattis\zamka.cpp"
F:\c++\same.exe
*/

int digit(int n){
  int c=0;
  // for(int x,x< x++)
  while(n>0){
    c+=n%10;
    n=n/10;
  }
  return c;
}

int main(){
  int l,d,x;
  cin >> l >> d >> x;
  // l=956;
  // x=20;
  int al=l;
  int c=digit(l);
  while(c!=x){
    c=digit(al);
    if(c>x){
      al++;
    }
    else if(c<x){
      al=al+x-c;
    }
    // cout<< al<< ", "<< c<<endl;
  }

  // d=345;
  int ad=d;
  // int c=digit(d);
  c=digit(d);
  while(c!=x){
    c=digit(ad);
    if(c>x){
      ad=ad-c+x;
    }
    else if(c<x){
      ad--;
    }
    // cout<< ad<< ", "<< c<<endl;
  }
  // pow(10);
  // while(){
  //   n
  // }
  // cout<< l<<endl;
  // cout<< digit(l)<<endl;
  cout<< al<<endl;
  cout<< ad<<endl;
  return 0;
}
