//knapsack recursion
int knapsack(int *weights, int *values, int n, int maxWeight){
	if(n==0){
        return 0;
    }
    
    if(weights[0]<=maxWeight){
        return max(values[0]+knapsack(weights+1,values+1,n-1,maxWeight-weights[0]),knapsack(weights+1,values+1,n-1,maxWeight));
    }
    
    else{
        return knapsack(weights+1,values+1,n-1,maxWeight);
    }
}

