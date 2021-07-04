//Method - 1
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i = 0; i < B.size(); i++){
        
        pq.push(A[0] + B[i]);
        
        if(pq.size() > C){
            pq.pop();
        }
    }
    
    for(int i = 1; i < A.size(); i++){
        for(int j = 0; j < B.size(); j++){
            
            int sum = A[i] + B[j];
            
            if(sum > pq.top()){
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
    sort(res.begin(),res.end(),greater<int>());
    return res;
}

//Method - 2
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < B.size(); j++){
            
            int sum = A[i] + B[j];
            
            if(pq.size() < C){
                pq.push(sum);
            }
            else{
                
                if(pq.top() < sum){
                    pq.pop();
                    pq.push(sum);
                }
                else{
                    break;
                }
            }
        }
    }
    
    vector<int> res;
    while(pq.size()){
        res.push_back(pq.top());
        pq.pop();
    }
    reverse(res.begin(),res.end());
    return  res;
}
