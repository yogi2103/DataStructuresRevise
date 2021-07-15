#include<iostream>
using namespace std;


    void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
        // write your code here
        
        if(sr>dr || sc>dc){
        	return;
		}
        
        if(sr==dr && sc==dc ){
        	cout<<psf<<endl;
        	return;
		}
        
        //can make column wise jump(horizontal)
        for(int i=1;i<=dc;i++){
			printMazePaths(sr,sc+i,dr,dc,psf+"h"+to_string(i));
		}
		
		//can make row wise jump(vertical)
		for(int i=1;i<=dr;i++){
			printMazePaths(sr+i,sc,dr,dc,psf+"v"+to_string(i));
		}
		
		//can make diagonal jump
		for(int i=1;i<=dr && i<=dc;i++){
			printMazePaths(sr+i,sc+i,dr,dc,psf+"d"+to_string(i));
		}
        
    }

int main() {
        int n ;
        int m ;cin>>n>>m;
        printMazePaths(0, 0, n - 1, m - 1, "");
    }
