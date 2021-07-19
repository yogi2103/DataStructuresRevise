#include<iostream>
using namespace std;

int Surviver(int n,int k){
	if(n==1){
		return 0;
	}
	int x=Surviver(n-1,k); //survive of n-1 
	int y=(x+k)%n;
	return y;
}

int main(){
	int n,k;
	cin>>n>>k;
	cout<<Surviver(n,k);
}
