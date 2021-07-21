#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<char>> arr){
	for(auto& it:arr){
		for(auto& z:it){
			cout<<z<<" ";
		}
		cout<<endl;
	}
}

vector<bool> placewordHorizontally(vector<vector<char>>arr, string word, int i, int j){
	vector<bool> wePlaced;
	for(int jj=0; jj<word.length();jj++){
		if(arr[i][j+jj]=='-'){
			arr[i][j+jj]=word[jj];
			wePlaced[jj]=true;
		}
	}
	return wePlaced;
}

void unplacewordHorizontally(vector<vector<char>>arr, vector<bool> wePlaced, int i,int j){
	for(int jj=0; jj<wePlaced.size();jj++){
		//removing the character which we placed only
		if(wePlaced[jj]==true){
			arr[i][j+jj]='-';
		}
	}
}

vector<bool> placewordVertically(vector<vector<char>>arr, string word, int i, int j){
	vector<bool> wePlaced;
	for(int ii=0; ii<word.length();ii++){
		if(arr[i+ii][j]=='-'){
			arr[i+ii][j]=word[ii];
			wePlaced[ii]=true;
		}
	}
	return wePlaced;
}

void unplacewordVertically(vector<vector<char>>arr, vector<bool> wePlaced, int i,int j){
	for(int ii=0; ii<wePlaced.size();ii++){
		//removing the character which we placed only
		if(wePlaced[ii]==true){
			arr[i+ii][j]='-';
		}
	}
}


bool canPlacewordHorizontally(vector<vector<char>>arr, string word,int i,int j){
	if(j-1>=0 && arr[i][j-1]!='+'){
		return false;
	}
	else if(j+word.length()<arr[0].size() && arr[i][j+word.length()]!='+'){
		return false;
	}
	
	for(int jj=0;jj<word.length();jj++){
		
		//if the word length gets out of board
		if(j+jj>=arr[0].size()){
			return false;
		}
		//if we get - or word is equal to our letter
		if(arr[i][j+jj]=='-'|| arr[i][j+jj]==word[jj]){
			continue;
		}
		else{
			return false;
		}
	}
	return true;
}

bool canPlacewordVertically(vector<vector<char>> arr, string word,int i,int j){
	if(i-1>=0 && arr[i-1][j]!='+'){
		return false;
	}
	else if(i+word.length()< arr[0].size() && arr[i+word.length()][j]!='+'){
		return false;
	}
	
	for(int ii=0;ii<word.length();ii++){
		
		//if the word length gets out of board
		if(i+ii>=arr[0].size()){
			return false;
		}
		//if we get - or word is equal to our letter
		if(arr[i+ii][j]=='-'|| arr[i+ii][j]==word[ii]){
			continue;
		}
		else{
			return false;
		}
	}
	return true;
}

void solution(vector<vector<char>>arr, vector<string> words,int vidx){
	
	if(vidx==words.size()){
		print(arr);
		return;
	}
	
	string word=words[vidx];
	for(int i=0;i<words.size();i++){
		for(int j=0;j<words.size();j++){
			if(arr[i][j]=='-' || arr[i][j]== word[0]){
				if(canPlacewordHorizontally(arr,word,i,j)){
					vector<bool>wePlaced=placewordHorizontally(arr,word,i,j);
					solution(arr,words,vidx+1);
					unplacewordHorizontally(arr,wePlaced,i,j);
				}
				if(canPlacewordVertically(arr,word,i,j)){
					vector<bool>wePlaced=placewordVertically(arr,word,i,j);
					solution(arr,words,vidx+1);
					unplacewordVertically(arr,wePlaced,i,j);
				}
			}
		}
	}
}


int main(){
	vector<vector<char>>v(10);
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			char c;
			cin>>c;
			v[i].push_back(c);
		}
	}
	int n;
	cin>>n;
	vector<string> words(n);
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		words.push_back(s);
	}
	solution(v,words,0);
}
