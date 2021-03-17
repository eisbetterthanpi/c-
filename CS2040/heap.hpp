#include <math.h>

#include <iostream>
using namespace std;

#ifndef HEAPHPP
#define HEAPHPP

#define DEFAULTHEAPSIZE 1023

template <class T>
class Heap {
protected:
	T* _heap;
	int _n;
	void _bubbleUp(int index);
	void _bubbleDown(int index);
    int _lookFor(T x); // return the index of the item x, return -1 if not found
                       // it is not a good/usual implementation, so we hide it from public
public:
	Heap() {
		_heap = new T[DEFAULTHEAPSIZE];
		_n = 0;
	};

	void insert(T);
    bool empty() {return _n==0;};
	T extractMax();
    T peekMax() {return _heap[0];};
	void printHeapArray();
	void printTree();
    void increaseKey(T from, T to);
    void decreaseKey(T from, T to);
    void deleteItem(T);

	~Heap() { delete[] _heap; };

	//You may include your own functions, if necessary
};

template <class T>
void Heap<T>::_bubbleUp(int index) {
	// _heap[index]
	// cout<<index<<", "<<_heap[index+1]<<endl;
	T item=_heap[index];
	int parent=floor((index-1)/2);
	// cout<<parent<<", "<<item<<endl;
	// cout<<item<<", "<<_heap[parent]<<(item>_heap[parent])<<endl;
	while (item>_heap[parent]){
		// cout<<parent<<", "<<item<<endl;
		_heap[index]=_heap[parent];
		_heap[parent]=item;
		index=parent;
		parent=floor((index-1)/2);
		if (index==0) break;
	}
}

template <class T>
void Heap<T>::_bubbleDown(int index){
	T left=2*index +1;
	T right=2*index +2;
	int litm,ritm,sind;
	litm = left<_n ? _heap[left]: -1;
	ritm = right<_n ? _heap[right]: -1;
	// cout<<left<<", "<<right<<endl;
	int item=_heap[index];
	while (item < max(litm,ritm)){
		// if(litm==-1 && ritm==-1){
		// 	cout<<"trigger"<<endl;
		// 	_heap[index]=_heap[_n-1];
		// 	index=_n;
		// 	break;
		// }
		sind = litm > ritm ? left: right;
		_heap[index]=_heap[sind];
		index=sind;
		left=2*index +1;
		right=2*index +2;
		litm = left<_n ? _heap[left]: -1;
		ritm = right<_n ? _heap[right]: -1;
		// cout<<item<<", " << litm<<", " <<ritm<<endl;
		// cout<<left<<", "<<right<<endl;
	}
	_heap[index]=item;
	if(item==-1){
	_heap[index]=_heap[_n-1];
	}
}

template <class T>
void Heap<T>::insert(T item) {
	_heap[_n]=item;
	if (_n>0)_bubbleUp(_n);
	_n++;
}

template <class T>
T Heap<T>::extractMax(){
	T head=_heap[0];
	_heap[0]=-1;
	if (_n>0)_bubbleDown(0);
	_n--;
	return head;
}


template <class T>
void Heap<T>::printHeapArray() {
	for (int i = 0; i < _n; i++)
		cout << _heap[i] << " ";
	cout << endl;
}

template <class T>
int Heap<T>::_lookFor(T x){ // not a very good implementation, but just use this for now.
    int i;
    for(i=0;i<_n;i++)
        if (_heap[i] == x)
            return i;

    return -1;
}


template <class T>
void Heap<T>::decreaseKey(T item, T prty){
	int index=_lookFor(item);
	if (index==-1)return;
	// cout<<"index "<<index<<endl;
	_heap[index] = prty;
	if (_n>0)_bubbleDown(index);
}

template <class T>
void Heap<T>::increaseKey(T item, T prty){
	int index=_lookFor(item);
	if (index==-1)return;
	// cout<<"index "<<index<<endl;
	_heap[index] = prty;
	if (_n>0)_bubbleUp(index);
}

template <class T>
void Heap<T>::deleteItem(T item){
	int index=_lookFor(item);
	if (index==-1)return;
	// cout<<"index "<<index<<" "<<_n<<endl;
	_heap[index] = _heap[_n-1];
	if (_n>0)_bubbleUp(index);
	// printTree();
	if (_n>0)_bubbleDown(index);
	_n--;
}

template <class T>
void Heap<T>::printTree() {
    int parity = 0;
	if (_n == 0)
		return;
	int space = pow(2,1 + (int) log2f(_n)),i;
	int nLevel = (int) log2f(_n)+1;
	int index = 0,endIndex;
    int tempIndex;

	for (int l = 0; l < nLevel; l++)
	{
		index = 1;
        parity = 0;
		for (i = 0; i < l; i++)
			index *= 2;
		endIndex = index * 2 - 1;
		index--;
        tempIndex = index;
        while (index < _n && index < endIndex) {
            for (i = 0; i < space-1; i++)
                cout << " ";
            if(index==0)
                cout << "|";
            else if (parity)
                cout << "\\";
            else
                cout << "/";
            parity = !parity;
            for (i = 0; i < space; i++)
                cout << " ";
			index++;
		}
        cout << endl;
        index=tempIndex;
		while (index < _n && index < endIndex) {
			for (i = 0; i < (space-1-((int) log10(_heap[index]))); i++)
				cout << " ";
			cout << _heap[index];
			for (i = 0; i < space; i++)
				cout << " ";
			index++;
		}

		cout << endl;
		space /= 2;
	}

}

//If necessary, you may include your own functions

/*
g++ -o F:\c++\same "F:\c++\temp.cpp"
F:\c++\same.exe
*/


#endif
