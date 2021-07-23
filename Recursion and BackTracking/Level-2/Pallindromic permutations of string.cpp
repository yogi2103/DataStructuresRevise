#include<iostream>
#include<unordered_map>
using namespace std;


void generatePallindromicPermutation(int cs,int ts,unordered_map<char,int> m,char oddc,string asf){
	if(cs>ts){
		string rev="";
		for(int i=asf.length()-1;i>=0;i--){
			rev+=asf[i]; 
		}
		string res =asf;		
		//for placing the odd character in between all characters
		if(oddc!=' '){
			res+=oddc;
		}
		res+=rev;
		cout<<res<<endl;
		return;
	}
	
	for(auto& it:m){
		//only when the frequency is greater than 0
		if(m[it.first]>0){
			m[it.first]--;
			generatePallindromicPermutation(cs+1,ts,m,oddc,asf+it.first);
			m[it.first]++;	
		}
	}
}

int main(){
	string s;
	cin>>s;
	unordered_map<char,int>m;
	for(int i=0;i<s.length();i++){
		m[s[i]]++;
	}
	
	char odd=' ';
	int odds=0;
	int length=0;
	for(auto& it:m){
		if(it.first%2==1){
			odd=it.first;
			odds++;
		}
		m[it.first]=m[it.first]/2;
		length+=m[it.first];
	}
	//if more than one characters having odd frequency
	if(odds>1){
		cout<<-1<<endl;
		return 0;
	}
	generatePallindromicPermutation(1,length,m,odd,"");
}
