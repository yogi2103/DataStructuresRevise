#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
	
	if(sr==dr && sc==dc){
		vector<string>v;
		v.push_back("");
		return v;
	}
	
	//for horizontal path
	vector<string> hpath;
	if(sc<dc){
		hpath=getMazePaths(sr,sc+1,dr,dc);	
	}
	
	//for vertical path
	vector<string> vpath;
	if(sr<dr){
		vpath=getMazePaths(sr+1,sc,dr,dc);	
	}
	
	vector<string> path;
	for(auto& it:hpath){
		path.push_back("h"+it);
	}
	
	for(auto& it: vpath){
		path.push_back("v"+it);
	}

	return path;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}
