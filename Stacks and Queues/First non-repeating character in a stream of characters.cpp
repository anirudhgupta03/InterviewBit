string Solution::solve(string A) {
    
    int alpha[26] = {0};
    
    queue<char> q;
    
    string B;
    
    for(int i = 0; i < A.size(); i++){
        
        q.push(A[i]);
        alpha[A[i]-97]++;
        
        while(!q.empty() && alpha[q.front()-97] > 1){
            q.pop();
        }
        
        if(q.empty()){
            B.push_back('#');
        }
        else{
            B.push_back(q.front());
        }
        
    }
    return B;
}
