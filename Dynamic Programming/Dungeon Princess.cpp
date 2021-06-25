//Ref: https://www.youtube.com/watch?v=FBQbm26tSzA
int solve(int x, int y, vector<vector<int>> &A, vector<vector<int>> &dp){
    
    if(x == A.size() || y == A[0].size()){
        return INT_MAX;
    }
    
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    
    int health = min(solve(x+1,y,A,dp), solve(x,y+1,A,dp));
    
    if(health == INT_MAX){
        health = 1;
    }
    
    int res = 0;
    
    if(health - A[x][y] > 0)
        res = health - A[x][y];
    else
        res = 1;
        
    return dp[x][y] = res;
}
int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    
    int m = A.size(), n = A[0].size();
    
    vector<vector<int>> dp(m,vector<int>(n,-1));
    
    return solve(0,0,A,dp);
}
