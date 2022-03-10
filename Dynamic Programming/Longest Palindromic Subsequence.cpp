//Bottom-Up
//TC - O(N*N)
//SC - O(N*N)
int Solution::solve(string A) {

    string B = A;
    reverse(B.begin(), B.end());
    int len = A.size();

    int dp[len + 1][len + 1];

    for(int i = 0; i <= len; i++){
        for(int j = 0; j <= len; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(A[i - 1] == B[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[len][len];
}
