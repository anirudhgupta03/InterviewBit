//Method - 1
//TC - O(3*n)
//SC - O(3*n)
int Solution::maxProfit(const vector<int> &A) {

    int n = A.size();

    if(n == 0){
        return 0;
    }
    vector<vector<int>> dp(3,vector<int>(n,0));

    for(int i = 1; i <= 2; i++){
        
        int temp = INT_MIN;

        for(int j = 1; j < n; j++){

            dp[i][j] = dp[i][j-1];

            temp = max(temp, dp[i-1][j-1] - A[j-1]);

            dp[i][j] = max(dp[i][j], temp + A[j]);
        }
    }

    return dp[2][n - 1];
}

//Method - 2
//Ref: https://www.youtube.com/watch?v=wuzTpONbd-0
//TC - O(n)
//SC - O(n)
int Solution::maxProfit(const vector<int> &A) {
    
    int n = A.size();
    
    if(n == 0){
        return 0;
    }
    
    int dp1[n];
    
    int minEle = A[0], maxProfit = 0;
    
    dp1[0] = 0;
    
    for(int i = 1; i < n; i++){
        if(A[i] < minEle){
            minEle = A[i];
        }
        maxProfit = max(A[i] - minEle, maxProfit);
        dp1[i] = maxProfit;
    }
    
    int dp2[n];
    int maxEle = A[n-1];
    maxProfit = 0;
    
    dp2[n - 1] = 0;
    for(int i = n - 2; i >= 0; i--){
        if(A[i] > maxEle){
            maxEle = A[i];
        }
        maxProfit = max(maxEle - A[i], maxProfit);
        dp2[i] = maxProfit;
    }
    
    maxProfit = 0;
    for(int i = 0; i < n; i++){
        maxProfit = max(maxProfit, dp1[i] + dp2[i]);
    }
    return maxProfit;
}

//Top-Down
//LC
//MLE on IB
class Solution {
public:
    int dp[2][100001][2];
    int solve(int count, int ind, int flag, vector<int> &A){

        if(ind == A.size() || count == 2){
            return 0;
        }

        if(dp[count][ind][flag] != -1){
            return dp[count][ind][flag];
        }
        int profit = 0;

        if(flag == 0){
            profit = max(solve(count, ind + 1, 1, A) - A[ind],  solve(count, ind + 1, 0, A));
        }
        else{
            profit = max(solve(count + 1, ind + 1, 0, A) + A[ind], solve(count, ind + 1, 1, A));
        }
        return dp[count][ind][flag] = profit;
    }
    int maxProfit(vector<int>& A) {
        
        memset(dp,-1,sizeof(dp));
        int res = solve(0, 0, 0, A);
        return res == INT_MIN ? 0: res;
    }
};
