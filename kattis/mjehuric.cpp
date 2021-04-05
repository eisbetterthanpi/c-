
#include <iostream>
// #include 'filename'
#include <cmath>
using namespace std;
/*
g++ -o F:\c++\same "F:\c++\kattis\mjehuric.cpp"
F:\c++\same.exe
*/
// https://open.kattis.com/problems/mjehuric
void print(int* s){
  for(int i=0;i<5;i++){
    cout<<s[i]<<" ";
  }
  cout<<endl;
}

int main(){
  int s[5];
  for(int i=0;i<5;i++){
    cin >>s[i];
  }
  // string ins ="2 1 5 3 4"
  // int s[5]={2, 1, 5, 3, 4};
  int temp;
  bool swap=true;
  while(swap){
    bool swap=false;
    for(int i=0;i<5-1;i++){
      if(s[i]>s[i+1]){
        temp=s[i];
        s[i]=s[i+1];
        s[i+1]=temp;
        swap=true;
        print(s);
      }
    }
    if(!swap) break;
  }

  return 0;
}
