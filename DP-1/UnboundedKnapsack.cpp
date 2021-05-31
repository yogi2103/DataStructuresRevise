#include<iostream>
using namespace std;

void unBoundedKnapsack(int arr[],int n,int val[],int wt){
	int dp[wt+1];
	for(int i=0;i<=wt;i++){
		dp[i]=0;
	}
	for(int i=1;i<=wt;i++){
		int maxi=-9999999;
		for(int j=0;j<n;j++){
			if(i>=arr[j]){
				maxi=max(maxi,val[j]+dp[i-arr[j]]);	
			}
		}
		dp[i]=maxi;
	}
	cout<<dp[wt];
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
	unBoundedKnapsack(val,n,arr,tar);
}
