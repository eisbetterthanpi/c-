
#include <iostream>
using namespace std;
/*
g++ -o F:\c++\same "F:\c++\adtree.cpp"
F:\c++\same.exe
*/
template <class T> class BinarySearchTree;

template <class T>
class TreeNode{
private:
  T _item;
  TreeNode<T>* _left;
  TreeNode<T>* _right;
  int _height;
public:
  TreeNode(T x){
    _left = _right = NULL;
    _item = x;
    _height = 0;
  }
    friend class BinarySearchTree<T>;
    // friend class BinarySearchTree;
};



template <class T>
class BinarySearchTree{
private:
	// int _size;
  TreeNode<T>* _root;
public:
  BinarySearchTree(){_root = NULL; }
  void insert(TreeNode<T>* current, T x){
    if (current->_item > x) {
      if (current->_left)
        current-> _left = insert(current-> left, x);
      else current->_left = new TreeNode<T>(x); }
    else if (x > current->_item) {
      if (current->_right)
        current-> _right = insert(current-> _right, x);
      else current->_right = new TreeNode<T>(x); }
  }
  void insert(T){
	// 	// ListNode<T> *aNewNode = new ListNode<T>(n);
  // 	ListNode<T> *aNewNode = new ListNode<T>(n);
  // 	aNewNode->_next = _head;
  // 	_head = aNewNode;
  // 	_size++;
  }
};

int main(){

  return 0;
}
