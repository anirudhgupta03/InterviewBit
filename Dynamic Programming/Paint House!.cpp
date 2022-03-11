//Ref: https://www.youtube.com/watch?v=kh48JLieeW8
//Method - 1
//TC - O(n*3)
//SC - O(n*3)
int paint(int n,int adj, vector<vector<int>> &A, vector<vector<int>> &dp){
    
    if(n == 0){
        return dp[n][adj] = 0;
    }
    
    if(dp[n][adj] != -1){
        return dp[n][adj];
    }
    
    if(adj == 0){
        return dp[n][adj] = min(paint(n-1,1,A,dp) + A[n-1][1], paint(n-1,2,A,dp)+ A[n-1][2]);
    }
    else if(adj == 1){
        return dp[n][adj] = min(paint(n-1,0,A,dp) + A[n-1][0], paint(n-1,2,A,dp) + A[n-1][2]);
    }
    else{
        return dp[n][adj] = min(paint(n-1,0,A,dp) + A[n-1][0], paint(n-1,1,A,dp) + A[n-1][1]);
    }
}
int Solution::solve(vector<vector<int> > &A) {
    
    int n = A.size();
    
    vector<vector<int>> dp(n+1,vector<int>(3,-1));
    
    return min(paint(n,0,A,dp), min(paint(n,1,A,dp), paint(n,2,A,dp)));
}
//Method - 2
//Top-Down
//TC - O(n*3)
//SC - O(n*3)
int paint(int ind, int col, vector<vector<int>> &A,  vector<vector<int>> &dp){

    if(ind == A.size() - 1){
        return A[ind][col];
    }
    
    if(dp[ind][col] != -1){
        return dp[ind][col];
    }
    
    int ans = INT_MAX;
    
    for(int i = 0; i < 3; i++){
        if(i == col) continue;
        ans = min(ans, paint(ind+1, i, A, dp) + A[ind][col]);
    }
    
    return dp[ind][col] = ans;
}
int Solution::solve(vector<vector<int> > &A) {

    int n = A.size();
    
    vector<vector<int>> dp(n,vector<int>(3,-1));
    
    int minCost = INT_MAX;

    for(int i = 0; i < 3; i++){
        minCost = min(minCost, paint(0,i,A,dp));
    }
    return minCost;
}

//Method - 3
//Bottom-Up
//TC - O(n*3)
//SC - O(n*3)
int Solution::solve(vector<vector<int> > &A) {

    int n = A.size();
    
    int dp[3][n];

    dp[0][0] = A[0][0], dp[1][0] = A[0][1], dp[2][0] = A[0][2];

    for(int i = 1; i < n; i++){

        dp[0][i] = min(dp[1][i-1],dp[2][i-1]) + A[i][0];
        dp[1][i] = min(dp[0][i-1],dp[2][i-1]) + A[i][1];
        dp[2][i] = min(dp[0][i-1],dp[1][i-1]) + A[i][2];
    }

    return min({dp[0][n-1],dp[1][n-1],dp[2][n-1]});
}

//Method - 4
//Optimal
//TC - O(n*3)
//SC - O(1)
int Solution::solve(vector<vector<int> > &A) {

    int n = A.size();
    int dp[3][n];

    int r = A[0][0];
    int b = A[0][1];
    int g = A[0][2];

    for(int j = 1; j < n; j++){
        int tr = A[j][0] + min(b, g);
        int tb = A[j][1] + min(r, g);
        int tg = A[j][2] + min(r, b);
        r = tr;
        b = tb;
        g = tg;
    }
    return min({r, b, g});
}
