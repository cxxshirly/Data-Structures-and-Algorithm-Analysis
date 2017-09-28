#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void Initialize (vector <int> & v);
void Print (vector <int>   v);
void Reverse (vector <int> & v);

int main(){
	
	stack<string> s1, s2;
	s1.push("Hi there");
	s1.push("Apple");
	s2.push("Bee");
	s2.push("Best");
	
	if(s1 == s2)
		cout << "s1 == s2" << endl;
	else if (s1 < s2) 
		cout  << "s1 < s2" << endl;
	else if (s2 < s1)  
		cout << "s2 < S1" << endl;

	vector <int> v (5);
	cout << "please enter 5 integers: " << endl;;
	Initialize(v);
	cout << "Now printing: "<< endl;
	Print(v);
	cout << "After reversing : "<< endl;
	Reverse(v);
//	reverse(v.begin(), v.end());
	Print(v);
	sort(v.begin(), v.end());
	cout << "After sorting : " << endl;
	Print(v);
return 0;

}

void Initialize (vector <int> &  v){
	int num = 0;
	for(int i = 0;i < 5;i++){
		cin >> num;
		v.push_back(num);
	}

}

void Print (vector <int>  v){
	for (int i = 0; i < v.size(); i++){
		if(v[i] != '\0')
		cout << v[i] << endl;
	}
}

void Reverse (vector <int> & v){
	vector <int> temp;
	int i = v.size();
	while (i > 0){
		i--;
		temp.push_back(v[i]);
	}

	for(int j = 0; j < v.size(); j++){
		v[j] = temp[j];
	}
}
