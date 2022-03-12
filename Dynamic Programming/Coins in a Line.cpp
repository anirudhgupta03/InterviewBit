//Top-Down Approach
//Best of the worst
//TC - O(n*n)
//SC - O(n*n)
#define ll long long
int solve(int lo, int hi, vector<int> &A, vector<vector<ll>> &dp){
    
    if(lo > hi){
        return 0;
    }
    
    if(dp[lo][hi] != -1){
        return dp[lo][hi];
    }
    
    ll a = 0,b = 0,c = 0,d = 0;
    
    a = solve(lo + 2, hi, A, dp) + A[lo];

    b = solve(lo + 1, hi - 1, A, dp) + A[lo];
    
    c = solve(lo, hi - 2, A, dp) + A[hi];

    d = solve(lo + 1, hi - 1, A, dp) + A[hi];
    
    return dp[lo][hi] = max(min(a,b),min(c,d));
}
int Solution::maxcoin(vector<int> &A) {
    
    int n = A.size();
    
    int lo = 0, hi = n - 1;
    
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1));
    
    return solve(lo,hi,A,dp);
}

//Bottom-Up Approach
//Ref: https://www.youtube.com/watch?v=ww4V7vRIzSk
int Solution::maxcoin(vector<int> &arr) {
    
    int n = arr.size();
    
    vector<vector<int>> dp(n,vector<int>(n,0));
    
    for(int g = 0; g < n; g++){
        for(int i = 0, j = g; j < n; i++, j++){
            if(g == 0){
                dp[i][j] = arr[i];
            }
            else if(g == 1){
                dp[i][j] = max(arr[i],arr[j]);
            }
            else{
                int val1 = arr[i] + min(dp[i+2][j], dp[i+1][j-1]);
                int val2 = arr[j] + min(dp[i+1][j-1], dp[i][j-2]);
                
                dp[i][j] = max(val1,val2);
            }
        }
    }
    return dp[0][n-1];
}
