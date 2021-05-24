int countMinStepsToOneHelper(int n,int arr[]){
	if(n<=1){
		return 0;
	}
	if(arr[n]!=-1){
		return arr[n];
	}
	int x=countMinStepsToOneHelper(n-1,arr);
	int y=INT_MAX;
	int z=INT_MAX;
	
	if(n%2==0){
		y=countMinStepsToOneHelper(n/2,arr);
	}
	
	if(n%3==0){
		z=countMinStepsToOneHelper(n/3,arr);
	}
	
	arr[n]=1+min(x,min(y,z));
	return arr[n];
}

int countMinStepsToOne(int n)
{
	//Write your code here
    int arr[n+1];
    for(int i=0;i<=n;i++){
    	arr[i]=-1;
	}
	return countMinStepsToOneHelper(n,arr);
}
