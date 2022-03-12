//Ref: https://www.youtube.com/watch?v=UagRoA3C5VQ
//TC - O(n*m)
//SC - O(n*m)
int Solution::solve(vector<vector<int> > &A) {
    
    int n = A.size(), m = A[0].size();
    
    int dp[n][m];
    
    memset(dp,0,sizeof(dp));
    
    int maxSize = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == n - 1 || j == m - 1){
                if(A[i][j] == 1){
                    dp[i][j] = 1;
                    maxSize = 1;
                }
                else{
                    dp[i][j] = 0;
                }
            }
            
        }
    }
    for(int i = n - 2; i >= 0; i--){
        for(int j = m - 2; j >= 0; j--){       
            if(A[i][j]){
                dp[i][j] = min({dp[i][j+1],dp[i+1][j],dp[i+1][j+1]}) + 1;
                maxSize = max(maxSize, dp[i][j]);
            }
        }
    }
    return maxSize*maxSize;
}
