
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
};

template <class T>
class BinarySearchTree{
private:
	int _size;
  TreeNode<T>* _root;
public:
  BinarySearchTree(){_size=0;_root = NULL; }

//simple works
  // TreeNode<T>* _insert(TreeNode<T>* current, T x){ //inserting x
  //   if (current->_item > x) {
  //     if (current->_left){
  //       current-> _left = _insert(current-> _left, x);}
  //       else current->_left = new TreeNode<T>(x);
  //       return current;
  //     }
  //   else if (x > current->_item){
  //     if (current->_right){
  //       current-> _right = _insert(current-> _right, x);}
  //     else {current->_right = new TreeNode<T>(x);
  //     return current;}
  //   }
  // return current;
  // }
  // void insert(T x){
  // 	if (_root == NULL){
  // 		_root = new TreeNode<T>(x);}
  // 	else{
  //     _root = _insert(_root, x);}
  // }

//with size, height
  TreeNode<T>* _insert(TreeNode<T>* current, T x){ //inserting x
    if (current->_item > x) {
      if (current->_left){
        // current->_height++;
        current-> _left = _insert(current-> _left, x);
        if (current-> _left->_height== current->_height){ current->_height++;}
      }
      else{current->_left = new TreeNode<T>(x);
        if (current-> _left->_height== current->_height){ current->_height++;}
        return current;}
    }
    else if (x > current->_item){
      if (current->_right){
        // current->_height++;
        current-> _right = _insert(current-> _right, x);
        if (current-> _right->_height == current->_height){ current->_height++;}
      }
      else {current->_right = new TreeNode<T>(x);
      if (current-> _right->_height == current->_height){ current->_height++;}
      return current;}
    }
    return current;
  }
  void insert(T x){_size++;
    if (_root == NULL){_root = new TreeNode<T>(x);}
  	else{_root = _insert(_root, x);}
  }

  int getheight(){return _root->_height;}

  void _printTree(int indent, TreeNode<T>* node, bool withHeight){
  	if (!node){return;}
  	if (node->_right){_printTree(indent + 2, node->_right, withHeight);}
    for (int i = 0; i < indent; i++){cout << " ";}
    cout << node->_item;
  	if (withHeight){cout << "(h=" << node->_height << ")";}
    cout << endl;
    if (node->_left){_printTree(indent + 2, node->_left, withHeight);}
  };
  void printTree(bool withHeight= true) {
  	_printTree(0, _root, withHeight);}

  void _inOrderPrint(TreeNode<T>* node){
    if (node->_left){_inOrderPrint(node->_left);}
    cout << node->_item<<" ";
  	if (node->_right){_inOrderPrint(node->_right);}};
  void inOrderPrint(){_inOrderPrint(_root);
    cout<<endl;}
  void _preOrderPrint(TreeNode<T>* node){
    cout << node->_item<<" ";
    if (node->_left){_preOrderPrint(node->_left);}
  	if (node->_right){_preOrderPrint(node->_right);}};
  void preOrderPrint(){_preOrderPrint(_root);
    cout<<endl;}
  void _postOrderPrint(TreeNode<T>* node){
    if (node->_left){_postOrderPrint(node->_left);}
  	if (node->_right){_postOrderPrint(node->_right);}
    cout << node->_item<<" ";};
  void postOrderPrint(){_postOrderPrint(_root);
    cout<<endl;}
  // void postOrderPrint(){
  //   if (_root->_left){postOrderPrint(_root->_left);}
  // 	if (_root->_right){postOrderPrint(_root->_right);}
  //   cout << _root->_item<<" ";};

  int searchMin(){TreeNode<T>* current=_root;
  // int searchMin(TreeNode<T>* current=_root){
    while (current->_height>0){current=current-> _left;}
    return current-> _item;}
  int searchMax(){TreeNode<T>* current=_root;
  // int searchMax(TreeNode<T>* current=_root){
    while (current->_height>0){current=current-> _right;}
    return current-> _item;}

  bool exist(T x){TreeNode<T>* current=_root;
    while (current != NULL){
      // cout<<current->_height<<", "<<current->_item<<endl;
      if (current->_item == x){return true;}
      // if (current == NULL){return false;}
      if (current->_item > x){current=current-> _left;}
      if (current->_item < x){current=current-> _right;}
    }
    return false;
  }

  int successor(T x){
    TreeNode<T>* current=_root;
    TreeNode<T>* save=NULL;
    while (current != NULL){
      if (current->_item > x){
        save=current;
        current=current-> _left;}
      else if (current-> _item <= x){current=current-> _right;}
    }
    if(save== NULL){return x;}
    return save->_item;}


};

int main(){
	BinarySearchTree<int> s;

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
  s.printTree();

  // cout<<"height: "<<s.getheight()<<endl;
  // cout<<"min: "<<s.searchMin()<<endl;
  // cout<<"max: "<<s.searchMax()<<endl;
  // cout<<"exist: "<<s.exist(12)<<endl;
  cout<<"successor: "<<s.successor(21)<<endl;

  // s.printTree();
  s.inOrderPrint();
  s.preOrderPrint();
  s.postOrderPrint();
  return 0;
}
