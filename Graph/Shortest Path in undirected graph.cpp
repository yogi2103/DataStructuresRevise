#include<bits/stdc++.h>
#include<queue>
using namespace std;
int shortestPath(int** edges, int v, int e, int source, int destination)
{
	// Write your code here!
    int arr[v+1];
    for(int i=0;i<=v;i++){
        arr[i]=INT_MAX;
    }
    queue<int>q;
    arr[source]=0;
    q.push(source);
    while(!q.empty()){
    	cout<<"Hello";
    	int front=q.front();
    	q.pop();
        for(int i=1;i<=v;i++){
            if(edges[front][i]){
                if(arr[i]+1<arr[front]){
                	arr[i]=arr[i]+1;
                	q.push(arr[i]);
				}
            }
    	}
    }
    for(int i=1;i<=v;i++){
        cout<<arr[i]<<" ";
    }
    return arr[destination];
}
int main(){
	int n;
	int e;
	cin>>n>>e;
	int** edges=new int*[n+1];
	for(int i=0;i<=n;i++){
		edges[i]= new int[n+1];
		for(int j=0;j<=n;j++){
			edges[i][j]=0;
		}
	}
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			cout<<edges[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i=1;i<=e;i++){
		int f,s;
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
	}
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			cout<<edges[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<shortestPath(edges,n,e,1,4);
}
