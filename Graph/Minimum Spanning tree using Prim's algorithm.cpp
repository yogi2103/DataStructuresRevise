// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> key(V,INT_MAX);
        key[0]=0;
        vector<int> mst(V,false);
        vector<int> parent(V,-1);
        for(int i=0;i<V;i++){
        	int node=INT_MAX,index;
        	for(int j=0;j<V;j++){
        		if(key[j]<node && !mst[j]){
        			node=key[j];
        			index=j;
				}
			}
			mst[index]=true;
        	for(auto it: adj[index]){
        		int vertex=it[0];
        		int wt=it[1];
        		if(!mst[vertex] && wt<key[vertex]){
        			key[vertex]=wt;
        			parent[vertex]=index;
				}
			}
		}
		int span=0;
		for(int i=1;i<V;i++){
			span+=key[i];
		}
		return span;
    }
}; 

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
