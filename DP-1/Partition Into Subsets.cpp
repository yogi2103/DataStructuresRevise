#include<iostream>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	long int dp[k+1][n+1];
	
	for(int i=0;i<=k;i++){
		for(int j=0;j<=n;j++){
			dp[i][j]=0;
		}
	}
	
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				dp[i][j]=1;
			}
			else if(i<j){
				dp[i][j]=i*dp[i][j-1]+dp[i-1][j-1];
			}
		}
	}
	cout<<dp[k][n];
}
