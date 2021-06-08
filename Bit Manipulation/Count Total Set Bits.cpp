//Ref: https://www.youtube.com/watch?v=g6OxU-hRGtY
int Solution::solve(int A) {
    
    if(A == 0){
        return 0;
    }
    
    long long p = 0, ans = 0;
    
    while(pow(2,p) <= A){
        p++;
    }
    p--;
    ans += pow(2,p-1)*p + (A - pow(2,p) + 1) + solve(A - pow(2,p));
    ans %= 1000000007;
    return ans;
}
