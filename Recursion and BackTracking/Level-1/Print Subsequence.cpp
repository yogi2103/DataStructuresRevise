#include<iostream>
using namespace std;

void printSubsequence(string s, string ans){
	
	if(s.length()==0){
		cout<<ans<<endl;
		return;
	}
	
	char ch=s[0];
	string ros=s.substr(1);
	printSubsequence(ros,ans+"");
	printSubsequence(ros,ans+ch);
}

int main(){
	string s;
	cin>>s;
	printSubsequence(s,"");
}
