//Ref: https:www.youtube.com/watch?v=-RDzMJ33nx8
//Bottom-Up
//TC - O(n1*n2)
//SC - O(n1*n2)
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

//Top-Down
int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp){
    
    if(j < 0) return 1;
    if(i < 0 || i < j) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    if(s[i] == t[j]){
        return dp[i][j] = solve(i - 1, j - 1, s, t, dp) + solve(i - 1, j, s, t, dp);
    }
    return dp[i][j] = solve(i - 1, j, s, t, dp);
}
int Solution::numDistinct(string A, string B) {
    
    int len1 = A.size(), len2 = B.size();
    
    vector<vector<int>> dp(len1, vector<int>(len2, -1));
    
    return solve(len1 - 1, len2 - 1, A, B, dp);
}

//Bottom-Up
//1D DP
int Solution::numDistinct(string A, string B) {
    
    int len1 = A.size(), len2 = B.size();
    
    vector<int> prev(len2 + 1, 0);
    
    prev[0] = 1;
    
    for(int i = 1; i <= len1; i++){
        for(int j = len2; j >= 1; j--){
            if(A[i - 1] == B[j - 1]){
                prev[j] = prev[j - 1] + prev[j];
            }
        }
    }
    return (int)prev[len2];
}
