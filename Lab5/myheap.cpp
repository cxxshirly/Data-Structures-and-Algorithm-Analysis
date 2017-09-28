//myheap.cpp
#include "BinaryHeap.h"
#include <iostream>
using namespace std;

int main(){
	BinaryHeap<char> PQ (50);
	
	for(char letter = 'A'; letter <= 'J'; ++letter){
		PQ.insert(letter);
	}
//	PQ.deleteMin();
//	cout << "Printing Left Subtree of the Root of Heap : ";
//	PQ.printLtSubtree();
//	cout << endl;	
//	cout << "The Height of Heap is : " << PQ.Height() << endl;
//	cout << "The Maximum Value of Heap Is : ";
//	cout << PQ.findMax() << endl;
	cout << "printing the leaves out: ";
	PQ.PrintLeaves();
	cout << endl;
			
return 0;
}

