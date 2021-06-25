//Top-Down Approach
int dx[2] = {0,1};
int dy[2] = {1,0};
int incrPath(int x, int y, vector<vector<int>> &A, vector<vector<int>> &dp){
    
    if(x == A.size() - 1 && y == A[0].size() - 1){
        return 0;
    }

    if(dp[x][y] != -1){
        return dp[x][y];
    }
    
    int mn = INT_MIN;
    
    for(int i = 0; i < 2; i++){
        
        int newx = x + dx[i], newy = y + dy[i];
        
        if(newx < A.size() && newy < A[0].size()){
            if(A[newx][newy] > A[x][y]){
                
                int t = incrPath(newx, newy, A, dp);
                if(t != INT_MIN)
                mn = max(mn, t + 1);
            }
        }
    }
    
    return dp[x][y] = mn;
}
int Solution::solve(vector<vector<int> > &A) {
    
    int m = A.size(), n = A[0].size();
    
    vector<vector<int>> dp(m,vector<int>(n,-1));
    
    int temp = incrPath(0,0,A,dp);
    
    if(temp == INT_MIN){
        return -1;
    }
    return temp + 1;
}
