//Ref: https://www.youtube.com/watch?v=lInhOSvjg6E
int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = INT_MIN;
    for(int i = n; i >= 0; i--){
        for(int j = m; j >= 0; j--){
            if(i == n || j == m){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = A[i][j] + dp[i + 1][j] + dp[i][j + 1] - dp[i + 1][j + 1];
                ans = max(ans, dp[i][j]);
            }
        }
    }
    return ans;
}
