//STLpd.cpp
#include <iostream>
#include <queue>

using namespace std;
void printQueue (priority_queue <string> pq);

int main(){
	priority_queue<string> pq;
	pq.push("Bee");
	pq.push("Aee");
	pq.push("Eee");
	pq.push("Jee");
	pq.push("Hee");
	pq.push("Cee");
	pq.push("Fee");
	pq.push("Kee");
	pq.push("Lee");
	pq.push("Mee");
	printQueue(pq);
return 0;
}

void printQueue (priority_queue <string> pq){
	priority_queue<string> temp = pq;
	while(temp.size() != 0){
		cout << temp.top() << " ";
		temp.pop();
	}
	cout << endl;	
}
