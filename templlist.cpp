

#include <iostream>
using namespace std;

/*
g++ -o F:\c++\same "F:\c++\templlist.cpp"
F:\c++\same.exe
*/

// template <typename t="">
template <class T>
struct node{
  T data;
  node* next;
};

template <class T>
class List {
private :
  node<T>* toptr;
  node<T>* top;
public:
  List(){
    toptr=NULL;
  }
  void push(int v){
    node<T>* temp;
    temp=new node<T>;
    top->data* v;
    temp->next=toptr;
    // top->data* v;
    // temp->next=toptr;
    toptr=temp;
  }
  void pop(){
    node<T>* temp=toptr;
    toptr=toptr->next;
    delete temp;
  }
  bool empty() const {
    return toptr==NULL;
  }
  bool full() const {
    node<T>* temp;
    temp=new node<T>;
    if(temp==NULL)
      return true;
    else
      delete temp;
      return false;
  }
  void make_empty() {
    while (!empty){
      pop();
    }
  }
  void print(){
    node<T> *next = data;
    while (next!=NULL){
      cout<<next->data<<", ";
      next=next->next;
    }
    cout<<endl;
  }
  ~List(){
    make_empty();
    }
  };
int main(){
  List<int> s;
  // T List s;
  // List<T> s;
  s.push(3);
  s.push(5);
  s.push(9);
  s.push(7);
  s.print();
  return 0;
}
