#include iostream
using namespace std;

int cs(int arr[], int n){
     write your code here
    int dp[n+1];
     for(int i=0;i=n;i++){
        dp[i]=0;
    }
    dp[n]=1;
    for(int i=n-1;i=0;i--){
        for(int j=1;j=arr[i] && i+j=n;j++){
            dp[i]+=dp[i+j];
        }
    }
    return dp[0];
}

int main(){
    int n;
    cinn;
    int arr[n];
    for(int i = 0 ; i  n ;i++){
        cinarr[i];
    }
    coutcs(arr,n)endl;
}
