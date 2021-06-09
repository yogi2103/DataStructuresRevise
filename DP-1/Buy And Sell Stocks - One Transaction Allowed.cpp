#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int overall=0;
	int least=999999;
	int pist=0;
	
	for(int i=0;i<n;i++){
		if(arr[i]<least){
			least=arr[i];
		}
		pist=arr[i]-least;
		if(pist>overall){
			overall=pist;
		}
	}
	
	cout<<overall;
}
