#include<iostream>
using namespace std;

void targetSum(int arr[],int n,int tar,string asf){
   if(tar==0){
     cout<<asf<<"."<<endl;
     return;  
    }
    
    if(n==0){
        return;
    }
    
	targetSum(arr+1,n-1,tar-arr[0],asf+to_string(arr[0])+", ");
	targetSum(arr+1,n-1,tar,asf);	
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
	targetSum(arr,n,tar,"");
}
