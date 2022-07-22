//Run-Time Error
// problem is because B is given as 10^9 while N is only 500 if B is greater than N then it is simple stock buy and sell in infinite transaction try to optimize there.
int Solution::solve(vector<int> &A, int B) {

    int n = A.size();

    vector<vector<int>> dp(B+1,vector<int>(n,0));

    for(int t = 1; t <= B; t++){
        for(int d = 1; d < n; d++){
            dp[t][d] = dp[t][d-1];

            for(int pd = 0; pd < d; pd++){
                   int temp = dp[t-1][pd];
                   dp[t][d] = max(dp[t][d], A[d]-A[pd] + temp); 
            }  
        }
    }

    return dp[B][n-1]; 
}

//TLE
int Solution::solve(vector<int> &A, int B) {

    int n = A.size();
    
    if(B > n){
        B = n;
    }
    vector<vector<int>> dp(B+1,vector<int>(n,0));

    for(int t = 1; t <= B; t++){
        for(int d = 1; d < n; d++){
            dp[t][d] = dp[t][d-1];

            for(int pd = 0; pd < d; pd++){
                   int temp = dp[t-1][pd];
                   dp[t][d] = max(dp[t][d], A[d]-A[pd] + temp); 
            }  
        }
    }

    return dp[B][n-1]; 
}

//Ref: https://www.youtube.com/watch?v=3YILP-PdEJA&t=71s
//Bottom-Up
//TC - O(B*n)
//SC - O(B*n)
int Solution::solve(vector<int> &A, int B) {

    int n = A.size();
    
    if(B > n){
        B = n;
    }
    vector<vector<int>> dp(B+1,vector<int>(n,0));

    for(int t = 1; t <= B; t++){
        
        int temp = INT_MIN;
        
        for(int d = 1; d < n; d++){
            
            dp[t][d] = dp[t][d-1];

            temp = max(temp, dp[t-1][d-1] - A[d-1]);
            
            dp[t][d] = max(dp[t][d], temp + A[d]); 
        }
    }

    return dp[B][n-1]; 
}

//Bottom-Up
//TC - O(B*n)
//SC - O(n)
int Solution::solve(vector<int> &A, int B) {
    
    if(B > A.size()){
        B = A.size();
    }
    
    vector<int> prev(A.size(),0);
    
    for(int i = 1; i <= B; i++){
        int maxEle = prev[0] - A[0];
        vector<int> curr(A.size(),0); 
        
        for(int j = 1; j < A.size(); j++){
            curr[j] = curr[j - 1];
            curr[j] = max(curr[j], maxEle + A[j]);
            maxEle = max(maxEle, prev[j] - A[j]);
        }
        prev = curr;
    }
    return prev[A.size() - 1];
}
