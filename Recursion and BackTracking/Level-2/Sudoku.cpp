#include<iostream>
using namespace std;

void display(int arr[][9]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool isValid(int board[][9],int x,int y,int val){
	//to check in the row
	for(int j=0;j<9;j++){
		if(board[x][j]==val){
			return false;
		}
	}
	
	//to check in the column
	for(int i=0;i<9;i++){
		if(board[i][y]==val)
			return false;
	}
	
	int smi= x/3* 3;
	int smj =y/3* 3;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[smi+i][smj+j]==val){
				return false;
			}
		}
	}
	return true;
}

void sudokuSolver(int board[][9],int i,int j){
	if(i==9){
		display(board);
		return;
	}
	
	int nexti=0;
	int nextj=0;
	
	if(j==8){
		nexti=i+1;
		nextj=0;
	}
	else{
		nexti=i;
		nextj=j+1;
	}
	
	if(board[i][j]!=0){
		sudokuSolver(board,i,j);
	}
	else{
		for(int options=1;options<=9;options++){
			if(isValid(board,i,j,options)){
				board[i][j]=options;
				sudokuSolver(board,nexti,nextj);
				board[i][j]=0;					//we'll backtrack if we don't find the perfect combination
			}
		}
	}
}

int main(){
	int arr[9][9];
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>arr[i][j];
		}
	}
	sudokuSolver(arr,0,0);
}
