// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
//	bool isCycle(int V, vector<int>adj[])
//	{
//	    // Code here
//	    queue<pair<int,int>>q;
//	    q.push({V,-1});
//	    while(!q.empty()){
//	        pair<int,int>p=q.front();
//	        q.pop();
//	        for(int i=0;i<V;i++){
//	            q.push({adj})
//	        }
//	    }
//	}
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
		
//		Solution obj;
//		bool ans = obj.isCycle(V, adj);
//		if(ans)
//			cout << "1\n";
//		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
