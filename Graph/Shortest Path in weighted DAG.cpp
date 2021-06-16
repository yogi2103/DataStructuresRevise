#include<bits/stdc++.h>
using namespace std;

void topologicalSort(int start,int n,vector<pair<int,int>> adj[],vector<int>& visited,stack<int>& s){
	visited[start]=true;
	for(auto it: adj[start]){
		if(!visited[it.first]){
			topologicalSort(it.first,n,adj,visited,s);	
		}
	}
	s.push(start);
}

void shortestPath(int start,int n,vector<pair<int,int>> adj[]){
	//first part is to do toplogical sort
	vector<int>v;
	vector<int> visited(n,false);
	stack<int>s;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			topologicalSort(start,n,adj,visited,s);		
		}
	}
	
	//then calculate the distance
	int dist[n];
	for(int i=0;i<n;i++){
		dist[i]=INT_MAX;
	}
	
	dist[s.top()]=0;
	while(!s.empty()){
		int top=s.top();
		s.pop();
		
		for(auto it: adj[top]){
			dist[it.first]=min(dist[top]+it.second,dist[it.first]);
		}
	}
	
	for(int i=0;i<n;i++){
		cout<<dist[i]<<" ";
	}
	
}

int main() 
{ 
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    adj[u].push_back({v, wt}); 
	}
	
	shortestPath(0, n, adj); 

	return 0; 
} 
