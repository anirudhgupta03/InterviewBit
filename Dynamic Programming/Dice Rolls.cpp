//TC - O(A)
//SC - O(A)
int mod;
int dp[1000001];
int rec(int A){
    if(A == 0){
        return 1;
    }
    if(dp[A] != -1){
        return dp[A];
    }
    int cnt = 0;
    for(int i = 1; i <= 6; i++){
        if(A - i >= 0){
            cnt = (cnt + rec(A - i))%mod;
        }
    }
    return dp[A] = cnt;
}
int Solution::solve(int A) {
    mod = 1e9 + 7;
    memset(dp,-1,sizeof(dp));
    return rec(A);
}
