#include <iostream>
#include<string>
using namespace std;

string codes[] = {"","a", "b", "c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

void printEncoding(string str, string asf){
    // write your code here
    if(str.length()==0){
    	cout<<asf<<endl;
    	return;
	}
	if(str[0]=='0'){
		return;
	}
    int index1=str[0]-'0';
    string ros1=str.substr(1);
    printEncoding(ros1,asf+codes[index1]);
    if(str.length()>=2){
		int index2=(str[0]-'0')*10+(str[1]-'0');
	    if(index2<=26){
			string ros2=str.substr(2);
	    	printEncoding(ros2,asf+codes[index2]);	
		}	
	}
}

int main(){
    string str;
    cin>>str;
    printEncoding(str,"");
    
}
