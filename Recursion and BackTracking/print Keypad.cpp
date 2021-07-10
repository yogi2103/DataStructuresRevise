#include <iostream>
using namespace std;

string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf){
    // write your code here
    if(ques.length()==0){
    	cout<<asf<<endl;
    	return;
	}
	
	int index=ques[0]-'0';
	string small=codes[index];
	string ros=ques.substr(1);
	for(int i=0;i<small.length();i++){
		printKPC(ros,asf+small[i]);
	}
	
}

int main(){
    string str;
    cin >> str;
    printKPC(str, "");
}
