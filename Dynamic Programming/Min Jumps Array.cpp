int Solution::jump(vector<int> &A) {
    
    int n = A.size();
    
    if(n == 1){
        return 0;
    }
    int dp[n];
    
    memset(dp,0,sizeof(dp));
    
    int cov = 0;
    
    for(int i = 0; i < n - 1; i++){
        
        if(i == 0 || dp[i]){
            for(int j = cov + 1; j <= i + A[i]; j++){
                if(j < n){
                    dp[j] = dp[i] + 1;
                }
                else{
                    break;
                }
                cov = max(cov,i + A[i]);
            }
        }
        else{
            return -1;
        }
    }
    
    if(!dp[n-1]){
        return -1;
    }
    return dp[n-1];
}
