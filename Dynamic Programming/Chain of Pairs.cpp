//LIS Implementation
int Solution::solve(vector<vector<int> > &A) {
    
    int n = A.size();
    
    vector<int> dp(n,1);
    
    int ans = 1;
    
    for(int i = 1; i < n; i++){
        
        for(int j = 0; j < i; j++){
            
            if(A[j][1] < A[i][0]){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        ans = max(ans,dp[i]);
    }
    
    return ans;
}
