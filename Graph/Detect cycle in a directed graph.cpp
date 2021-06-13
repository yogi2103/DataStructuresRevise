	bool isCyclicHelper(int start,int parent,int V, vector<int> adj[],vector<bool>& visited,vector<bool>& dfsvisited) {
		visited[start]=true;
		dfsvisited[start]=true;
		for(auto it: adj[start]){
			if(visited[start] && dfsvisited[it]){
				return true;
			}
			if(!visited[it]){
				if(isCyclicHelper(it,start,V,adj,visited)){
					return true;
				};
			}
		}
		dfsvisited[start]=false;
		return false;
	}
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	// code here
	   	vector<bool> visited(V,false);
	   	vector<bool> dfsvisited(V,false);
	   	for(int i=0;i<V;i++){
	   		if(!visited[i]){
	   			if(isCyclicHelper(i,-1,V,adj,visited,dfsvisited)){
	   				return true;
				   };
			   }
		}
		return false;
	}
