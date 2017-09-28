#include <iostream>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;

struct RecType{
	int age;
	float weight;
	char gender;
};

int main(){

	int num = 5;
	int* intPtr = NULL;
	intPtr = &num;
	num *= 10;
	cout << "intPtr points to :			 " << *intPtr << endl;
	RecType* recPtr = new RecType;
	recPtr -> age = 25;
	recPtr -> weight = 190;
	recPtr -> gender = 'M';
	recPtr -> age += 5;
	cout << "Three Fields Ponited to By recPtr :	 " << recPtr -> age << " " << recPtr -> weight << " " << recPtr -> gender << " " << endl;
	delete recPtr;
	recPtr = NULL;

	char* strPtr = new char [50];
	strcpy (strPtr, "Operating Systems");
	cout << "strPtr ponits to :		  	 " << strPtr << endl;

	int count = 0;
	int strSize = strlen(strPtr);
	for (int i = 0; i <= strSize; i++){
		if(islower(*strPtr++)){
			count++;
		}
	}
	cout << "LowerCase Letters Pointed To By strPtr : " << count << endl;
	strPtr = strPtr - strSize- 1;
	strPtr += 10;	
	cout << "Printing strPtr after adding 10:	 " << strPtr << endl;
	strPtr -= 10;	
	delete strPtr;
	
	return 0;
}

