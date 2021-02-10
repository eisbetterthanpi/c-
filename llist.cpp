
/*
g++ -o F:\c++\same "F:\nus\y1\CS2040C\assignment\Lab1SimpleLinkedList\Lab1SimpleLinkedList\main.cpp"
g++ -o F:\c++\same "F:\nus\y1\CS2040C\assignment\Lab1SimpleLinkedList\Lab1SimpleLinkedList\simpleIntLinkedList.h"
g++ -o F:\c++\same "F:\nus\y1\CS2040C\assignment\Lab1SimpleLinkedList\Lab1SimpleLinkedList\simpleIntLinkedList.cpp"
g++ -o F:\c++\same "F:\c++\llist.cpp"
F:\c++\same.exe
*/


#include <iostream>
// #include 'filename'
// #include <cmath>
using namespace std;

// stddef.h or cstddef


// #pragma once

class ListNode{
private:
	int _item;
	ListNode *_next;
public:
  ListNode(int n){
  	_item = n;
  	_next = NULL;
  }
	int content(){return _item;}
	friend class List;
};

class List{ //head
private:
	int _size;
	ListNode *_head;
public:
	List(){
		_size = 0;
		_head = NULL;
	}
	// ~List();

  void insert(int n){
  	ListNode *aNewNode = new ListNode(n);
  	aNewNode->_next = _head;
  	_head = aNewNode;
  	_size++;
  }
  void print(){
    ListNode *next = _head;
    while (next!=NULL){
      cout<<next->_item<<", ";
      next=next->_next;
    }
    cout<<endl;
  }
  // https://www.codementor.io/@codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr
	void removeHead(){
  	if (_size > 0) {
  		ListNode *temp = _head;
  		_head = _head->_next;
  		delete temp;
  		_size--;
  	}
  }
  bool exist(int n){
    ListNode *next = _head;
    while (next!=NULL){
      cout<<next->_item<<", ";
      if (next->_item==n){
        return true;
      }
      next=next->_next;
    }
    cout<<endl;
    return false;
  }
  int pop(){
    ListNode *next = _head;
    ListNode *now = _head;
    // while (next!=NULL){
    while (next->_next!=NULL){
      now=next;
      next=next->_next;
    }
    // cout<<next->_item<<"! "<<next._next<<"! "<<endl;
    return next->_item;
    // next->_next = NULL;
    now = NULL;
    delete next;
    _size--;
  }
	// void removeHead(){
  // 	if (_size > 0) {
  // 		ListNode *temp = _head;
  // 		_head = _head->_next;
  // 		delete temp;
  // 		_size--;
  // 	}
  // }
  // List::~List()
  // {
  // 	while (_size != 0)
  // 		removeHead();
  // };

	// int headItem();
  // insert index get(index) remove
};




// class List{
// private:
//   int _size; item *_next;
// public:
//   // List(int s=0, List *n = NULL){
//   //   _size = s;
//   //   _next = n;
//   //   // int *ptr = NULL;
//   //  //    r=r;c=c;
//   // }
//   List(int s=0){ //cart next = NULL
//     _size = s;
//     _next = NULL
//   }
//   // int len(){return _size;}
//   // void append(int val){
//   //   // List cart = new List(val,NULL);
//   //   cart = List(val,NULL);
//   //   // return radius;
//   // }
//   // remove pop reverse
// };
//
// class item{
//   private:
//     int val; item *_next;
//   public:
//     item(int n){
//       val = n;
//       _next = NULL
//     }
// };





int main(){
  // List s= new List();
  // int s= new List();
  // s= new List();
  List s;
  s.insert(3);
  s.insert(5);
  s.insert(9);
  s.insert(7);
  // cout<< s<<endl;//nope
  // cout<< s.content()<<endl;
  // cout<< s.head()<<endl;
  s.print();
  s.pop();
  s.print();
  cout << "Does 9 exist in the list?" << (s.exist(9) ? "Yes" : "No") << endl;
  // s.append(23);
  // s.append(23);
  // cout<<s<<endl;
  return 0;
}
