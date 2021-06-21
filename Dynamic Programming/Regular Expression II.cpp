//Ref: https://www.youtube.com/watch?v=DJvw8jCmxUU
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
