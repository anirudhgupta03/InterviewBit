//Ref: https://www.youtube.com/watch?v=jFZmBQ569So
#define ll long long
int Solution::numDecodings(string A) {
    
    if(A[0] == '0'){
        return 0;
    }
    int n = A.size();
    
    int mod = 1e9 + 7;
    
    ll dp[n];
    
    dp[0] = 1;
    
    for(int i = 1; i < n; i++){
        
        char curr = A[i], prev = A[i-1];
        
        if(curr == '0' && prev == '0'){
            dp[i] = 0;
        }
        else if(curr == '0' && prev != '0'){
            
            if(prev == '1' || prev == '2'){
                if(i > 1){
                    dp[i] = dp[i-2]%mod;   
                }
                else{
                    dp[i] = 1;
                }
            }
            else{
                dp[i] = 0;
            }
        }
        else if(curr != '0' && prev == '0'){
            dp[i] = dp[i-1];
        }
        else if(curr != '0' && prev != '0'){
            
            dp[i] = dp[i-1];
            
            if(stoi(A.substr(i-1,2)) <= 26){
                if(i > 1)
                dp[i] = (dp[i] + dp[i-2])%mod;
                else{
                    dp[i] += 1;
                }
            }
        }
    }
    return dp[n-1]%mod;
}
//TC - O(n)
//SC - O(n)
#define ll long long
int Solution::numDecodings(string A) {

    int mod = 1e9 + 7;
    int n = A.size();

    if(A[0] == '0'){
        return 0;
    }
    vector<ll> dp(n);
    dp[0] = 1;

    for(int i = 1; i < n; i++){
        if(A[i] == '0'){
            if(A[i - 1] == '1' || A[i - 1] == '2'){
                if(i - 2 >= 0){
                    dp[i] = dp[i - 2];
                }
                else{
                    dp[i] = 1;
                }
            }
            else{
                dp[i] = 0;
            }
        }
        else{
            dp[i] = dp[i - 1];
            if(A[i - 1] == '1'){
                if(i - 2 >= 0){
                    dp[i] = (dp[i] + dp[i - 2])%mod;
                }
                else{
                    dp[i] = (dp[i] + 1)%mod;
                }
            }
            else if(A[i - 1] == '2'){
                if(A[i] >= '0' && A[i] <= '6'){
                    if(i - 2 >= 0){
                    dp[i] = (dp[i] + dp[i - 2])%mod;
                    }
                    else{
                        dp[i] = (dp[i] + 1)%mod;
                    }
                }
            }
        }
    }
    return dp[n - 1]%mod;
}
