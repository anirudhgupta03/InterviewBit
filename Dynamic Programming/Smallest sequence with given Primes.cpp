//Ref: https://www.youtube.com/watch?v=rRn1vBH-L-8
//TC - O(D)
//SC - O(D)
vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> dp(D + 1);
    dp[0] = 1;
    int ind1 = 0, ind2 = 0, ind3 = 0;
    int ind = 1;
    while(ind <= D){
        dp[ind] = min({dp[ind1]*A, dp[ind2]*B, dp[ind3]*C});
        if(dp[ind1]*A == dp[ind]) ind1++;
        if(dp[ind2]*B == dp[ind]) ind2++;
        if(dp[ind3]*C == dp[ind]) ind3++; 
        ind++;
    }
    dp.erase(dp.begin());
    return dp;
}
