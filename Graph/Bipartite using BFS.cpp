// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	
	bool isBipartiteHelper(int start,int V, vector<int>adj[],vector<int>& colors,vector<bool>& visited){
		queue<int>q;
		q.push(start);
		colors[start]=0;
		visited[start]=true;
		while(!q.empty()){
			int start=q.front();
			cout<<"top="<<start<<" "<<endl;
			q.pop();
			for(auto it: adj[start]){
				cout<<"I am it"<<it<<" ";
				if(visited[it] && colors[start]==colors[it]){
					return false;
				}
				
				if(!visited[it]){
					if(colors[start]==0){
						colors[it]=1;
					}
					else{
						colors[it]=0;
					}
					visited[it]=true;
					q.push(it);
				}
			}
			cout<<endl;
		}
		return true;
	}
	
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<bool> visited(V,false);
	    vector<int> colors(V,-1);
	    for(int i=0;i<V;i++){
	    	if(!visited[i]){
	    		if(!isBipartiteHelper(i,V,adj,colors,visited)){
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
