#include<bits/stdc++.h>
using namespace std;

void solution(bool** board,int row,vector<bool>& cols,vector<bool>& leftdiag,vector<bool>& rightdiag,string asf){
	
	if(row==cols.size()){
		cout<<asf+"."<<endl;
		return;
	}
	
	for(int col=0;col<cols.size();col++){
		if(!cols[col] && !rightdiag[row+col] && !leftdiag[row-col+cols.size()-1]){
			board[row][col]=true;
			cols[col]=true;
			rightdiag[row+col]=true;
			leftdiag[row-col+cols.size()-1]=true;
			solution(board,row+1,cols,leftdiag,rightdiag,asf+to_string(row)+"-"+to_string(col)+",");
			board[row][col]=false;
			cols[col]=false;
			rightdiag[row+col]=false;
			leftdiag[row-col+cols.size()-1]=false;
		}
	}
}

int main(){
	int n;
	cin>>n;
	vector<bool> cols(n,false);
	vector<bool> leftdiag(2*n-1,false);
	vector<bool> rightdiag(2*n-1,false);
	bool** board= new bool*[n];
	for(int i=0;i<n;i++){
		board[i]= new bool[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			board[i][j]=false;
		}
	}
	solution(board,0,cols,leftdiag,rightdiag,"");
}
