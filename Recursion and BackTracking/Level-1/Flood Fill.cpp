#include<iostream>

#include<vector>

using namespace std;

void floodfill(vector<vector<int>>maze,int sr,int sc,int dr,int dc,string psf,vector<vector<bool>> visited) {
	if(sr<0 || sc<0 || sr>dr || sc>dc || maze[sr][sc]==1 || visited[sr][sc]){
		return;
	}
	
	if(sr==dr && sc==dc){
		cout<<psf<<endl;
		return;
	}
	visited[sr][sc]=true;
	floodfill(maze,sr-1,sc,dr,dc,psf+"t",visited);
	floodfill(maze,sr,sc-1,dr,dc,psf+"l",visited);
	floodfill(maze,sr+1,sc,dr,dc,psf+"d",visited);
	floodfill(maze,sr,sc+1,dr,dc,psf+"r",visited);
	visited[sr][sc]=false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int >> arr(n, vector < int > (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

	vector< vector<bool>> visited(n);
	for(auto&it: visited){
		vector<bool> check(m,false);
		it=check;
	}
    floodfill(arr,0,0,n-1,m-1,"",visited);
}
