#include <iostream>
#include "bst.h"

using namespace std;

int main(){

	BinarySearchTree <int> T(0);
	T.insert(6);
	T.insert(2);
	T.insert(8);
	T.insert(1);
	T.insert(4);
	T.insert(3);
	T.insert(9);
  	T.postOrder();	
	cout << "The height of tree: " << T.height() << endl;
	cout << "The number of Node in this tree: " << T.numNodes() << endl;
	if(T.isBalanced() ==  true){
		cout << "It's Balanced!" << endl;
	}
 	else
		cout << "It's Not Balanced! "  << endl;
return 0;
}
