//Ref: https://www.youtube.com/watch?v=g6OxU-hRGtY
#define mod 1000000007
#define ll long long
int Solution::solve(int A) {
    if(A == 0){
        return 0;
    }

    ll p = 0;
    while((1 << p) <= A){
        p++;
    }
    p--;

    ll bitstill2x = (1 << (p - 1))*p;
    ll msb2xton = A - (1 << p) + 1;
    ll ans = bitstill2x + msb2xton + solve(A - (1 << p));
    return ans%mod;
}
