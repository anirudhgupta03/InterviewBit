int Solution::firstMissingPositive(vector<int> &A) {
    
    int mx = 0;
    for(int i = 0; i < A.size(); i++){
        mx = max(mx,A[i]);
    }
    
    int cnt[mx+1] ={0};
    for(int i = 0; i < A.size(); i++){
        if(A[i] > 0)
        cnt[A[i]] = 1;
    }
    
    for(int i = 1; i < mx+1; i++){
        if(cnt[i] == 0){
            return i;
        }
    }
    return mx+1;
}
