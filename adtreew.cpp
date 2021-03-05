
#include <iostream>
using namespace std;
/*
g++ -o F:\c++\same "F:\c++\adtreew.cpp"
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
  int _weight;
public:
  TreeNode(T x){
    _left = _right = NULL;
    _item = x;
    _height = 0;
    _weight = 1;
  }
    friend class BinarySearchTree<T>;
};

template <class T>
class BinarySearchTree{
private:
	// int _size;
  int _weight;
  TreeNode<T>* _root;
public:
  BinarySearchTree(){_weight=1;_root = NULL; }

// weight insert
  TreeNode<T>* _insert(TreeNode<T>* current, T x){ //inserting x
    current-> _weight++;
    if (current->_item > x) {
      if (current->_left){
        // current-> _left = _insert(current-> _left, x);}
        cout<<x<<" ins l "<<current->_item<<endl;
        current-> _left = balance(_insert(current-> _left, x));
        if (current-> _left->_height== current->_height){current->_height++;}
      }
      else {current->_left = new TreeNode<T>(x);
        if (current-> _left->_height== current->_height){current->_height++;}
        return current;}
    }
    else if (x > current->_item){
      if (current->_right){
        // current-> _right = _insert(current-> _right, x);}
        cout<<x<<" ins r "<<current->_item<<endl;
        current-> _right = balance(_insert(current-> _right, x));
        if (current-> _right->_height == current->_height){current->_height++;}
      }
      else {current->_right = new TreeNode<T>(x);
        if (current-> _right->_height == current->_height){current->_height++;}
        return current;}
    }
  return current;
  }
  void insert(T x) {
  	if (_root == NULL){_root = new TreeNode<T>(x);}
  	else{_root = _insert(_root, x);}
  }

  TreeNode<T>* head(){
    // cout<<_root->_weight<<endl;
    return _root->_right->_left;}
    // return _root;}

  int getheight(TreeNode<T>* p){
    if (! p){return -1;}
    int l=-1,r=-1;
    p->_height=1;
    if (p->_left){l=p->_left->_height;}
    if (p->_right){r=p->_right->_height;}
    p->_height+=max(l,r);
    // return _root->_height;}
    return p->_height;}
  int getweight(TreeNode<T>* p){
    // return _root->_weight;
    // p->_weight=p->_left->_weight+p->_right->_weight+1
    if (! p){return 0;}
    p->_weight=1;
    if (p->_left){p->_weight+=p->_left->_weight;}
    if (p->_right){p->_weight+=p->_right->_weight;}
    return p->_weight;
    }

  void _printTree(int indent, TreeNode<T>* node, bool withWeight){
  	if (!node){return;}
  	if (node->_right){
  		_printTree(indent + 2, node->_right, withWeight);}
  	for (int i = 0; i < indent; i++){cout << " ";}
  	cout << node->_item;
    if (true){cout << "(h=" << node->_height << ")";}
  	if (withWeight){cout << "(w=" << node->_weight << ")";}
    cout << endl;
    if (node->_left){_printTree(indent + 2, node->_left, withWeight);}
  };
  void printTree(bool withWeight=true){_printTree(0, _root, withWeight);}



  TreeNode<T>* right(TreeNode<T>* p){
    TreeNode<T>* c=p->_left;
    p->_left=c->_right;
    p->_weight=getweight(p);
    p->_height=getheight(p);
    c->_right=p;
    c->_weight=getweight(c);
    c->_height=getheight(c);
    return c;
  }
  TreeNode<T>* left(TreeNode<T>* p){
    TreeNode<T>* c=p->_right;
    p->_right=c->_left;
    p->_weight=getweight(p);
    p->_height=getheight(p);
    c->_left=p;
    c->_weight=getweight(c);
    c->_height=getheight(c);
    return c;
  }

  TreeNode<T>* balance(TreeNode<T>* p){
    cout<<"bal "<<p->_item<<" ";
  // TreeNode<T>* balance(){
    // TreeNode<T>* p = _root->_right->_left;
    // TreeNode<T>* gp = _root->_right;
    // _root->_right->_left=right(p);
    // if(getweight(p->_right)-getweight(p->_left)>1){p=left(p);
    if(getheight(p->_right)-getheight(p->_left)>1){p=left(p);
    cout<<"l";}
    // if(getweight(p->_right)-getweight(p->_left)<-1){p=right(p);
    if(getheight(p->_right)-getheight(p->_left)<-1){p=right(p);
    cout<<"r";}
    // if p->_right->_weight p->_leftp->_weight 1 =right(p);
    // p->_right->_weight p->_leftp->_weight 1 =left(p);
    // _root->_right->_left=left(p);
    // gp->_left=p;
    cout<<p->_item<<endl;
    return p;
    // return _root;
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

  int searchMin(){TreeNode<T>* current=_root;
    while (current->_weight>1){current=current-> _left;}
    return current-> _item;}
  int searchMax(){TreeNode<T>* current=_root;
    while (current->_weight>1){current=current-> _right;}
    return current-> _item;}
  bool exist(T x){TreeNode<T>* current=_root;
    while (current != NULL){
      if (current->_item == x){return true;}
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
  s.printTree();
  cout<<endl<<endl;
  // s.balance();
  // s.balance(s.head());
  // s.printTree();

  // s.inOrderPrint();
  // s.preOrderPrint();
  // s.postOrderPrint();
  // cout<<"weight: "<<s.getweight()<<endl;
  cout<<"weight: "<<s.getweight(s.head())<<endl;
  // cout<<"min: "<<s.searchMin()<<endl;
  // cout<<"max: "<<s.searchMax()<<endl;
  // cout<<"exist: "<<s.exist(152)<<endl;
  // cout<<"successor: "<<s.successor(210)<<endl;
  return 0;
}
