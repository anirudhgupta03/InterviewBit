//Ref: https://www.youtube.com/watch?v=wInXbAHi72g
#define ll long long
int Solution::solve(int A) {
    ll mod = 1e9 + 7;
    ll c3 = 24;
    ll c2 = 12;
    for(int i = 2; i <= A; i++){
        ll temp = (7*c2 + 5*c3)%mod;
        c3 = (10*c2 + 11*c3)%mod;
        c2 = temp % mod;
    }
    return (c2 + c3)%mod;
}
