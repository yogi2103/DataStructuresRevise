#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int include=arr[0];
	int exclude=0;
	for(int i=1;i<n;i++){
		exclude=max(include,exclude);
		include+=arr[i];
	}
	cout<<max(include,exclude);
}
