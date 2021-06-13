// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	
	bool isBipartiteHelper(int start,int color,int V, vector<int>adj[],vector<int>& colors,vector<bool>& visited){
		queue<int>q;
		q.push(start);
		colors[start]=color;
		visited[start]=true;
		for(auto it: adj[start]){
			if(visited[it] && colors[start]==colors[it]){
				return false;
			}
			if(!visited[i]){
				if(!isBipartiteHelper(it,1-colors[start],V,adj,colors,visited)){
					return false;
				};
			}
		}
		return true;
	}
	
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<bool> visited(V,false);
	    vector<int> colors(V,-1);
	    for(int i=0;i<V;i++){
	    	if(!visited[i]){
	    		if(!isBipartiteHelper(i,0,V,adj,colors,visited)){
	    			return false;
				}
			}
		}
		return true;
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
		for(int i=0;i<V;i++){
			cout<<i<<":->";
			for(int j=0;j<adj[i].size();j++){
				cout<<adj[i][j]<<" ";
			}
			cout<<endl;
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends
