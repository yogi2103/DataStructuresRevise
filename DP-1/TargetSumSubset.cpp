#include<iostream>
using namespace std;

void targetSubset(int arr[],int n,int tar){
	int dp[n+1][tar+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=tar;j++){
			dp[i][j]=0;
		}
	}
	
	//because 0 is already a subset of every element
	for(int i=0;i<=n;i++){
		dp[i][0]=1;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=tar;j++){
			
			//no need to include
			if(dp[i-1][j]==1){
				dp[i][j]=1;
			}
			
			//if include
			if(j-arr[i-1]>=0 && dp[i-1][j-arr[i-1]]!=0){
				dp[i][j]=1;
			}
			
		}
	}
	
	if(dp[n][tar]){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
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
	targetSubset(arr,n,tar);
}
