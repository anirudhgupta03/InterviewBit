int Solution::solve(vector<int> &A, int B) {
    
    priority_queue<int> pq;
    
    for(int i = 0; i < A.size(); i++){
        pq.push(A[i]);
    }
    
    int count = 0, profit = 0;
    
    while(count != B && pq.top() != 0){
        
        profit += pq.top();
        
        int temp = pq.top();
        
        temp--;
        
        pq.pop();

        pq.push(temp);
        
        count++;
    }
    
    return profit;
}
