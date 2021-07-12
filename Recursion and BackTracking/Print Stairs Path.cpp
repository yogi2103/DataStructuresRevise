#include <iostream>
using namespace std;

void printStairPaths(int n, string psf){
    // write your code here
    if(n<0){
    	return;
	}
    if(n==0){
    	cout<<psf<<endl;
    	return;
	}
	
	printStairPaths(n-1,psf+to_string(1));
	printStairPaths(n-2,psf+to_string(2));
	printStairPaths(n-3,psf+to_string(3));
    
}

int main(){

    int n;
    cin >> n;
    printStairPaths(n, "");
}
