#include<bits/stdc++.h>
using namespace std;

bool issafe(vector<vector<bool>> chess,int row,int col){
	//to check in upper row
	for(int i=row-1;i>=0;i--){
		if(chess[i][col]){
			return false;
		}
	}
	
	//to check left diagonal wise
	for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
		if(chess[i][j]){
			return false;
		}
	}
	
	//to check in the right diagonal
	for(int i=row-1,j=col+1; i>=0 && j<chess[0].size();i--,j++){
		if(chess[i][j]){
			return false;
		}
	}
	
	return true;
}

void Nqueens(vector<vector<bool>> chess, string asf,int row){
	
	if(row==chess[0].size()){
		cout<<asf<<"."<<endl;
		return;
	}
	
	for(int col=0;col<chess[0].size();col++){
		if(issafe(chess,row,col)){
			chess[row][col]=true;
			Nqueens(chess,asf+to_string(row)+"-"+to_string(col)+", ",row+1);
			chess[row][col]=false;	
		}
	}
}

int main(){
	int n;
	cin>>n;
	vector<vector<bool>>v(n);
	for(auto& it:v){
		vector<bool>check(n,false);
		it=check;
	}
	Nqueens(v,"",0);
}
