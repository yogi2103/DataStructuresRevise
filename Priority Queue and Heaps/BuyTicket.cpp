#include<queue>
int buyTicket (int *arr, int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    queue<int>q;
    priority_queue<int>pq;
    
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        q.push(i);
    }
    
    int time=0;
    while(true){
        if(pq.top()==arr[q.front()]){
            pq.pop();
            time++;
             if(q.front()==k){
                return time;
            }
            q.pop();
        }
        
        else{
            int top=q.front();
            q.pop();
            q.push(top);
        }
    }
}

