#include<bits/stdc++.h>
#include<queue>
using namespace std;

void printBFS(int** edges,int sv,int n,bool* visited,vector<int>& v){
	queue<int>q;
	q.push(sv);
	visited[sv]=true;
	while(!q.empty()){
		v.push_back(q.front());
		for(int i=0;i<n;i++){
			if(!visited[i] && edges[q.front()][i]==1){
				visited[i]=true;
				q.push(i);
			}
		}
		q.pop();
	}
}

void printBFSHelper(int** edges,int sv,int n,bool* visited){
    for(int i=0;i<n;i++){
    	vector<int>v;
        if(!visited[i])
        	printBFS(edges,i,n,visited,v);
			for(int i=0;i<v.size();i++){
				cout<<v[i]<<" ";
			}
    }
}

void printDFS(int** edges,int sv,int n,bool* visited){
	cout<<sv<<endl;
	visited[sv]=true;
	for(int i=0;i<n;i++){
		if(!visited[i] && edges[sv][i]==1){
			printDFS(edges,i,n,visited);	
		}
	}
}

int main(){
	int n;
	int e;
	cin>>n>>e;
	int** edges=new int*[n];
	for(int i=0;i<n;i++){
		edges[i]= new int[n];
		for(int j=0;j<n;j++){
			edges[i][j]=0;
		}
	}
	
	for(int i=0;i<e;i++){
		int f,s;
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
	}
	
	bool visited[n];
	
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	
	printBFSHelper(edges,0,n,visited);
}
