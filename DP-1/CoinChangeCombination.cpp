#include<iostream>
using namespace std;

void coinChangePermutation(int arr[],int n,int tar){
	int dp[tar+1];
	for(int i=0;i<=tar;i++){
		dp[i]=0;
	}
	dp[0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=tar;j++){
			if(j>=arr[i]){
				dp[j]+=dp[j-arr[i]];
			}
		}
	}
	cout<<dp[tar];
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
	coinChangePermutation(arr,n,tar);
}
