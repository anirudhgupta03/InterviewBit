//Method - 1
//TC - O(n*n)
//SC - O(n*n)
int maxPathTriangle(int x, int y, vector<vector<int>> &A, vector<vector<int>> &dp){

    if(x == A.size()){
        return dp[x][y] = 0;
    }

    if(dp[x][y] != -1){
        return dp[x][y];
    }
    
    return dp[x][y] = max(maxPathTriangle(x+1, y, A,dp), maxPathTriangle(x+1,y+1,A,dp)) + A[x][y];
}
int Solution::solve(vector<vector<int> > &A) {

    int n = A.size();
    
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

    return maxPathTriangle(0,0,A,dp);
}

//Method - 2
//TC - O(n*n)
//SC - O(n)
int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();

    vector<int> dp(n);
    dp = A[n - 1];

    for(int i = n - 2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            dp[j] = A[i][j] + max(dp[j], dp[j + 1]);
        }
    }
    return dp[0];
}

//Method - 3
//TC - O(n*n)
//SC - O(1)
int Solution::solve(vector<vector<int> > &A) {

    int n = A.size();

    for(int i = n - 2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            A[i][j] += max(A[i+1][j], A[i+1][j+1]);
        }
    }
    return A[0][0];
}
