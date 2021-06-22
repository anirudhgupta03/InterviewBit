int Solution::adjacent(vector<vector<int> > &A) {
    
    int n = A[0].size();
    
    int a = A[0][0], b = A[1][0];
    
    if(n == 1){
        return max(a,b);
    }
    int c = A[0][1], d = A[1][1];
    
    int max1, max2;
    
    int dp[n];
    
    dp[0] = max(a,b);
    dp[1] = max(c,d);
    
    max1 = dp[0];
    max2 = max(dp[0],dp[1]);    //for 2nd max choose max among first end second
    
    for(int i = 2; i < A[0].size(); i++){
        
        if(i % 2 == 0){
            dp[i] = max(A[0][i],A[1][i]) + max1;
            max1 = max(dp[i],max2);
        }
        else{
            dp[i] = max(A[0][i],A[1][i]) + max2;
            max2 = max(dp[i],max1);
        }
    }
    return max(dp[n-1],dp[n-2]);
}
