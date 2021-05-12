#include<iostream>
using namespace std;
#include<queue>

int main(){
	priority_queue<int>pq;
	pq.push(10);
	pq.push(20);
	cout<<pq.top();
}
