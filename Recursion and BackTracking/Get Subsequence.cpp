#include <iostream>
#include <vector>
using namespace std;

vector<string> gss(string s){
    // write your code here
    if(s.size()==0){
    	vector<string> v;
    	v.push_back("");
    	return v;
	}
    char small=s[0];
    string ros=s.substr(1);
    vector<string> smalloutput=gss(ros);
    vector<string> output;
    for(auto& it: smalloutput){
    	output.push_back(it);
	}
	for(auto& it: smalloutput){
		output.push_back(small+it);
	}
//	for(auto& it: smalloutput){
//    	output.push_back(it);
//    	output.push_back(small+it);
//	}
	return output;
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}
