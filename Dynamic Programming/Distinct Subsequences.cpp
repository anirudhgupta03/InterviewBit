https://www.youtube.com/watch?v=-RDzMJ33nx8
int Solution::numDistinct(string A, string B) {
    
    int n1 = A.size(), n2 = B.size();
    
    int dp[n1+1][n2+1];
    
    for(int i = 0; i <= n1; i++){
        for(int j = 0; j <= n2; j++){
            
            if(i == 0 && j == 0){
                dp[i][j] = 1;
            }
            else if(i == 0){
                dp[i][j] = 0;
            }
            else if(j == 0){
                dp[i][j] = 1;
            }
            else if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n1][n2];
}
