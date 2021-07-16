#include<iostream>
using namespace std;

int maxScore(string words[],int size,int farr[],int score[],int index){
	
	if(index==size){
		return 0;
	}
	
	int score_notincluded = 0 + maxScore(words,size,farr,score,index+1);		//No include
	//include
	int scoreword=0;
	string word=words[index];
	bool flag=true;	//true if yes can call be made
	for(int i=0;i<word.length();i++){
		char ch=word[i];
		if(farr[ch-'a']==0){
			flag=false;
		}
		farr[ch-'a']--;
		scoreword+=score[ch-'a'];
	}
	int score_included=0;
	if(flag){
		score_included=scoreword+maxScore(words,size,farr,score,index+1);
	}
	for(int i=0;i<word.length();i++){
		char ch=word[i];
		farr[ch-'a']++;
	}
	return max(score_notincluded,score_included);
}

int main(){
	int n;
	cin>>n;
	string words[n];
	for(int i=0;i<n;i++){
		cin>>words[i];
	}
	int z;
	cin>>z;
	char letters[z];
	for(int i=0;i<z;i++){
		cin>>letters[i];
	}
	int score[26];
	for(int i=0;i<26;i++){
		cin>>score[i];
	}
	int farr[26];
	for(int i=0;i<26;i++){
		farr[i]=0;
	}
	
	for(int i=0;i<z;i++){
		farr[letters[i]-'a']++;
	}
	
	cout<<maxScore(words,n,farr,score,0);
}
