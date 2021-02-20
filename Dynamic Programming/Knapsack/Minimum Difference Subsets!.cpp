int Solution::solve(vector<int> &A) {
    
    int sum = 0;
    int n = A.size();
    
    for(auto x : A){
        sum += x;
    }
    
    int dp[n+1][sum+1];
    
    for(int j = 1; j < sum + 1; j++){
        dp[0][j] = 0;
    }
    
    for(int i = 0; i < n + 1; i++){
        dp[i][0] = 1;
    }
    
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < sum + 1; j++){
            
            if(A[i-1] <= j){
                dp[i][j] = dp[i-1][j-A[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int ans = INT_MAX;
    for(int j = 0; j <= sum/2; j++){
        if(dp[n][j]){
            ans = min(ans,sum-2*j);
        }
    }
    return ans;
}
