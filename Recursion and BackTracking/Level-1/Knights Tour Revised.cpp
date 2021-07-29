#include<bits/stdc++.h>
using namespace std;

void displayBoard(vector<vector<int>> chess){
	for(auto& it:chess){
		for(auto& z:it){
			cout<<z<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void KnightsTour(vector<vector<int>> chess, int r, int c, int move){
	
	if(r<0 || c<0 || r>=chess[0].size() || c>=chess[0].size() || chess[r][c]>0){
		return;
	}
	
	else if(move==chess[0].size()*chess[0].size()){
		chess[r][c]=move;
		displayBoard(chess);
		chess[r][c]=0;
		return;
	}
	
	chess[r][c]=move;
	KnightsTour(chess,r-2,c+1,move+1);
	KnightsTour(chess,r-1,c+2,move+1);
	KnightsTour(chess,r+1,c+2,move+1);
	KnightsTour(chess,r+2,c+1,move+1);
	KnightsTour(chess,r+2,c-1,move+1);
	KnightsTour(chess,r+1,c-2,move+1);
	KnightsTour(chess,r-1,c-2,move+1);
	KnightsTour(chess,r-2,c-1,move+1);
	chess[r][c]=0;
}

int main(){
	int n,r,c;
	cin>>n>>r>>c;
	vector<vector<int>>v(n);
	for(auto& it:v){
		vector<int>check(n,0);
		it=check;
	}
	KnightsTour(v,r,c,1);
}
