vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    
    int n = A.size();
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
            int sum = A[i] + B[j];
            
            if(i == 0) pq.push(sum);
            else if(pq.top() < sum){
                pq.pop();
                pq.push(sum);
            }
            else{
                break;
            }
        }
    }
    
    vector<int> res;
    
    while(pq.size()){
        res.push_back(pq.top());
        pq.pop();
    }
    reverse(res.begin(),res.end());
    return res;
    
}
