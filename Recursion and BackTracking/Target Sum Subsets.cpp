#include<iostream>
using namespace std;

void target_Sum(int* arr,int n,int tar,int curr,string psf){
	if(n==0){
		if(curr==tar){
			cout<<psf<<"."<<endl;
		}
		return;
	}
	//current array element will be a part
	target_Sum(arr+1,n-1,tar,curr+arr[0],psf+to_string(arr[0])+",");
	//will not be a part
	target_Sum(arr+1,n-1,tar,curr,psf);
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int tar;
	cin>>tar;
	
	target_Sum(arr,n,tar,0,"");
	
}
