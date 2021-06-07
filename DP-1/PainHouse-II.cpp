#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	int arr[n][k];
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			cin>>arr[i][j];
		}
	}
	
	for(int i=1;i<n;i++){
		for(int j=0;j<k;j++){
			int mini=999999;
			for(int q=0;q<k;q++){
				if(j==q){ 
					continue;
				}
				mini=min(mini,arr[i-1][q]);	
			}
			arr[i][j]+=mini;
		}
	}
	int final=INT_MAX;
	for(int i=0;i<k;i++){
		final=min(final,arr[n-1][i]);
	}
	cout<<final;
}
