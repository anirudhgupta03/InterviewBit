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

//Method - 2
#define ll long long
ll recur(int A, int B, vector<vector<ll>> &dp, int mod){
 
    if(A == 0 && B == 0){
        return 1;
    }
    if(A == 0){             //if(B == 0) we can't put this here as we can put in all remaining places zero
        return 0;
    }
 
    if(dp[A][B] != -1){
        return dp[A][B];
    }
 
    ll ans = 0;
    for(int i = 0; i <= 9; i++){
        if(B >= i){
            ans = (ans + recur(A-1,B-i,dp,mod))%mod;
        }
    }
    return dp[A][B] = ans;
}
int Solution::solve(int A, int B) {
 
    if(B > 9*A){
        return 0;
    }
 
    if(B == 0){
        return 0;
    }
 
    int mod = 1e9 + 7;
 
    ll count = 0;
    vector<vector<ll>> dp(A+1,vector<ll>(B+1,-1));
 
    for(int i = 1; i <= 9; i++){
        if(i <= B){
            count = (count + recur(A-1,B-i,dp,mod))%mod;
        }
    }
    return count%mod;
}
