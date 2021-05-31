#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int zero=1;
	int one=1;
	for(int i=2;i<=n;i++){
		int temp=one;
		one=zero+one;
		zero=temp;
