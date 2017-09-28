//radixS.cpp
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int maxElemLength (const vector <string>& v);
char GetChar (string s, int k);
vector <queue<string> > ItemsToQueues (const vector<string> & L, int k);
vector <string> QueuesToArray(vector<queue<string> >& QA, int numVals);
void RadixSort (vector <string>& L, int numDigits);
void PrintVector (const vector <string>& L); 
vector <string>  padding (const vector <string> &v, int max);
vector <string> unPadding (const vector <string> &v, int max);

int main(){

	vector<string> L; //The list to be sorted
	vector<queue<string> > QA (128); //Vector of queues indexed 0-128
	L.push_back("zebra");
	L.push_back("apple");
	L.push_back("orange");
	L.push_back("can");
	L.push_back("candy");
	L.push_back("a");
	L.push_back("top");
	L.push_back("pumpkin");
	L.push_back("today");
	L.push_back("parade");

	int numDigits = maxElemLength(L);
	cout << " Befor sorted -- print Vector L : ";
	PrintVector(L);
	L = padding(L,numDigits);
	RadixSort(L,numDigits);
	cout << " after sorted -- print Vector L : ";
	L = unPadding(L,numDigits);
	PrintVector(L);

return 0;
}

//return the number of char of the largest string with vector v
int maxElemLength (const vector <string>& v){
	int max = v[0].size();
	int count = 0;
	for (int i = 0; i < v.size(); i++){
		if (v[i].size() > max)
			max = v[i].size();
	}
return max;
}

vector <string> padding (const vector <string> &v, int max){
	vector<string> L; 
	for (int i = 0; i < v.size(); i++){
		string a = v[i];
		int num = max - (v[i].size());
		a.insert(a.end(), num, ' ');
		L.push_back(a);
	//	cout << "L[i] =" << L[i];

	}
//	cout << endl;
return L;
}

vector <string> unPadding (const vector <string> &v, int max){
	vector<string> L; 
	for (int i = 0; i < v.size(); i++){
		string a = v[i];
		if(a.find(' ')){
			string b;
			b = a.substr(0,a.find(' '));
			L.push_back(b);
		}
		else{
			L.push_back(a);
		}
	}	
return L;
}
//returns the kth digit of number
char GetChar (string s, int k){
	if(k == 0){
		char ch = s[s.size()-1];
		return ch;	
	}
	else if(s.size() >=  k-1){
		string a = s.substr(s.size()-1-k,1);
		char ch = a[0];
		return ch;
	}
	else{
		char ch = ' ';
		return ch;	
	}
}

//creates and returns the intermediate array of ten queues
vector <queue<string> > ItemsToQueues (const vector<string> & L, int k){
	vector<queue<string> > QA (128); //Vector of queues indexed 0-128
	char j;
	int vSize = L.size();
	//cout << " k = " << k << endl;
	
	for (int i = 0; i < vSize; i ++){
		j = GetChar(L[i],k);
		QA[j].push(L[i]);
		//cout << " QA[" << j << "] push : " << L[i];
	}
	for( int q = 0; q < 128; q ++){
		if(QA[q].empty()){
			QA[q].push(" ");
		}
	}	
	//cout << endl;
return QA;
}

//creating a new list from the values in the intermediate array of queues
vector <string> QueuesToArray(vector<queue<string> >& QA, int numVals){
	vector <string> L;
	int i = 0;
	for(int q = 0; q < 128; q++){
		if(QA[i].front() != " "){
			while( !QA[i].empty()){
				L.push_back(QA[i].front());
				QA[i].pop();
				}
			i ++;
		}
		else if( QA[i].front() == " " ){
			QA[i].pop();
			i ++;	
		}
		else if (QA[i].empty()){
			i ++;
		}
	}
	//cout << "Queues to Array : ";
	//PrintVector(L);
return L;
}


void RadixSort (vector <string>& L, int numDigits){
	vector <queue<string> > QA (128);
	int numVals = L.size();
	int k = 0;
	for(int i = 0; i < numDigits; i ++){
		QA = ItemsToQueues(L,k);
		L = QueuesToArray(QA,numVals);
		k++;
	}
}

//prints out the content of the vector without modifying it in any way
void PrintVector (const vector <string>& L){
	for( int i = 0; i < L.size(); i ++){
		cout << L[i] << "  ";
	}
	cout << endl;
}


