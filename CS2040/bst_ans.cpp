#include <iostream>
using namespace std;
template <class T>
class BinarySearchTree;

/*
g++ -o F:\c++\same "F:\c++\bst_ans.cpp"
F:\c++\same.exe
*/

template <class T>
class TreeNode {
private:
	T _item;
	TreeNode<T>* _left;
	TreeNode<T>* _right;
	int _height;
public:
	TreeNode(T x) { _left = _right = NULL; _item = x; _height = 0; };
	friend BinarySearchTree<T>;
};
template <class T>
class BinarySearchTree{
private:
	int _size;
	TreeNode<T>* _root;
	void _printTree(int indent, TreeNode<T>*, bool withHeight);
	void _inOrderPrint(TreeNode<T>*);
	void _preOrderPrint(TreeNode<T>*);
	void _postOrderPrint(TreeNode<T>*);
	TreeNode<T>* _insert(TreeNode<T>* current, T x);
	TreeNode<T>* balance(TreeNode<T>*);
	int getheight(TreeNode<T>*);
	TreeNode<T>* _rightRotation(TreeNode<T>*);
	TreeNode<T>* _leftRotation(TreeNode<T>*);
    void _destroySubTree(TreeNode<T>*);
public:
	BinarySearchTree() { _root = NULL; _size = 0; }
	~BinarySearchTree();
	int size() { return _size; };
	void insert(T);
	void printTree(bool withHeight = 1);
	// void printTree(bool withHeight);
	void inOrderPrint();
	void postOrderPrint();
	void preOrderPrint();
	T searchMax() ;
	T searchMin();
	bool exist(T x);
	T successor(T);
};

template <class T>
void BinarySearchTree<T>::_printTree(int indent, TreeNode<T>* node, bool withHeight){
	if (!node){return;}
	if (node->_right){_printTree(indent + 2, node->_right, withHeight);}
  for (int i = 0; i < indent; i++){cout << " ";}
  cout << node->_item;
	if (withHeight){cout << "(h=" << node->_height << ")";}
  cout << endl;
  if (node->_left){_printTree(indent + 2, node->_left, withHeight);}
};
template <class T>
// void BinarySearchTree<T>::printTree(bool withHeight= true){
void BinarySearchTree<T>::printTree(bool withHeight){
	_printTree(0, _root, withHeight);}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_insert(TreeNode<T>* current, T x){ //inserting x
	if (current->_item > x) {
		if (current->_left){
			// current-> _left = _insert(current-> _left, x);
			current-> _left = balance(_insert(current-> _left, x));
			if (current-> _left->_height== current->_height){current->_height++;}
		}
		else {current->_left = new TreeNode<T>(x);
			if (current-> _left->_height== current->_height){current->_height++;}
			return current;}
	}
	else if (x > current->_item){
		if (current->_right){
			// current-> _right = _insert(current-> _right, x);
			current-> _right = balance(_insert(current-> _right, x));
			if (current-> _right->_height == current->_height){current->_height++;}
		}
		else {current->_right = new TreeNode<T>(x);
			if (current-> _right->_height == current->_height){current->_height++;}
			return current;}
	}
return current;
}
template <class T>
void BinarySearchTree<T>::insert(T x){
	if (_root == NULL){
		_root = new TreeNode<T>(x);
		_size ++;}
	else if (! exist(x)){
		_root = balance(_insert(_root, x));
		_size ++;}
}
template <class T>
TreeNode<T>* BinarySearchTree<T>:: balance(TreeNode<T>* p){
	if(getheight(p->_right)-getheight(p->_left)>1){p=_leftRotation(p);
	}
	if(getheight(p->_right)-getheight(p->_left)<-1){p=_rightRotation(p);
	}
	return p;
}
template <class T>
int BinarySearchTree<T>::getheight(TreeNode<T>* p){
	if (! p){return -1;}
	int l=-1,r=-1;
	p->_height=1;
	if (p->_left){l=p->_left->_height;}
	if (p->_right){r=p->_right->_height;}
	p->_height+=max(l,r);
	// return _root->_height;}
	return p->_height;}
template <class T>
bool BinarySearchTree<T>::exist(T x){
	TreeNode<T>* current=_root;
	while (current != NULL){
		if (current->_item == x){return true;}
		else if (current->_item > x){current=current-> _left;}
		else if (current->_item < x){current=current-> _right;}
	}
	return false;
}
template <class T>
T BinarySearchTree<T>::searchMax() {
	TreeNode<T>* current=_root;
	// if (!current) return;
	// while (current-> _item){current=current-> _right;}
  while (current-> _right){current=current-> _right;}
	return current-> _item;
  // return current-> _item;}
	// return T();
}
template <class T>
T BinarySearchTree<T>::searchMin(){
	TreeNode<T>* current=_root;
	// if (!current) return _root;
	// while (current-> _item){current=current-> _left;}
  while (current-> _left){current=current-> _left;}
	return current-> _item;
}
template <class T>
T BinarySearchTree<T>::successor(T x){
    TreeNode<T>* current=_root;
    TreeNode<T>* save=NULL;
    while (current != NULL){
      if (current->_item > x){
        save=current;
        current=current-> _left;}
      else if (current-> _item <= x){current=current-> _right;}
    }
    if(save== NULL){return x;}
    return save->_item;
}
template <class T>
TreeNode<T>* BinarySearchTree<T>::_leftRotation(TreeNode<T>* p){
    TreeNode<T>* c=p->_right;
    p->_right=c->_left;
    p->_height=getheight(p);
    c->_left=p;
    c->_height=getheight(c);
    return c;
  }
template <class T>
TreeNode<T>* BinarySearchTree<T>::_rightRotation(TreeNode<T>* p){
    TreeNode<T>* c=p->_left;
    p->_left=c->_right;
    p->_height=getheight(p);
    c->_right=p;
    c->_height=getheight(c);
    return c;
  }

template <class T>
void BinarySearchTree<T>::preOrderPrint(){
    _preOrderPrint(_root);
    cout<<endl;
}
template <class T>
void BinarySearchTree<T>::_preOrderPrint(TreeNode<T>* node){
	if (!node) return;
	cout << node->_item << " ";
	_preOrderPrint(node->_left);
	_preOrderPrint(node->_right);
}
template <class T>
void BinarySearchTree<T>::inOrderPrint(){
    _inOrderPrint(_root);
    cout<<endl;
}
template <class T>
void BinarySearchTree<T>::_inOrderPrint(TreeNode<T>* node){
	if (!node) return;
	_inOrderPrint(node->_left);
	cout << node->_item << " ";
	_inOrderPrint(node->_right);
}
template <class T>
void BinarySearchTree<T>::postOrderPrint(){
    _postOrderPrint(_root);
    cout<<endl;
}
template <class T>
void BinarySearchTree<T>::_postOrderPrint(TreeNode<T>* node){
	if (!node) return;
	_postOrderPrint(node->_left);
	_postOrderPrint(node->_right);
	cout << node->_item << " ";
}

template <class T>
void BinarySearchTree<T> ::_destroySubTree(TreeNode<T>* node){
	if (node->_left) _destroySubTree(node->_left);
	if (node->_right) _destroySubTree(node->_right);
	delete node;
}

template <class T>
BinarySearchTree<T> :: ~BinarySearchTree(){
	if (_root) _destroySubTree(_root);
}


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
