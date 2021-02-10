#include <iostream>
#include<cmath>
using namespace std;
/*
g++ -o F:\same "F:\sums.cpp"
F:\same.exe
*/

int *sums(int num){
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

// def sums(list,target):
//     if target in list:
//         return [list.index(target)]
//
//     ans,list_sorted=[],[]
//     for i,v in enumerate(list):
//         ans+=[[[i+1],v]] #list of indexes used, value of sum
//         list_sorted+=[[i+1,v]]
//     list_sorted=sorted(list_sorted,key=lambda l:l[1], reverse=True) #[index,value] sorted by value
//
//     for y in list_sorted:
//         for val in ans:
//             if not y[0] in val[0]: #make sure index have not been used
//                 if val[1]+y[1]==target: #target achieved, done!
//                     return sorted(val[0]+[y[0]])
//                 elif val[1]+y[1]<target: #add new possible sum to memory
//                     ans+=[[val[0]+[y[0]],val[1]+y[1]]]

#include <algorithm>
int main() {
  // l,t=[1,2,6,3,17,82,23,234],26    #[3,6] 47?
  // l,t=[1,2,6,3,17,82,23,234],40    #[4,6] 57?
  // l,t=[1,2,6,3,17,82,23,234],23    #[6]

  int l[]={1,2,6,3,17,82,23,234};
  int lsize=sizeof(l)/sizeof(l[0]);
  cout << l<<endl;
  cout << lsize<<endl;
  sort(l, l+lsize);
  // show(l, lsize);

  // int t =26
  // int *ans=sums(l,t);
  // cout << ans<<endl;
  for ( int i = 0; i < lsize; i++ ) {
    // cout <<i<<" "<< l[i]<<endl;
    cout << l[i]<<", ";
  }
  return 0;
}




// def sums(list,target):
//     if target in list:
//         return [list.index(target)]
//
//     ans,list_sorted=[],[]
//     for i,v in enumerate(list):
//         ans+=[[[i+1],v]] #list of indexes used, value of sum
//         list_sorted+=[[i+1,v]]
//     list_sorted=sorted(list_sorted,key=lambda l:l[1], reverse=True) #[index,value] sorted by value
//
//     for y in list_sorted:
//         for val in ans:
//             if not y[0] in val[0]: #make sure index have not been used
//                 if val[1]+y[1]==target: #target achieved, done!
//                     return sorted(val[0]+[y[0]])
//                 elif val[1]+y[1]<target: #add new possible sum to memory
//                     ans+=[[val[0]+[y[0]],val[1]+y[1]]]
//
// l,t=[1,2,6,3,17,82,23,234],26    #[3,6] 47?
// l,t=[1,2,6,3,17,82,23,234],40    #[4,6] 57?
// l,t=[1,2,6,3,17,82,23,234],23    #[6]
// print(sums(l,t))
