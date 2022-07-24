//Method - 1
bool ispalindrome(string s,int start, int end){
        
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    int solve(string s, int i, int j, vector<vector<int>> &dp){
        
        if(i >= j){
            return 0;
        }
        
        if(ispalindrome(s,i,j)){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = INT_MAX;
        
        for(int k = i; k <= j-1; k++){
            
            int left, right;
            
            if(dp[i][k] != -1){
                left = dp[i][k];
            }
            else{
                left = solve(s,i,k,dp);
                dp[i][k] = left;
            }
            
            if(dp[k+1][j] != -1){
                right = dp[k+1][j];
            }
            else{
                right = solve(s,k+1,j,dp);
                dp[k+1][j] = right;
            }
            int temp = left + right + 1;
            ans = min(ans,temp);
        }
        
        return dp[i][j] = ans;
    }

int Solution::minCut(string str) {
    int n = str.size();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        
        for(int i = 0; i < n+1; i++){
            for(int j = 0 ; j < n+1 ; j++){
                dp[i][j] = -1;
            }
        }
        
        return solve(str,0,n-1,dp);
}

//Method - 2
int minCuts;
int dp[502];
bool isPalindrome(string s){
    int l = 0, r = s.size() - 1;
    while(l < r){
        if(s[l] != s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
int solve(int ind, string &A){
    if(ind == A.size()){
        return -1;
    }
    if(dp[ind] != -1){
        return dp[ind];
    }
    int minCuts = INT_MAX;
    for(int i = ind; i < A.size(); i++){
        if(isPalindrome(A.substr(ind, i - ind + 1))){
            minCuts = min(minCuts, solve(i + 1, A) + 1);
        }
    }
    return dp[ind] = minCuts;
}
int Solution::minCut(string A) {
    memset(dp,-1,sizeof(dp));
    return solve(0,A);
}

//Method - 3
//Best
int dp[502];
int solve(int ind, string &A, vector<vector<int>> &isPalindrome){
        if(ind == A.size()){
            return -1;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        int minCuts = INT_MAX;
        for(int i = ind; i < A.size(); i++){
            if(isPalindrome[ind][i]){
                minCuts = min(minCuts, solve(i + 1, A, isPalindrome) + 1);
            }
        }
        return dp[ind] = minCuts;
}
int Solution::minCut(string s) {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        vector<vector<int>> isPalindrome(n, vector<int>(n,0));
        
        for(int i = 0; i < n; i++){
            isPalindrome[i][i] = 1; 
        }
        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i + 1]){
                isPalindrome[i][i + 1] = 1;
            }
        }
        for(int i = n - 3; i >= 0; i--){
            for(int j = i + 2; j < n; j++){
                if(s[i] == s[j]){
                    isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
                }
            }
        }
        return solve(0,s,isPalindrome);
}

//Method - 4
//Bottom-Up
int Solution::minCut(string A) {
    
    int len = A.size();
    
    vector<vector<bool>> isPalindrome(len, vector<bool>(len, false));
    
    for(int i = 0; i < len; i++){
        isPalindrome[i][i] = true;
    }
    for(int i = 0; i < len - 1; i++){
        if(A[i] == A[i + 1]){
            isPalindrome[i][i + 1] = true;
        }
    }
    
    for(int i = len - 3; i >= 0; i--){
        for(int j = i + 2; j < len; j++){
            if(A[i] == A[j] && isPalindrome[i + 1][j - 1]){
                isPalindrome[i][j] = true;
            }
        }
    }
    vector<int> dp(len + 1, 0);
    
    for(int ind = len - 1; ind >= 0; ind--){
        int minCuts = INT_MAX;
        for(int i = ind; i < len; i++){
            if(isPalindrome[ind][i]){
                minCuts = min(minCuts, dp[i + 1] + 1);
            }
        }
        dp[ind] = minCuts;
    }
    return dp[0] - 1;
}
