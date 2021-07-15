#include<iostream>
using namespace std;

void printAbbreviation(string str, string asf, int count){
	
	if(str.length()==0){
		if(count==0){
			cout<<asf<<endl;
		}
		else{
			cout<<asf+to_string(count)<<endl;	
		}
		return;
	}
	
	string ros=str.substr(1);
	if(count>0){
		printAbbreviation(ros,asf+to_string(count)+str[0],0);	
	}
	else{
		printAbbreviation(ros,asf+str[0],0);	
	}
	printAbbreviation(ros,asf,count+1);
}

int main(){
	string s;
	cin>>s;
	printAbbreviation(s,"",0);
}
