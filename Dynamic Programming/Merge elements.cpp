//Ref: https://www.youtube.com/watch?v=TFdclijv4Mg
int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> prefix(n + 1, 0);
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i - 1] + A[i - 1];
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int diff = 1; diff < n; diff++){
        int i = 0;
        int j = i + diff;
        for(; j < n; j++,i++){
            dp[i][j] = INT_MAX;
            for(int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], prefix[j + 1] - prefix[i] + dp[i][k] + dp[k + 1][j]);
            }
        }
    }
    return dp[0][n - 1];
}
