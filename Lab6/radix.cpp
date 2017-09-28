//radix.cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maxElemLength (const vector <int>& v);
int GetDigit (int number, int k);
vector <queue<int> > ItemsToQueues (const vector<int> & L, int k);
vector <int> QueuesToArray(vector<queue<int> >& QA, int numVals);
void RadixSort (vector <int>& L, int numDigits);
void PrintVector (const vector <int>& L); 

int main(){

	vector<int> L; //The list to be sorted
	vector<queue<int> > QA (10); //Vector of queues indexed 0-9
	L.push_back(380);
	L.push_back(95);
	L.push_back(345);
	L.push_back(382);
	L.push_back(260);
	L.push_back(100);
	L.push_back(492);
	int numDigits = maxElemLength(L);
	cout << " Befor sorted -- print Vector L : ";
	PrintVector(L);
	RadixSort(L,numDigits);
	cout << " after sorted -- print Vector L : ";
	PrintVector(L);
	
	
return 0;
}

//return the number of digits of the largest integer with vector v
int maxElemLength (const vector <int>& v){
	int max = v[0];
	int count = 0;
	for (int i = 0; i < v.size(); i++){
		if (v[i] > max)
			max = v[i];
	}
	while(max){
		max = max/10;
		count ++;
	}	
	
return count;
}

//returns the kth digit of number
int GetDigit (int number, int k){
	int count = 0;
	int temp = number;
	int locNum = number;
	//get the number of digit counted
	while (temp){
		temp = temp/10;
		count ++;
	}
	if (k > (count-1))
		return 0;
	else {
		while (k > 0){
			locNum /= 10;
			-- k;
		}
		return (locNum%10);
	}
}

//creates and returns the intermediate array of ten queues
vector <queue<int> > ItemsToQueues (const vector<int> & L, int k){
	vector<queue<int> > QA (10); //Vector of queues indexed 0-9
	int j;
	int vSize = L.size();
	for (int i = 0; i < vSize; i ++){
		j = GetDigit(L[i],k);
		QA[j].push(L[i]);
	}
	for( int q = 0; q < 10; q ++){
		if(QA[q].empty()){
			QA[q].push(0);
		}
	}	
return QA;
}

//creating a new list from the values in the intermediate array of queues
vector <int> QueuesToArray(vector<queue<int> >& QA, int numVals){
	vector <int> L;
	int i = 0;
	for(int q = 0; q < 10; q++){
		if(QA[i].front() != 0){
			while( !QA[i].empty()){
				L.push_back(QA[i].front());
				QA[i].pop();
				}
			i ++;
			}
		else if( QA[i].front() == 0){
			QA[i].pop();
			i ++;	
		}
		else if (QA[i].empty()){
			i ++;
		}
	}
return L;
}


void RadixSort (vector <int>& L, int numDigits){
	vector <queue<int> > QA (10);
	int numVals = L.size();
	int k = 0;
	for(int i = 0; i < numDigits; i ++){
		QA = ItemsToQueues(L,k);
		L = QueuesToArray(QA,numVals);
		k++;
	}
}

//prints out the content of the vector without modifying it in any way
void PrintVector (const vector <int>& L){
	for( int i = 0; i < L.size(); i ++){
		cout << L[i] << "  ";
	}
	cout << endl;
}

