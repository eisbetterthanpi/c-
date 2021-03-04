
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
  // int _height;
  int _weight;
public:
  TreeNode(T x){
    _left = _right = NULL;
    _item = x;
    // _height = 0;
    _weight = 0;
  }
    friend class BinarySearchTree<T>;
};

template <class T>
class BinarySearchTree{
private:
	// int _size;
  TreeNode<T>* _root;
public:
  BinarySearchTree(){_root = NULL; }

  TreeNode<T>* _insert(TreeNode<T>* current, T x){ //inserting x
    current-> _weight++;
    if (current->_item > x) {
      if (current->_left){
        current-> _left = _insert(current-> _left, x);}
        else current->_left = new TreeNode<T>(x);
          return current;}
    else if (x > current->_item){
      if (current->_right){
        current-> _right = _insert(current-> _right, x);}
      else {current->_right = new TreeNode<T>(x);
        return current;}
    }
  return current;
  }
  void insert(T x) {
  	if (_root == NULL){
  		_root = new TreeNode<T>(x);}
  	else{
      _root = _insert(_root, x);}
  }




  void _printTree(int indent, TreeNode<T>* node, bool withWeight){
  	if (!node){
  		return;}
  	if (node->_right){
      // cout<<"r"<<indent;
  		_printTree(indent + 2, node->_right, withWeight);}
  	for (int i = 0; i < indent; i++){
  		cout << " ";}
    // cout << node->_item;
  	cout << node->_item<<" "<<indent/2;
  	if (withWeight){
      cout << "(w=" << node->_weight << ")";}
    cout << endl;
    if (node->_left){
      // cout<<"l"<<indent;
      _printTree(indent + 2, node->_left, withWeight);}
  };
  void printTree(bool withWeight=true){_printTree(0, _root, withWeight);}


  void right(TreeNode<T>* p){
    c=p._left
    p._left=c._right
    c._right=p
  }
  void left(TreeNode<T>* p){
    c=p._right
    p._right=c._left
    c._left=p
  }

  TreeNode<T>* balance(TreeNode<T>*){

  }



  void _inOrderPrint(TreeNode<T>* node){
    if (node->_left){
      _inOrderPrint(node->_left);}
    cout << node->_item<<" ";
  	if (node->_right){
  		_inOrderPrint(node->_right);}
  };
  void inOrderPrint(){
    _inOrderPrint(_root);
    cout<<endl;
  }
  void _preOrderPrint(TreeNode<T>* node){
    cout << node->_item<<" ";
    if (node->_left){
      _preOrderPrint(node->_left);}
  	if (node->_right){
  		_preOrderPrint(node->_right);}
  };
  void preOrderPrint(){
    _preOrderPrint(_root);
    cout<<endl;
  }
  void _postOrderPrint(TreeNode<T>* node){
    if (node->_left){
      _postOrderPrint(node->_left);}
  	if (node->_right){
  		_postOrderPrint(node->_right);}
    cout << node->_item<<" ";
  };
  void postOrderPrint(){
    _postOrderPrint(_root);
    cout<<endl;
  }


  // searchMin()
  // searchMax()
  // successor()
};

int main(){

	BinarySearchTree<int> s;

  // s.insert(3);
  // s.insert(5);
  // s.insert(9);
  s.insert(7);
  s.insert(67);
  s.insert(23);
  s.insert(144);
  s.insert(3);
  s.insert(4);
  s.insert(1);

  s.insert(6);
  s.insert(21);
  s.insert(12);
	// s.print();
  s.printTree(true);
  s.inOrderPrint();
  s.preOrderPrint();
  s.postOrderPrint();
  return 0;
}
