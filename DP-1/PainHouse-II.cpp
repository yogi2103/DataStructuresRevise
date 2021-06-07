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
	
	//starting with the next array
	for(int i=1;i<n;i++){
		//for as many colors 
		for(int j=0;j<k;j++){
			int mini=999999;
			//for each color choosing the minimum cost
			for(int q=0;q<k;q++){
				if(j==q){ 
					continue;
				}
				mini=min(mini,arr[i-1][q]);	
			}
			arr[i][j]+=mini;
		}
	}
	
	//finally finding the minimum cost among all the houses
	int final=INT_MAX;
	for(int i=0;i<k;i++){
		final=min(final,arr[n-1][i]);
	}
	cout<<final;
}
