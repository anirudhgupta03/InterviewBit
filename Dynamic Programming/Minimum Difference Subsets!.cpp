//Bottom-Up
//TC - O(n*sum)
//SC - O(n*sum)
int Solution::solve(vector<int> &A) {

    int n = A.size();
    int sum = 0;

    for(int i = 0; i < A.size(); i++){
        sum += A[i];
    }

    int dp[n + 1][sum + 1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            if(i == 0 && j == 0){
                dp[i][j] = 1;
            }
            else if(i == 0){
                dp[i][j] = 0;
            }
            else if(j == 0){
                dp[i][j] = 1;
            }
            else if(A[i - 1] <= j){
                dp[i][j] = dp[i - 1][j - A[i - 1]] || dp[i - 1][j];
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for(int j = sum/2; j >= 0; j--){
        if(dp[n][j]){
            return sum - 2*j;
        }
    }
}
