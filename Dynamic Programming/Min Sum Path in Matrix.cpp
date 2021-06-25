//Top-Down Approach
int dx[2] = {0,1};
int dy[2] = {1,0};
int solve(int x, int y, vector<vector<int>> &A, vector<vector<int>> &dp){
    
    if(x == A.size() - 1 && y == A[0].size() - 1){
        return A[x][y];
    }
    
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    
    int temp = INT_MAX;
    
    for(int i = 0; i < 2; i++){
        
        int xo = x + dx[i], yo = y + dy[i];
        
        if(xo < A.size() && yo < A[0].size()){
            
            int t = solve(xo,yo,A,dp);
            
            if(t != INT_MAX){
                temp = min(temp,t + A[x][y]);
            }
        }
    }
    return dp[x][y] = temp;
}
int Solution::minPathSum(vector<vector<int> > &A) {
    
    int n = A.size(), m = A[0].size();
    
    vector<vector<int>> dp(n,vector<int>(m,-1));
    
    return solve(0,0,A,dp);
}
