#include<iostream>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int same=k*1;
	int diff=k*(k-1);
	int total=same+diff;
	for(int i=3;i<=n;i++){
		same=diff;
		diff=total*(k-1);
		total=same+diff;
	}
	cout<<total;
}
