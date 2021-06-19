//Method - 1
//TLE
//Time Complexity - O(m*n*W)
//Space Complexity - O(n*W)
int knapsack(const vector<int> &B,const vector<int> &C, int W){
    
    int n = B.size();
    
    int dp[n+1][W+1];
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= W; j++){
            
            if(i == 0 && j == 0){
                dp[i][j] = 0;
            }
            else if(i == 0){
                dp[i][j] = INT_MAX - 1001;
            }
            else if(j == 0){
                dp[i][j] = 0;
            }
            else if(B[i-1] <= j){
                dp[i][j] = min(dp[i][j-B[i-1]] + C[i-1],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][W];
}
int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    
    int minCost = 0;
    
    int m = A.size();
    for(int i = 0; i < A.size(); i++){
        minCost += knapsack(B,C,A[i]);
    }
    
    return minCost;
}

//Method - 2
//Similar to Coin Change II LC
//Time Complexity - O(n*W) + O(m)
//Space Complexity - O(n*W)
int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    
    int n = B.size();
    int W = INT_MIN;
    
    for(int i = 0; i < A.size(); i++){
        W = max(W,A[i]);
    }
    
    int dp[n+1][W+1];
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= W; j++){
            
            if(i == 0 && j == 0){
                dp[i][j] = 0;
            }
            else if(i == 0){
                dp[i][j] = INT_MAX - 1001;      //Whole Crux
            }
            else if(j == 0){
                dp[i][j] = 0;
            }
            else if(B[i-1] <= j){
                dp[i][j] = min(dp[i][j-B[i-1]] + C[i-1],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int minCost = 0;
    
    for(int i = 0; i < A.size(); i++){
        minCost += dp[n][A[i]];
    }
    
    return minCost;
}
