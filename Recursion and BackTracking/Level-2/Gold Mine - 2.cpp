#include<bits/stdc++.h>
using namespace std;

void travelAndCollectGold(vector<vector<int>> arr,int i,int j,vector<int>&bag,vector<vector<bool>>&visited){
	
	if(i<0 || j<0 || i>=arr.size() || j>=arr[0].size() || arr[i][j]==0 || visited[i][j]){
		return;
	}
	
	visited[i][j]=true;
	bag.push_back(arr[i][j]);
	//4 direction calls
	travelAndCollectGold(arr,i-1,j,bag,visited);
	travelAndCollectGold(arr,i,j+1,bag,visited);
	travelAndCollectGold(arr,i,j-1,bag,visited);
	travelAndCollectGold(arr,i+1,j,bag,visited);
}

int getMaxGold(vector<vector<int>> arr,int n,int m){
	//visited array
	int max=-9999999;
	vector< vector<bool>> visited(n);
	for(auto&it: visited){
		vector<bool> check(m,false);
		it=check;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			vector<int> bag;
			if(arr[i][j]!=0 && !visited[i][j]){
				travelAndCollectGold(arr,i,j,bag,visited);
				int sum=0;
				for(auto& it: bag){
					sum+=it;
				}
				if(sum>max){
					max=sum;
				}
			}
		}
	}
	return max;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int >> arr(n, vector < int > (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    cout<<getMaxGold(arr,n,m);
}
