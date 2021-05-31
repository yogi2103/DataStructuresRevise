#include<iostream>
using namespace std;

void coinChangeCombination(int arr[],int n,int tar){
	int dp[tar+1];
	for(int i=0;i<=tar;i++){
		dp[i]=0;
	}
	dp[0]=1;
	for(int i=0;i<=tar;i++){
		for(int j=0;j<n;j++){
			if(i>=arr[j]){
				dp[i]+=dp[i-arr[j]];
			}
		}
	}
	return dp[tar];
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
	coinChangeCombination(arr,n,tar);
}
