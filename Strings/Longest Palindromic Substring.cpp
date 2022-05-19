string Solution::longestPalindrome(string s) {
    
    int best_len = 0;
        string best_s = "";
        int n = s.length();
        for(int mid = 0; mid < n; mid++) {
            for(int x = 0; mid - x >= 0 && mid + x < n; x++) {
                if(s[mid-x] != s[mid+x]) {
                    break;
                }
                int len = 2 * x + 1;
                if(len > best_len) {
                    best_len = len;
                    best_s = s.substr(mid - x, len);
                }
            }
        }
        for(int mid = 0; mid < n - 1; mid++) {
            for(int x = 1; mid - x + 1 >= 0 && mid + x < n; x++) {
                if(s[mid-x+1] != s[mid+x]) {
                    break;
                }
                int len = 2 * x;
                if(len > best_len) {
                    best_len = len;
                    best_s = s.substr(mid - x + 1, len);
                }
            }
        }
        return best_s;
}
//DP Approach
//Time Complexity - O(N^2)
//Space Complexity - O(N^2)
string Solution::longestPalindrome(string A) {
    
    int len = A.size();
    
    bool dp[len][len];
    
    memset(dp,0,sizeof(dp));
    
    int max_len = 1, l = 0;
    
    for(int i = 0; i < len; i++){
        dp[i][i] = 1;
    }
    
    for(int i = 0; i < len - 1; i++){
        if(A[i] == A[i+1]){
            dp[i][i+1] = 1;
            if(2 > max_len){
                max_len = 2;
                l = i;
            }
        }
    }
    
    int j;
    for(int k = 3; k <= len; k++){
        for(int i = 0; i <= len - k; i++){
            
            j = i + k - 1;
            if(A[i] == A[j] && dp[i+1][j-1]){
                dp[i][j] = 1;
                if(max_len < k){
                    max_len = k;
                    l = i;
                }
            }
        }
    }
    return A.substr(l,max_len);
}

//Method - 3
string Solution::longestPalindrome(string A) {
    int n = A.size();
    if(n == 1) return A;

    bool dp[n][n];      //int dp[n][n] gives MLE
    
    memset(dp,0,sizeof(dp));

    string res;
    res.push_back(A[0]);
    int maxLen = 1;
    for(int i = 0; i < n; i++) dp[i][i] = 1;

    for(int i = n - 2; i >= 0; i--){
        if(A[i] == A[i + 1]){
            maxLen = 2;
            res = A.substr(i,2);
            dp[i][i + 1] = 1;
        }
    }

    for(int i = n - 3; i >= 0; i--){
        for(int j = i + 2; j < n; j++){
            if(A[i] == A[j]){
                dp[i][j] = dp[i + 1][j - 1];
                if(dp[i][j]){
                    if(j - i + 1 >= maxLen){
                        maxLen = j - i + 1;
                        res = A.substr(i, maxLen);
                    }
                }
            }
        }
    }
    return res;
}
