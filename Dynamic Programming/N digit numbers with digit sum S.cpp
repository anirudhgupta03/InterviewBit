//Good Question
#define ll long long
int recur(int sum, int count, int A, int B, vector<vector<int>> &dp, int mod){
    
    if(count == A && sum == B){
        return 1;
    }
    
    if(count == A || sum == B){
        return 0;
    }
    
    if(dp[count][sum] != -1){
        return dp[count][sum];
    }
    ll ans = 0;
    for(int i = 0; i <= 9; i++){
        
        if(sum + i <= B){
            ans = (ans%mod + recur(sum + i, count + 1, A, B, dp, mod)%mod)%mod;
        }
    }
    return dp[count][sum] = ans%mod;
}
int Solution::solve(int A, int B) {
    
    int sum = 0, count = 0, mod = 1000000007;
    
    vector<vector<int>> dp(A+1,vector<int>(B+1,-1));
    
    return recur(sum, count, A, B, dp, mod);
}
