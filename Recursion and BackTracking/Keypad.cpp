#include<iostream>
using namespace std;

vector<string> letterCombinationsHelper(string digits,vector<string> bag){
        if(digits.length()==0){
            vector<string> s;
            s.push("");
            return s;
        }
        
        int index=digits[0]-'0';
        string small=bag[index];
        string ros=digits.substr(1);
        vector<string> smalloutput=letterCombinationsHelper(ros,bag);
        vector<string> output;
        for(int i=0;i<small.length();i++){
            for(auto& it: smalloutput){
                output.push_back(small[i]+it);
            }
        }
        return output;
    }
    
vector<string> letterCombinations(string digits) {
        vector<string> bag=["","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"];
        return letterCombinationsHelper(digits,bag);
}
