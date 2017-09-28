#include <iostream>
using namespace std;

//prototype

bool checkVal (double* ptr1, double* ptr2);
bool checkAdd (double* ptr1, double* ptr2);

int main(){

	double num1 = 20;
	double num2 = 30;
	double* ptr1 = &num1;
	double* ptr2 = &num1;	
	
	checkVal(ptr1,ptr2);
	checkAdd(ptr1,ptr2);




return 0;
}

bool checkVal (double* ptr1, double* ptr2){
	if (*ptr1 == *ptr2)
		return (cout << "true" << endl);
	else 
		return (cout << "false" << endl);
}

bool checkAdd (double* ptr1, double* ptr2){

	if (ptr1 == ptr2)
		return (cout << "true" << endl);
	else 
		return (cout << "false" << endl);
}
