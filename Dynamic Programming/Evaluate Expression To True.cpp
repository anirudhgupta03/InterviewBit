#define ll long long
#define mod 1003
ll dp[151][151][2];
ll solve(int i, int j, int isTrue, string &exp){
    
    if(i > j) return 0;
    if(i == j){
        if(isTrue){
            return exp[i] == 'T';
        }
        else{
            return exp[i] == 'F';
        }
    }
    if(dp[i][j][isTrue] != -1){
        return dp[i][j][isTrue];
    }
    ll ways = 0;
    for(int k = i + 1; k <= j - 1; k += 2){
        ll lT = solve(i, k - 1, 1, exp);
        ll lF = solve(i, k - 1, 0, exp);
        ll rT = solve(k + 1, j, 1, exp);
        ll rF = solve(k + 1, j, 0, exp);
        
        if(exp[k] == '&'){
            if(isTrue){
                ways = (ways + lT*rT)%mod;
            }
            else{
                ways = (ways + lF*rF + lT*rF + lF*rT)%mod;
            }
        }
        else if(exp[k] == '^'){
            if(isTrue){
                ways = (ways + lT*rF + lF*rT)%mod;
            }
            else{
                ways = (ways + lT*rT + lF*rF)%mod;
            }
        }
        else if(exp[k] == '|'){
            if(isTrue){
                ways = (ways + lT*rF + lF*rT + lT*rT)%mod;
            }
            else{
                ways = (ways + lF*rF)%mod;
            }
        }
    }
    return dp[i][j][isTrue] = ways;
}
int Solution::cnttrue(string A) {
    memset(dp, -1, sizeof(dp));
    return solve(0, A.size() - 1, 1, A);
}
