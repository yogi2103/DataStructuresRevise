// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    
    bool isCycleHelper(int start,int parent,int V,vector<int>adj[],vector<bool>& visited){
        visited[start]=true;
        for(auto it: adj[start]){
            if(visited[it] && it!=parent){
                return true;
            }
            if(!visited[it]){
             if(isCycleHelper(it,start,V,adj,visited)){
                 return true;
             };    
            }
        }
        return false;
    }
    
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool> visited (V,false);
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            if(isCycleHelper(i,-1,V,adj,visited)){
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
