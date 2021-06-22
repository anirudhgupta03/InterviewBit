//Ref: https://www.youtube.com/watch?v=l_nR5X9VmaI
int Solution::coinchange2(vector<int> &A, int B) {
    
    int mod = 1000007;
    
    int dp[B+1];
    
    memset(dp,0,sizeof(dp));
    
    dp[0] = 1;
    
    for(int i = 0; i < A.size(); i++){
        for(int j = A[i]; j <= B; j++){
            dp[j] = (dp[j] + dp[j-A[i]])%mod;
        }
    }
    return dp[B]%mod;
}
