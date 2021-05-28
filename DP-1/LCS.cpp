#include<iostream>
using namespace std;

int lcs_DP(string s1,string s2){
	int m=s1.size();
	int n=s2.size();
	int** output=new int*[m+1];
	for(int i=0;i<=m;i++){
		output[i]=new int[n+1];
		for(int j=0;j<=n;j++){
			output[i][j]=0;
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s1[i]==s2[j]){
				output[i][j]=1+output[i-1][j-1];
			}
			else{
				output[i][j]=max(output[i-1][j-1],max(output[i][j-1],output[i-1][j]));
			}
		}
	}
	
	return output[m][n];
}

int longestCommonSubsequence(string s1,string s2, int** dp){
	
	int m=s1.size();
	int n=s2.size();
	 if(s1.size()==0 || s2.size()==0){
            return 0;
    }
	
	if(dp[m][n]!=-1){
		return dp[m][n];
	}
	
	if(s1[0]==s2[0]){
        dp[m][n]=1+longestCommonSubsequence(s1.substr(1),s2.substr(1),dp);
        return dp[m][n];
    }
    
	else{
        int x=longestCommonSubsequence(s1,s2.substr(1),dp);
        int y=longestCommonSubsequence(s1.substr(1),s2,dp);
        dp[m][n]=max(x,y);
        return dp[m][n];
    }
}
int longestCommonSubsequence(string s1, string s2) {
	int m=s1.size();
	int n=s2.size();
	int** output=new int*[m+1];
	for(int i=0;i<=m;i++){
		output[i]=new int[n+1];
		for(int j=0;j<=n;j++){
			output[i][j]=-1;
		}
	}
	return longestCommonSubsequence(s1,s2,output);
}

//recursively
int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        if(s1.size()==0 || s2.size()==0){
            return 0;
        }
        
        if(s1[0]==s2[0]){
            return 1+lcs(x,y,s1.substr(1),s2.substr(1));
        }
        else{
            int x=lcs(x,y,s1,s2.substr(1));
            int y=lcs(x,y,s1.substr(1),s2);
            return max(x,y);
        }
    }


int main(){
	cout<<lcs_DP("abcd","bcde");
}
