//Top-Down Approach
int dx[2] = {0,1};
int dy[2] = {1,0};
int solve(int x, int y, vector<vector<int>> &A, vector<vector<int>> &dp){
    
    if(x == A.size() - 1 && y == A[0].size() - 1){
        return 1;
    }
    
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    
    int temp = 0;
    
    for(int i = 0; i < 2; i++){
        int xo = x + dx[i], yo = y + dy[i];
        
        if(xo < A.size() && yo < A[0].size() && A[xo][yo] == 0){
            temp += solve(xo,yo,A,dp);
        }
    }
    return dp[x][y] = temp;
}
int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    
    int m = A.size(), n = A[0].size();
    
    if(A[0][0] == 1 || A[m-1][n-1] == 1){
        return 0;
    }
    vector<vector<int>> dp(m,vector<int>(n,-1));
    
    return solve(0,0,A,dp);
}
