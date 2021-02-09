int paths(int x, int y, int a, int b, vector<vector<int>> &dp){
    
    if(x == a && y == b){
        return 1;
    }
    else if(x == a + 1|| y == b + 1){
        return 0;
    }
    if(dp[x][y]!=-1){
        return dp[x][y];
    }
    else{
        dp[x][y] = paths(x,y+1,a,b,dp)+paths(x+1,y,a,b,dp);
        return dp[x][y];
    }
}

int Solution::uniquePaths(int A, int B) {
    
    vector<vector<int>> dp;
    
    for(int i = 0; i < A; i++){
        vector<int> v;
        for(int j = 0; j < B; j++){
            v.push_back(-1);
        }
        dp.push_back(v);
    }
    
    return paths(0,0,A-1,B-1,dp);
    
}
