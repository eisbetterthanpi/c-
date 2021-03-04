
#include <iostream>
using namespace std;
/*
g++ -o F:\c++\same "F:\c++\llistT.cpp"
F:\c++\same.exe
*/

template <class T> class List;

template <class T>
class ListNode{
private:
	T _item;
	ListNode<T> *_next;
public:
  ListNode(T n){
		_item = n;
  	_next = NULL;
  }
	T content(){return _item;}
	friend class List<T>;
};

template <class T>
class List{ //head
private:
	int _size;
	ListNode<T> *_head;
public:
	List(){
		_size = 0;
		_head = NULL;
	}
  void insert(T n){
  	ListNode<T> *aNewNode = new ListNode<T>(n);
  	aNewNode->_next = _head;
  	_head = aNewNode;
  	_size++;
  }
  void print(){
    ListNode<T> *next = _head;
    while (next!=NULL){
      cout<<next->_item<<", ";
      next=next->_next;
    }
    cout<<endl;
  }
	void removeHead(){
  	if (_size > 0){
  		ListNode<T> *temp = _head;
  		_head = _head->_next;
  		delete temp;
  		_size--;
  	}
  }
	void reverseOp(){
		ListNode<T> *temp = _head;
		ListNode<T> *now = _head;
		ListNode<T> *prev=NULL;
		for (int i = 1; i <= _size; ++i) {
			temp=temp->_next;
			now->_next=prev;
			prev=now;
			now=temp;
		}
		_head=prev;
	}
  bool exist(T n){
    ListNode<T> *next = _head;
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
	T max(){
		int k;
    ListNode<T> *next = _head;
    while (next!=NULL){
      cout<<next->_item<<", ";
      if (next->_item>k){
				k=next->_item;
      }
      next=next->_next;
    }
    return k;
  }
  T pop(){
    ListNode<T> *next = _head;
    ListNode<T> *now = _head;
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
	T len(){
		return _size;
	}
  ~List(){
  	while (_size != 0){
  		removeHead();
		}
  }
};


int main(){
	List<int> s;

  s.insert(3);
  s.insert(5);
  s.insert(9);
  s.insert(7);
	s.print();

	s.removeHead();
	s.print();
	s.reverseOp();
	s.print();
	cout<<s.max()<<endl;
	cout<<s.len()<<endl;
  cout << "Does 9 exist in the list?" << (s.exist(9) ? "Yes" : "No") << endl;
  return 0;
}
