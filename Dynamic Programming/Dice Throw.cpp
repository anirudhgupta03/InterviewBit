int mod;
int solve(int A, int B, int C, vector<vector<int>> &dp){
    if(A == 0 && C == 0){
        return 1;
    }
    if(A == 0 || C == 0 || C < A || C > A*B){
        return 0;
    }
    if(dp[A][C] != -1){
        return dp[A][C];
    }
    int cnt = 0;
    for(int i = 1; i <= B; i++){
        if(C - i >= 0){
            cnt = (cnt + solve(A - 1, B, C - i, dp))%mod;
        }
    }
    return dp[A][C] = cnt;
}
int Solution::findDiceSum(int A, int B, int C) {
    if(C < A){
        return 0;
    }
    mod = 1e9 + 7;
    vector<vector<int>> dp(A + 1, vector<int>(C + 1, -1));
    return solve(A,B,C,dp);
}
