#include<iostream>
#include<queue>
using namespace std;

vector<int> GetPath(int** edges,int sv,int n,bool* visited,int ev){
	vector<int>v;
	if(sv==ev){
		v.push_back(sv);
		return v;
	}
	
	visited[sv]=true;
	
	for(int i=0;i<n;i++){
		if(edges[sv][i]==1 && !visited[i])
			vector<int>temp=GetPath(edges,i,n,visited,ev);
		if(temp.size()>0){
			temp.push_back(sv);
		}
	}
	
	return v;
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
	
	int sv,ev;
	cin>>sv>>ev;
	
	bool visited[n];
	vector<int> v=GetPath(edges,sv,n,visited,ev);
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
}
