//Time Complexity - O(n*n)
//Space Complexity - O(n*n)
int solve(int x, int y, vector<vector<int>> &A, vector<vector<int>> &dp){
    
    if(x == A.size()){
        return 0;
    }
    
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    
    int a = solve(x+1,y,A,dp);
    int b = solve(x+1,y+1,A,dp);
    
    return dp[x][y] = min(a,b) + A[x][y];
}
int Solution::minimumTotal(vector<vector<int> > &A) {
    
    int n = A.size();
    
    vector<vector<int>> dp(n,vector<int>(n,-1));
    
    return solve(0,0,A,dp);
}

//Time Complexity - O(n*n)
//Space Complexity - O(n)
//Ref: https://www.youtube.com/watch?v=kXx2eB2B2kQ
int Solution::minimumTotal(vector<vector<int> > &A) {
    
    int n = A.size();

    int dp[n];

    for(int i = 0; i < n; i++){
        dp[i] = A[n-1][i];
    }
    
    for(int i = n - 2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            dp[j] = min(dp[j],dp[j+1]) + A[i][j];
        }
    }
    
    return dp[0];
}
