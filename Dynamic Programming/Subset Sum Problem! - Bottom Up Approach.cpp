int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    int dp[n+1][B+1];
    
    for(int j = 1; j <= B; j++){
        dp[0][j] = 0;
    }
    
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= B; j++){
            
            if(A[i-1] <= j){
                dp[i][j] = dp[i-1][j-A[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][B];
}
//Time Complexity: O(n*B)
//Space Complexity: O(n*B)
