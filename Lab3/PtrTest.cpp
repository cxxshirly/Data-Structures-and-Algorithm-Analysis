
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;

int main(){
	int* ptrA,* ptrB;
	ptrA = new int;
	ptrB = new int;
	*ptrA = 345;
	ptrB = new int;
	*ptrB = *ptrA;

return 0;
}

