#include <iostream>
// #include 'filename'
#include <cmath>
using namespace std;
/*
g++ -o F:\c++\same "F:\c++\kattis\height.cpp"
F:\c++\same.exe
*/
// https://open.kattis.com/problems/height
void print(int* s){
  for(int i=0;i<20;i++){
    cout<<s[i]<<" ";
  }
  cout<<endl;
}

// bool comp(int a, int b) return (a < b);
// bool comp(int a, int b) return a < b;

int main(){
  int k;
  cin >>k;
  int s[20];
  for(int j=0;j<k;j++){
    for(int i=0;i<20;i++){
      int s[20];
      cin >>s[i];
      }
    print(s);
    }
    // for(int j=0;j<20;j++){
    //   // min_element(s, s+1, comp)
    //   // min(s, s+1)
    // }
  // string ins ="2 1 5 3 4"
  // int s[5]={2, 1, 5, 3, 4};
  // int temp;
  // bool swap=true;
  // // while(swap){
  // while(true){
  //   bool swap=false;
  //   for(int i=0;i<5-1;i++){
  //     if(s[i]>s[i+1]){
  //       temp=s[i];
  //       s[i]=s[i+1];
  //       s[i+1]=temp;
  //       swap=true;
  //       print(s);
  //     }
  //   }
  //   cout<<swap<<endl;
  //   // if(!swap) break;
  //   // break;
  // }

  return 0;
}
