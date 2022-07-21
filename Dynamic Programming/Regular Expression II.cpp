//Ref: https://www.youtube.com/watch?v=DJvw8jCmxUU
//Bottom-Up
//TC - O(len1*len2)
//SC - O(len1*len2)
int Solution::isMatch(const string A, const string B) {
    
    int len1 = A.size(), len2 = B.size();
    
    bool dp[len1+1][len2+1];
    
    for(int i = 0; i < len1 + 1; i++){
        for(int j = 0; j < len2 + 1; j++){
            
            if(i == 0 && j == 0){
                dp[i][j] = true;
            }
            else if(j == 0){
                dp[i][j] = false;
            }
            else if(i == 0){
                
                if(B[j-1] == '*'){
                    dp[i][j] = dp[i][j-2];
                }
                else{
                    dp[i][j] = false;
                }
            }
            else if(B[j-1] == '.'){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(B[j-1] == '*'){
                if(A[i-1] == B[j-2] || B[j-2] == '.'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-2];
                }
                else{
                    dp[i][j] = dp[i][j-2];
                }
            }
            else if(B[j-1] == A[i-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = false;
            }
        }
    }
    return dp[len1][len2];
}

//Top-Down
//TC - O(len1*len2)
//SC - O(len1*len2) + O(len1 + len2)
int solve(int i, int j, string A, string B, vector<vector<int>> &dp){
    
    if(i == 0 && j == 0){
        return dp[i][j] = 1;
    }
    if(j == 0){
        return dp[i][j] = 0;
    }
    if(i == 0){
        if(B[j - 1] == '*'){
            return dp[i][j] = solve(i, j - 2, A, B, dp);
        }
        else{
            return dp[i][j] = 0;
        }
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    if(B[j - 1] == '*'){
        dp[i][j] = solve(i, j - 2, A, B, dp);
        if(dp[i][j]) return dp[i][j];
        
        if(B[j - 2] == A[i - 1] || B[j - 2] == '.'){
            dp[i][j] |= solve(i - 1, j, A, B, dp);
        }
        return dp[i][j];
    }
    else if(A[i - 1] == B[j - 1] || B[j - 1] == '.'){
        return dp[i][j] = solve(i - 1, j - 1, A, B, dp);
    }
    else{
        return dp[i][j] = 0;
    }
}
int Solution::isMatch(const string A, const string B) {
    
    int len1 = A.size(), len2 = B.size();
    
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1,-1));
    
    return solve(len1, len2, A, B, dp);
}
