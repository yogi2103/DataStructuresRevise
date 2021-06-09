#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int bd=0; 		//buying date
	int sd=0; 		//selling date
	int op=0;
	for(int i=1;i<n;i++){
		if(arr[i]>=arr[i-1]){
			sd++;
		}
		else{
			op+=arr[sd]-arr[bd];
			bd=i;
			sd=i;
		}
	}
	op+=arr[sd]-arr[bd];
	cout<<op;
}
