//Ref: https://www.youtube.com/watch?v=Lm38EAoDc7c
int Solution::solve(const vector<int> &A) {
    
    int n = A.size();
    
    if(n <= 2){
        return n;
    }
    
    vector<unordered_map<int,int>> dp(n);
    int maxAP = 2;
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            
            int diff = A[j] - A[i];
            
            if(dp[i].find(diff) != dp[i].end()){
                dp[j][diff] = dp[i][diff] + 1;
            }
            else{
                dp[j][diff] = 2;
            }
            maxAP = max(maxAP,dp[j][diff]);
        }
    }
    return maxAP;
}
