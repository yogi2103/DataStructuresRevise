#include<bits/stdc++.h>
using namespace std;

bool safeplace(vector<vector<bool>>chess,int row,int col){
	//for checking row-wise
	for(int i=row-1;i>=0;i--){
		if(chess[i][col]){
			return false;
		}
	}
	
	//for checking left diagonal wise
	int i=row-1;
	int j=col-1;
	while(i>=0 && j>=0){
		if(chess[i--][j--]){
			return false;
		}
	}
	
	//for checking right diagonal wise
	i=row-1;
	j=col+1;
	while(i>=0 && j<chess.size()){
		if(chess[i--][j++]){
			return false;
		}
	}
	
	return true;
}

//the point here is that we can place only one queen at each row.

void Nqueens(vector<vector<bool>>chess,string qsf,int row){
	
	if(row==chess.size()){
		cout<<qsf+"."<<endl;
		return;
	}
	
	for(int col=0;col<chess.size();col++){
		if(safeplace(chess,row,col)){
			chess[row][col]=true;
			Nqueens(chess,qsf+to_string(row)+"-"+to_string(col)+", ",row+1);
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
