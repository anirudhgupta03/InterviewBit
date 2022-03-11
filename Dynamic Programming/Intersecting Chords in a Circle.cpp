//Catalan Number
//Ref: https://www.youtube.com/watch?v=qgQg1BcCWBA
//TC - O(A*A)
//SC - O(A)
#define ll long long
int Solution::chordCnt(int A) {
    
    if(A == 1 || A == 2){
        return A;
    }
    
    int mod = 1e9 + 7;
    
    vector<ll> dp(A+1,0);
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3; i <= A; i++){
        
        int l = 0, r = i - 1;
        
        while(l <= i - 1){
            dp[i] = (dp[i] + dp[l]*dp[r])%mod;
            l++;
            r--;
        }
    }
    return dp[A]%mod;
}
