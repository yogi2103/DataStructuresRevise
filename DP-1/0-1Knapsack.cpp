#include<iostream>
using namespace std;

void Knapsack(int arr[],int n,int val[],int wt){
	int dp[n+1][wt+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=wt;j++){
			dp[i][j]=0;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=wt;j++){
			if(j-arr[i-1]>=0){
				dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-arr[i-1]]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<dp[n][wt];
}

int main(){
	int n;
	cin>>n;
	int arr[n],val[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		cin>>val[i];
	}
	int tar;
	cin>>tar;
	Knapsack(arr,n,val,tar);
}
