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

//Method - 3
//TC - O(m*n)
//SC - O(m*n)
int dx[2] = {1,0};
int dy[2] = {0,1};
int solve(int x, int y, int m, int n, vector<vector<int>> &A, vector<vector<int>> &dp){

    if(x == m - 1 && y == n - 1){
        return 1;
    }

    if(dp[x][y] != -1){
        return dp[x][y];
    }
    
    int minHealth = INT_MAX;
    for(int i = 0; i < 2; i++){
        int xo = x + dx[i], yo = y + dy[i];
        if(xo < m && yo < n){
            int temp = solve(xo, yo, m, n, A, dp);
            if(temp == INT_MAX) continue;
            if(temp + A[xo][yo] > 0){
                minHealth = min(minHealth, max(1, temp - A[xo][yo]));
            }
            else{
                minHealth = min(minHealth, (temp - A[xo][yo]));
            }
        }
    }
    return dp[x][y] = minHealth;
}
int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int m = A.size(), n = A[0].size();
    vector<vector<int>> dp(m, vector<int>(n, - 1));

    int temp = solve(0,0,m,n,A,dp);

    if(temp + A[0][0] > 0){
        return max(1, temp - A[0][0]);
    }
    else{
        return temp - A[0][0];      
    }
}

//Method - 4
int dx[2] = {0,1};
int dy[2] = {1,0};
int solve(int x, int y, int m, int n, vector<vector<int>> &A, vector<vector<int>> &dp){
    
    if(x == m - 1 && y == n - 1){
        if(A[x][y] < 0){
            return 1 - A[x][y];
        }
        else{
            return 1;
        }
    }
    
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    int mh = INT_MAX;
    for(int i = 0; i < 2; i++){
        int xo = x + dx[i], yo = y + dy[i];
        if(xo >= 0 && yo >= 0 && xo < m && yo < n){
            int hr = solve(xo, yo, m, n, A, dp);
            if(hr - A[x][y] <= 0){
                mh = 1;
            }
            else{
                mh = min(mh, hr - A[x][y]);
            }
        }
    }
    return dp[x][y] = mh;
}
int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int m = A.size(), n = A[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(0, 0, m, n, A, dp);
}
