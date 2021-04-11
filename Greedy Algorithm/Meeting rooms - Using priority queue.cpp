int Solution::solve(vector<vector<int> > &A) {
    
    int n = A.size();
    
    vector<int> start(n);
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i = 0; i < n; i++){
        
        start[i] = A[i][0];
        pq.push(A[i][1]);
    }
    
    sort(start.begin(),start.end());
    //sort(end.begin(),end.end());
    
    int count = 1;
    
    int i = 1, j = 0;
    
    while(i < n){
          
        if(start[i] >= pq.top()){
            i++;
            pq.pop();
        }
        else{
            count++;
            i++;
        }
    }
    return count;
}
