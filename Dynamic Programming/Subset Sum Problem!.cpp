//Recursive Approach
//Time Complexity - O(2^n)
//Space Complexity - O(1)
bool isPresent(int ind, int n, int B, vector<int> &A){
    
    if(B == 0){
        return true;
    }
    if(ind == n){
        return false;
    }
    
    if(A[ind] <= B){
        return isPresent(ind+1,n,B-A[ind],A) || isPresent(ind+1,n,B,A);
    }
    else{
        return isPresent(ind+1,n,B,A);
    }
}
int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    
    return isPresent(0,n,B,A);
}

//Top-Down Approach
//Time Complexity - O(n*B)
//Space Complexity - O(n*B)
bool isPresent(int n, int B, vector<int> &A, vector<vector<int>> &dp){
    
    if(n == 0 && B == 0){
        return dp[n][B] = 1;
    }
    if(n == 0){
        return dp[n][B] = 0;
    }
    if(B == 0){
        return dp[n][B] = 1;
    }
    
    if(dp[n][B] != -1){
        return dp[n][B];
    }
    if(A[n-1] <= B){
        return dp[n][B] = isPresent(n-1,B-A[n-1],A,dp) || isPresent(n-1,B,A,dp);
    }
    else{
        return dp[n][B] = isPresent(n-1,B,A,dp);
    }
}
int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    
    vector<vector<int>> dp(n+1,vector<int>(B+1,-1));
    
    return isPresent(n,B,A,dp);
}

//Bottom-Up Approach
//Time Complexity - O(n*B)
//Space Complexity - O(n*B)
int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    int dp[n+1][B+1];
    
    for(int j = 1; j <= B; j++){
        dp[0][j] = 0;
    }
    
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= B; j++){
            
            if(A[i-1] <= j){
                dp[i][j] = dp[i-1][j-A[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][B];
}
