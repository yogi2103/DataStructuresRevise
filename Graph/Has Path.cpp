#include<iostream>
#include<queue>
using namespace std;

bool hasPathHelper(int** edges,int sv,int n,bool* visited, int ev){
	if(sv==ev){
		return true;
	}
	
	visited[sv]=true;
	for(int i=0;i<n;i++){
        
        if(i==sv){
            continue;
        }
        
		if(!visited[i] && edges[sv][i]==1){
			if(hasPathHelper(edges,i,n,visited,ev))
                return true;
		}
	}
	
	return false;
}

bool hasPath(int** edges,int sv,int n,bool* visited,int ev){
	if(edges[sv][ev]==1){
		return true;
	}
	
	return hasPathHelper(edges,sv,n,visited,ev);
		
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
	if(hasPath(edges,sv,n,visited,ev))
        cout<<"true";
    else{
        cout<<"false";
    }
}
