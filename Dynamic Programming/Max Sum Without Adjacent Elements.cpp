//Method - 1
//TC - O(n)
//SC - O(n)
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

//Method - 2
//TC - O(n)
//SC - 0(2*n)
int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    int dp[2][n + 1];
    memset(dp,0,sizeof(dp));

    if(n == 1){
        return max(A[0][0], A[1][0]);
    }
    dp[0][1] = A[0][0];
    dp[1][1] = A[1][0];

    for(int i = 2; i <= n; i++){
        dp[0][i] = max(dp[0][i - 1], max(dp[0][i - 2], dp[1][i - 2]) + A[0][i - 1]);
        dp[1][i] = max(dp[1][i - 1], max(dp[0][i - 2], dp[1][i - 2]) + A[1][i - 1]);
    }
    return max(dp[0][n],dp[1][n]);
}

//Method - 3
//TC - O(n)
//SC - O(n)
int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    int dp[n + 1] = {0};
    if(n == 1){
        return max(A[0][0], A[1][0]);
    }
    dp[1] = max(A[0][0],A[1][0]);

    for(int i = 2; i <= n; i++){
        dp[i] = max(dp[i - 1], max(A[0][i - 1], A[1][i - 1]) + dp[i - 2]);
    }
    return dp[n];
}
