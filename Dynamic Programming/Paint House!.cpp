//Ref: https://www.youtube.com/watch?v=kh48JLieeW8
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

//Top-Down
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
