#pragma once
#include <math.h>

#include <iostream>
using namespace std;

#ifndef HEAPHPP
#define HEAPHPP

// left(x)=2x+1	right(x)=2x+2	parent(x)=floor((x-1)/2)
// parent=floor((index-1)/2)
// customer use >, rest use <

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
	int left=2*index +1;
	int right=2*index +2;
	T item,litm,ritm,mxitm;
	int sind;
	// litm = left<_n ? _heap[left]: -1;
	// litm = left<_n ? void(_heap[left]): void(NULL);
	if (left<_n){
		litm=_heap[left];
		sind=left;
		mxitm=litm;
		if (right<_n){
			ritm=_heap[right];
			sind = litm > ritm ? left: right;
			mxitm = litm > ritm ? litm : ritm;
		}
	}
	else if (left>_n && right>_n) return;
	item=_heap[index];
	// while (item < max(litm,ritm)){
	while (mxitm > item){
		sind = litm > ritm ? left: right;
		_heap[index]=_heap[sind];
		index=sind;
		left=2*index +1;
		right=2*index +2;
		if (left<_n){
			litm=_heap[left];
			sind=left;
			mxitm=litm;
			if (right<_n){
				ritm=_heap[right];
				sind = litm > ritm ? left: right;
				mxitm = litm > ritm ? litm : ritm;
			}
		}
		else break;
		// cout<<index<<", " <<left<<", "<<right<<endl;
	}
	_heap[index]=item;
	// if(item==-1){
	// _heap[index]=_heap[_n-1];
	// }
	return;
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
	// deleteItem(_heap[0]);
	_heap[0] = _heap[_n-1];
	// cout<<"extract b4 bbd"<<endl;
	if (_n>0)_bubbleDown(0);
	_n--;
	return head;
}

template <class T>
void Heap<T>::printHeapArray(){
	for (int i = 0; i < _n; i++)
		cout << _heap[i] << " ";
	cout << endl;
}

template <class T>
int Heap<T>::_lookFor(T x){ // not a very good implementation, but just use this for now.
    int i;
		// cout << _heap<<endl;
    for(i=0;i<_n;i++){
				// cout <<_heap[i] <<", "<< x<< endl;
				// cout<<_heap[i] == x ;
				// if (_heap[i] == x){
				if (_heap[i] >= x && _heap[i] <= x){
						// cout<<"found "<<i<<endl;
						return i;
				}
		}
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
	// cout<<"index "<<index<<" "<<_n<<" "<<_heap[_n-1]<<endl;
	_heap[index] = _heap[_n-1];
	// cout<<"del bb "<<endl;
	if (_n>0)_bubbleUp(index);
	// cout<<"del bb uped "<<index<<endl;
	// printTree();
	if (_n>0)_bubbleDown(index);
	// cout<<"del bb downed "<<index<<endl;
	_n--;
}

template <class T>
void Heap<T>::printTree(){
  int parity = 0;
	if (_n == 0)
		return;
	int space = pow(2,1 + (int) log2f(_n)),i;
	int nLevel = (int) log2f(_n)+1;
	int index = 0,endIndex;
  int tempIndex;
	for (int l = 0; l < nLevel; l++){
		index = 1;
    parity = 0;
		for (i = 0; i < l; i++)
			index *= 2;
			endIndex = index * 2 - 1;
			index--;
      tempIndex = index;
      while (index < _n && index < endIndex){
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





#endif
