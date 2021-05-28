
int editDistance_DP(string s1,string s2){
	int m=s1.size();
	int n=s2.size();
	int** output=new int*[m+1];
	for(int i=0;i<=m;i++){
		output[i]=new int[n+1];
		for(int j=0;j<=n;j++){
			output[i][j]=0;
		}
	}
	
	//for filling the first row
	for(int i=0;i<=m;i++){
		output[i][0]=i;
	}
	
	//for fillinf the first column
	for(int i=0;i<=n;i++){
		output[0][i]=i;
	}
	
	//for filling the rest
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s1[m-i]==s2[n-j]){
				output[i][j]=output[i-1][j-1];
			}
			else{
				output[i][j]=min(output[i][j-1],min(output[i-1][j],output[i-1][j-1]));
			}
		}
	}
	return output[m][n];
}

//Memoization

int editDistance(string s1,string s2, int** dp){
	int m=s1.size();
	int n=s2.size();

	if(s1.size()==0){
        dp[m][n] = s2.size();
        return dp[m][n];
    }
    
    if(s2.size()==0){
        dp[m][n] = s1.size();
        return dp[m][n];
    }
    
    if(dp[m][n]!=-1){
    	return dp[m][n];
	}
    
    
    if(s1[0]==s2[0]){
        dp[m][n] = editDistance(s1.substr(1),s2.substr(1));
        return dp[m][n];
    }
    
    else{
        int x=1+editDistance(s1.substr(1),s2);	//insert
        int y=1+editDistance(s1,s2.substr(1));	//delete
        int z=1+editDistance(s1.substr(1),s2.substr(1)); //replace
        dp[m][n]= min(x,min(y,z));
        return dp[m][n];
    }
	
}

int editDistance(string s1,string s2){
	int m=s1.size();
	int n=s2.size();
	int** output=new int*[m+1];
	for(int i=0;i<=m;i++){
		output[i]=new int[n+1];
		for(int j=0;j<=n;j++){
			output[i][j]=-1;
		}
	}
	return editDistance(s1,s2,output);
}

//Recursion
int editDistance(string s1, string s2) {
	// Write your code here
    
    if(s1.size()==0){
        return s2.size();
    }
    
    if(s2.size()==0){
        return s1.size();
    }
    
    if(s1[0]==s2[0]){
        return editDistance(s1.substr(1),s2.substr(1));
    }
    
    else{
        int x=1+editDistance(s1.substr(1),s2);	//insert
        int y=1+editDistance(s1,s2.substr(1));	//delete
        int z=1+editDistance(s1.substr(1),s2.substr(1)); //replace
        return min(x,min(y,z));
    }
}
