#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	long long int arr[n][3];
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>arr[i][j];
		}
	}
	
	for(int i=1;i<n;i++){
		arr[i][0]+=min(arr[i-1][1],arr[i-1][2]);
		arr[i][1]+=min(arr[i-1][0],arr[i-1][2]);
		arr[i][2]+=min(arr[i-1][0],arr[i-1][1]);
	}
	
	cout<<min({arr[n-1][0],arr[n-1][1],arr[n-1][2]});
}
