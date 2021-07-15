#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc,int dr, int dc) {
	
	if(sr==dr && sc==dc){
		vector<string>v;
		v.push_back("");
		return v;
	}
	
	vector<string>path;
	vector<string> hpath;
	if(sc<dc){
		for(int i=1;i<=dc;i++){
			hpath=getMazePaths(sr,sc+i,dr,dc);
			for(auto& it: hpath){
				path.push_back("h"+to_string(i)+it);
			}	
		}	
	}
	
	vector<string> vpath;
	if(sr<dr){
		for(int i=1;i<=dr;i++){
			vpath=getMazePaths(sr+i,sc,dr,dc);
			for(auto& it: vpath){
				path.push_back("v"+to_string(i)+it);
			}	
		}	
	}
	
	vector<string> dpath;
	if(sr<dr && sc<dc){
		for(int i=1;i<=dr&& i<=dc;i++){
			dpath=getMazePaths(sr+i,sc+i,dr,dc);	
			for(auto& it: dpath){
				path.push_back("d"+to_string(i)+it);
			}	
		}	
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
