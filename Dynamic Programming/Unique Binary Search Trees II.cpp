//Application of Catalan Number
int Solution::numTrees(int A) {

    if(A == 1 || A == 2){
        return A;
    }

    int dp[A+1];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= A; i++){

        int lo = 0, hi = i - 1;

        while(lo <= i - 1){
            dp[i] += dp[lo]*dp[hi];
            lo++;
            hi--;
        }
    }
    return dp[A];
}
