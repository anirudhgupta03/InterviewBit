int Solution::wordBreak(string A, vector<string> &B) {
    
    int len = A.size();
    int n = B.size();
    
    unordered_set<string> us;
    
    for(int i = 0; i < B.size(); i++){
        us.insert(B[i]);
    }
    
    int dp[len + 1];
    memset(dp,0,sizeof(dp));
    
    dp[0] = 1;
    
    for(int i = 1; i <= len; i++){
        for(int j = i - 1; j >= 0; j--){
            
            string s = A.substr(j,i-j);
            
            if(us.find(s) != us.end()){
                dp[i] = dp[i] || dp[j];   
            }
            
            if(dp[i]){
                break;
            }
        }
    }
    
    if(dp[len]){
        return 1;
    }
    return 0;
}
