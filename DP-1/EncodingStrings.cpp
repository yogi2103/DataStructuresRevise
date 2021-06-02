#include<iostream>
using namespace std;

int main(){
	string s;
	cin>>s;
	int dp[s.length()];
	dp[0]=1;
	for(int i=1;i<s.length();i++){
		if(s[i-1]=='0' && s[i]=='0'){
			dp[i]=0; 
		}
		else if(s[i-1]=='0' && s[i]!='0'){
			dp[i]=dp[i-1];
		}
		else if(s[i-1]!='0' && s[i]=='0'){
			if(s[i-1]=='1' && s[i-1]=='2'){
				dp[i]= (i>=2 ? dp[i-2] : 1);	//trivial case suppose we have 21 then only 1 answer which is "u"
			}
			else{
				dp[i]=0;
			}
		}
		else{
			if(s.substr(i-1,i+1)<="26"){
				dp[i]=dp[i-1]+(i>=2 ?dp[i-2] : 1);
			}
			else{
				dp[i]=dp[i-1];
			}
		}
	}
	
	cout<<dp[s.length()-1];
}
