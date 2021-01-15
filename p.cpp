#include <iostream>
#include<cmath>
using namespace std;
/*
g++ -o F:\p "F:\p.cpp"
F:\p.exe
*/

int *p(int num){
    int n = num;
    int f=2;
    int ta=log2(num);
    int *s = new int[ta]; //for array to be returned, only these 2 ways to declare?
    // static int s[10];
    int i=0;
    while (f<=(pow(num,0.5))) {
        if (n%f==0){
            s[i]=f;
            i++;
            n=n/f;}
        else{f++;}
    }
    s[i]=n;
    return s;
}

int main() {
  int n=8075;
  // int s[10]={4,5,6};
  // int s[10];
  // int s[]; //error: storage size of 's' isn't known

  int *ans=p(n);
  cout << ans<<endl;
  for ( int i = 0; i < 10; i++ ) {
    cout <<i<<" "<< ans[i]<<endl;
  }
}
