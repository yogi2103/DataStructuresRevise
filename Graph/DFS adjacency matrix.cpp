#include<iostream>
#include<queue>
using namespace std;

void printBFS(int** edges,int sv,int n,bool* visited){
	queue<int>q;
	q.push(sv);
	while(!q.empty()){
		cout<<q.front();
		visited[q.front()]=true;
		for(int i=0;i<n;i++){
			if(!visited[i] && edges[q.front()][i]==1){
				visited[i]=true;
				q.push(i);
			}
		}
		q.pop();
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
	
	printBFS(edges,0,n,visited);
}
