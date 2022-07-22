//Ref: https://www.youtube.com/watch?v=wInXbAHi72g
vector<vector<int>> comb;
#define ll long long
#define mod 1000000007
int dp[4][4][4][100001];
ll rec(int ind, int v1, int v2, int v3, int A){
    
    if(ind == A){
        return 1;
    }
    if(dp[v1][v2][v3][ind] != -1){
        return dp[v1][v2][v3][ind];
    }
    
    ll ans = 0;
    for(int i = 0; i < 36; i++){
        if(comb[i][0] != v1 && comb[i][1] != v2 && comb[i][2] != v3){
            ans = (ans + rec(ind + 1, comb[i][0], comb[i][1], comb[i][2], A))%mod;
        }
    }
    return dp[v1][v2][v3][ind] = ans;
}
int Solution::solve(int A) {
    
    comb.clear();
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                if(i != j && j != k){
                    comb.push_back({i, j, k});
                }
            }
        }
    }
    
    memset(dp, -1, sizeof(dp));
    
    ll ans = 0;
    for(int i = 0; i < 36; i++){
        ans = (ans + rec(1, comb[i][0], comb[i][1], comb[i][2], A))%mod;
    }
    return ans;
}
