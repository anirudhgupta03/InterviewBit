int solve(int A, vector<int> &dp){
    
    if(A == 0){
        return 1;
    }
    if(A < 0){
        return 0;
    }
    if(dp[A]!= -1){
        return dp[A];
    }
    return dp[A] = solve(A-1,dp) + solve(A-2,dp);
}
int Solution::climbStairs(int A) {
    
    vector<int> dp(A+1,-1);
    
    return solve(A,dp);
}
