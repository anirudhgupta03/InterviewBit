//Ref: https://www.youtube.com/watch?v=FBQbm26tSzA
//Method - 1
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

//Method - 2
int dx[2] = {1,0};
int dy[2] = {0,1};
int solve(int x, int y, vector<vector<int>> &dp, vector<vector<int>> &A){

    if(x == A.size() - 1 && y == A[0].size() - 1){
        if(A[x][y] <= 0){
            return -1*A[x][y] + 1;
        }
        else{
            return 1;
        }
    }

    if(dp[x][y] != -1){
        return dp[x][y];
    }

    int ans = INT_MAX;

    for(int i = 0; i < 2; i++){
        int xo = x + dx[i], yo = y + dy[i];
        if(xo < A.size() && yo < A[0].size()){
            ans = min(ans, solve(xo,yo,dp,A));
        }
    }
    return dp[x][y] = max(1, ans - A[x][y]);
}
int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    
    int m = A.size(), n = A[0].size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return solve(0,0,dp,A);
}
