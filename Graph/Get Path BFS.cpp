#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

vector<int> GetPathBFS(int** edges,int sv,int n,bool* visited,int ev){
	unordered_map<int,int>m;
	m[sv]=-1;
	queue<int>q;
	q.push(sv);
	visited[sv]=true;
	int top=0;
	while(!q.empty()){
		int sv=q.front();
		if(sv==ev){
			top=sv;
			break;
		}
		q.pop();
		for(int i=0;i<n;i++){
			if(edges[sv][i]==1 && !visited[i]){
				visited[i]=true;
				q.push(i);	
				m[i]=sv;
			}
		}
	}
    vector<int>v;
	if(top){
		int last=top;
		while(last!=-1){
			v.push_back(last);
			last=m[last]; 
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
	vector<int> v=GetPathBFS(edges,sv,n,visited,ev);
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
}
