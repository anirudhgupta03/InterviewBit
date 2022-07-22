//Top-Down
class Solution {
public:
    int dp[30001][2];
    int solve(int ind, int flag, vector<int> &A){

        if(ind == A.size()){
            return 0;
        }
        if(dp[ind][flag] != -1){
            return dp[ind][flag];
        }

        int maxprofit = 0;
        if(flag == 0){
            maxprofit = max(solve(ind + 1, 1, A) - A[ind], solve(ind + 1, 0, A));
        }
        else{
            maxprofit = max(solve(ind + 1, 0, A) + A[ind], solve(ind + 1, 1, A));
        }
        return dp[ind][flag] = maxprofit;
    }

    int maxProfit(vector<int>& prices) {
        
        int maxprofit = 0;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, prices);
    }
};

//Bottom-Up
//TC: O(n*2)
//SC: O(n*2)
int Solution::maxProfit(const vector<int> &A) {
    
    int maxprofit = 0;
    
    int dp[A.size() + 1][2];
    dp[A.size()][0] = dp[A.size()][1] = 0;
    
    for(int i = A.size() - 1; i >= 0; i--){
        for(int j = 0; j < 2; j++){
            if(j == 0){
                dp[i][j] = max(dp[i + 1][1] - A[i], dp[i + 1][0]);
            }
            else if(j == 1){
                dp[i][j] = max(dp[i + 1][0] + A[i], dp[i + 1][1]);
            }
        }
    }
    return dp[0][0];
}

//Bottom-Up
//TC: O(n*2)
//SC: O(1)
int Solution::maxProfit(const vector<int> &A) {
    
    int maxprofit = 0;
    
    vector<int> prev(2,0);
    
    for(int i = A.size() - 1; i >= 0; i--){
        vector<int> curr(2,0);
        for(int j = 0; j < 2; j++){
            if(j == 0){
                curr[0] = max(prev[1] - A[i], prev[0]);
            }
            else if(j == 1){
                curr[1] = max(prev[0] + A[i], prev[1]);
            }
        }
        prev = curr;
    }
    return prev[0];
}

//Ref: https://www.youtube.com/watch?v=Q7v239y-Tik
int Solution::maxProfit(const vector<int> &A) {
    
    int profit = 0;
    
    for(int i = 1; i < A.size(); i++){
        
        if(A[i] > A[i-1]){
            profit += A[i] - A[i-1];
        }
    }
    
    return profit;
}
