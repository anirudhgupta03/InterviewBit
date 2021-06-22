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
