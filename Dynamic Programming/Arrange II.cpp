int solve(int ind, string A, int B, int w[], int b[], vector<vector<int>> &dp){
    
    if(ind == A.size() && B == 0){
        return 0;
    }
    
    if(ind == A.size() || B == 0){
        return INT_MAX;
    }
    
    if(dp[ind][B] != -1){
        return dp[ind][B];
    }
    
    int mn = INT_MAX;
    
    for(int i = ind; i < A.size(); i++){
        
        int temp = solve(i+1,A,B - 1,w,b,dp);
        
        if(temp != INT_MAX){
            temp += (w[i+1]-w[ind])*(b[i+1]-b[ind]);
        }
        
        mn = min(mn,temp);
    }
    
    return dp[ind][B] = mn;
}
int Solution::arrange(string A, int B) {
    
    int n = A.size();
    
    if(B > n){
        return -1;
    }
    
    if(B == n){
        return 0;
    }
    
    int w[n+1], b[n+1];
    memset(w,0,sizeof(w));
    memset(b,0,sizeof(b));
    
    w[0] = 0;
    b[0] = 0;
    
    for(int i = 1; i <= n; i++){
        
        if(A[i - 1] == 'W'){
            w[i] = w[i-1] + 1;
            b[i] = b[i-1];
        }
        else{
            b[i] = b[i-1] + 1;
            w[i] = w[i-1];
        }
    }
    vector<vector<int>> dp(n,vector<int>(B+1,-1));
    return solve(0,A,B,w,b,dp);
}
