
//using dp
int minCostPathHelper(int **input, int** dp, int i, int j, int m, int n){
    if(i>=m || j>=n){
        return INT_MAX;
    }
    
    if(i==m-1 && j==n-1){
        dp[i][j]=input[i][j];
        return dp[i][j];
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    int x=minCostPathHelper(input,dp,i+1,j+1,m,n);
    int y=minCostPathHelper(input,dp,i,j+1,m,n);
    int z=minCostPathHelper(input,dp,i+1,j,m,n);
    
    dp[i][j] = input[i][j]+min(x,min(y,z));
    return dp[i][j];
}


//using recursion
int minCostPathHelper(int** input,int i,int j,int m,int n){
    if(i>=m || j>=n){
        return INT_MAX;
    }

    if(i==m-1 && j==n-1){
        return input[i][j];
    }
    
    //diagonally
    int x=minCostPathHelper(input,i+1,j+1,m,n);
    int y=minCostPathHelper(input,i,j+1,m,n);
    int z=minCostPathHelper(input,i+1,j,m,n);
    
    return input[i][j]+min(x,min(y,z));
}

int minCostPath(int **input, int m, int n)
{
	//Write your code here
    return minCostPathHelper(input,0,0,m,n);
}
