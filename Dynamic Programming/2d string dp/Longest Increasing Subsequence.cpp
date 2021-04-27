int Solution::lis(const vector<int> &A) {
    
    int n = A.size();
    vector<int> dp(n,1);
    
    for(int i = 1; i < n; i++){
        for(int j = i - 1; j >= 0; j--){
            
            if(A[j] < A[i]){
                dp[i] = max(dp[j]+1,dp[i]);
            }
        }
    }
    
    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        ans = max(ans,dp[i]);
    }
    
    return ans;
}
