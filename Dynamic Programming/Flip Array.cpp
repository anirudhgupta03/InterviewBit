//Similar to Minimum Number of Coins
//In Mimimum Number of Coins problem we were given an unbounded kanpsack and we had to fill it such that we use minimum number of coins to fill it.
//Here is a similar problem in which we are given a sum and we have to find the minimum number of elements(which will be equal to minimum flips) needed to find that sum
//Method - 1
int Solution::solve(const vector<int> &A) {
    
    int n = A.size();
    
    int sum = 0;
    
    for(int i = 0; i < n; i++){
        sum += A[i];
    }
    
    int dp[n+1][sum+1];
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            
            if(i == 0 && j == 0){
                dp[i][j] = 0;
            }
            else if(j == 0){
                dp[i][j] = 0;
            }
            else if(i == 0){
                dp[i][j] = INT_MAX - 1;
            }
            else if(A[i-1] <= j){
                dp[i][j] = min(dp[i-1][j-A[i-1]] + 1, dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    for(int j = sum/2; j >= 0; j--){
        if(dp[n][j] != INT_MAX - 1){
            return dp[n][j];
        }
    }
}

//Method - 2
int Solution::solve(const vector<int> &A) {

    int sum = 0, n = A.size();

    for(int i = 0; i < A.size(); i++){
        sum += A[i];
    }

    sum /= 2;

    int dp[n + 1][sum + 1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum; j++){

            if(j == 0){
                dp[i][j] = 0;
            }
            else if(i == 0){
                dp[i][j] = INT_MAX;
            }
            else if(A[i-1] <= j){
                if(dp[i-1][j-A[i-1]] == INT_MAX){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = min(dp[i-1][j-A[i-1]] + 1, dp[i-1][j]);
                }
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int j = sum; j >= 0; j--){
        if(dp[n][j] != INT_MAX){
            return dp[n][j];
        }
    }
}
