
#include <iostream>
using namespace std;
/*
g++ -o F:\c++\same "F:\c++\classTtut.cpp"
F:\c++\same.exe
*/


template<class TypeT>
void bubble(TypeT a[], int n){
  int i, j;
  for (i = 0; i<n - 1; i++){
    for (j = i + 1; j<n; j++){
      if (a[i]>a[j]){
        swap(a[i],a[j]);}}}};

// int main(){
//   int n =5;
//   int s[n] = {10, 2,45,1, 30};
//   // int s[3] = (10, 20, 30);
//   // bubble(int s[], int n);
//   bubble(s, n);
//   for (int i = 0; i < n; i++) {
//     cout << s[i] << ", ";
//   }
//   return 0;
// }

/*
add template <class T>
change int to T
classes add <T>

*/
template <class T> class List;

template <class T>
class ListNode{
private:
  T _item;
  ListNode<T> *_next;
public:
  ListNode(T);
  T content() { return _item; };
  friend class List<T>;
  // template<class U> friend class List;
};

template <class T>
class List{
private:
  int _size;
  ListNode<T> *_head;
public:
  List(){
		_size = 0;
		_head = NULL;
	}
  // void List<T>::insertHead(T n){
  void insertHead(T n){
    ListNode<T> *aNewNode = new ListNode<T>(n);
    aNewNode->_next = _head;
    _head = aNewNode;
    _size++;
  }
};

int main(){
  
  return 0;
}



// template <class T>
// class Stack {
// private:
//   List<T> _ll;
// public:
//   void push(T x);
//   T pop();
//   // bool isEmpty();
// };
//
//
// template <class T>
// void Stack<T>:: push(T x) {
//   _11.insertHead(x);
// }
// template <class T>
// T Stack<T>:: pop() {
//   T item = _11.headItem();
//   _11.remove Head ();
//   return item;
// }
