// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    
    bool isCycleHelper(int start,int V, vector<int>adj[],vector<bool>& visited ){
	    queue<pair<int,int>>q;
	    q.push({start,-1});
	    visited[start]=true;
	    while(!q.empty()){
	        pair<int,int>p=q.front();
	        int adj_element=p.first;
	        int prev=p.second;
	        q.pop();
	        for(auto it: adj[adj_element]){
	        	//if my previous node is already visited
	        	if(visited[it] && it!=prev){
	        		return true;
				}
				if(!visited[it]){
					q.push({it,p.first});
	            	visited[it]=true;	
				}
	        }
	    }
	    return false;
    }
    
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	   vector<bool> visited(V,false);
	   for(int i=0;i<V;i++){
	       if(!visited[i]){
	        if(isCycleHelper(i,V,adj,visited)){
	           return true; 
	        };   
	       }
	    }
	    return false;
	}
	
	
	
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
