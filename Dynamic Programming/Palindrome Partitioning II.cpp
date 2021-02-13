bool ispalindrome(string s,int start, int end){
        
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    int solve(string s, int i, int j, vector<vector<int>> &dp){
        
        if(i >= j){
            return 0;
        }
        
        if(ispalindrome(s,i,j)){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = INT_MAX;
        
        for(int k = i; k <= j-1; k++){
            
            int left, right;
            
            if(dp[i][k] != -1){
                left = dp[i][k];
            }
            else{
                left = solve(s,i,k,dp);
                dp[i][k] = left;
            }
            
            if(dp[k+1][j] != -1){
                right = dp[k+1][j];
            }
            else{
                right = solve(s,k+1,j,dp);
                dp[k+1][j] = right;
            }
            int temp = left + right + 1;
            ans = min(ans,temp);
        }
        
        return dp[i][j] = ans;
    }

int Solution::minCut(string str) {
    int n = str.size();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        
        for(int i = 0; i < n+1; i++){
            for(int j = 0 ; j < n+1 ; j++){
                dp[i][j] = -1;
            }
        }
        
        return solve(str,0,n-1,dp);
}
