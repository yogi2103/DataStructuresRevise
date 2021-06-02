#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int building=1;
	int space=1;
	for(int i=2;i<=n;i++){
		int temp=space;
		space=building+space;
		building=temp;
	}
cout<<(building+space)*(building+space);
}
