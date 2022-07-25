//Ref: https://www.youtube.com/watch?v=l_nR5X9VmaI
//TC - O(n*B)
//SC - O(B)
int Solution::coinchange2(vector<int> &A, int B) {
    
    int mod = 1000007;
    
    int dp[B+1];
    
    memset(dp,0,sizeof(dp));
    
    dp[0] = 1;
    
    for(int i = 0; i < A.size(); i++){
        for(int j = A[i]; j <= B; j++){
            dp[j] = (dp[j] + dp[j-A[i]])%mod;
        }
    }
    return dp[B]%mod;
}

//Alter
//TC - O(n*B)
//SC - O(2*B)
int Solution::coinchange2(vector<int> &A, int B) {

    int n = A.size();
    int dp[2][B + 1];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    int mod = 1000007;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= B; j++){
            if(j == 0){
                dp[1][j] = 1;
            }
            else if(i == 0){
                dp[1][j] = 0;
            }
            else if(A[i - 1] <= j){
                dp[1][j] = (dp[1][j - A[i - 1]] + dp[0][j])%mod;
            }
            else{
                dp[1][j] = dp[0][j];
            }
        }
        for(int j = 0; j <= B; j++){
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
    }
    return dp[0][B];
}

//
#define mod 1000007
int Solution::coinchange2(vector<int> &A, int B) {
    
    int n = A.size();
    
    vector<int> prev(B + 1,0);
    prev[0] = 1;
    
    for(int i = 1; i <= n; i++){
        vector<int> curr(B + 1, 0);
        curr[0] = 1;
        for(int j = 1; j <= B; j++){
            if(A[i - 1] <= j){
                curr[j] = (curr[j - A[i - 1]] + prev[j])%mod;
            }
            else{
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    return prev[B] % mod;
}
