int Solution::canJump(vector<int> &A) {
    
    int n = A.size();
    
    int dp[n];
    
    memset(dp,0,sizeof(dp));
    
    dp[0] = 1;
    
    int cov = 0;
    
    for(int i = 0; i < n - 1; i++){
        
        if(dp[i]){
            for(int  j = cov + 1; j <= i + A[i]; j++){
                if(j < n)
                    dp[j] = 1;
                else
                    break;
            }
            cov = max(cov,i+A[i]);
        }
        else{
            return 0;
        }
    }
    return dp[n-1];
}
