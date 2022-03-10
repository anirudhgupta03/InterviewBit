//Bottom-Up
int Solution::solve(string A, string B) {

    int len1 = A.size(), len2 = B.size();

    int dp[len1 + 1][len2 + 1];

    for(int i = 0; i <= len1; i++){
        for(int j = 0; j <= len2; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(A[i - 1] == B[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[len1][len2];
}

//Recursion + Memoization(Top-Down)
int dp[1005][1005];
int tsolve(int ind1, int ind2, string A, string B){

    if(ind1 == A.size() || ind2 == B.size()){
        return 0;
    }
    if(dp[ind1][ind2] != -1){
        return dp[ind1][ind2];
    }
    int maxLen = 0;
    if(A[ind1] == B[ind2]){
        maxLen = max(maxLen, tsolve(ind1 + 1, ind2 + 1, A, B) + 1);
    }
    else{
        maxLen = max(maxLen, tsolve(ind1 + 1, ind2, A, B));
        maxLen = max(maxLen, tsolve(ind1, ind2 + 1, A, B));
    }
    return dp[ind1][ind2] = maxLen;
}
int Solution::solve(string A, string B) {

    int maxLen = 0, len = 0;
    memset(dp,-1,sizeof(dp));
    return tsolve(0,0,A,B);
}
