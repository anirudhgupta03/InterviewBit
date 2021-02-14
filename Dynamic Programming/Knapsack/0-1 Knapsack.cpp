int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    
    int n = A.size();
    int dp[n + 1][C + 1];
    
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < C + 1; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }
    
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < C + 1; j++){
            
            if(B[i-1]<=j){
                dp[i][j] = max(A[i-1] + dp[i-1][j-B[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][C];
}
