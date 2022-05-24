#define mod 1000000007
#define ll long long
int Solution::solve(int A) {
    ll fact = 1;
    for(int i = 1; i <= A; i++){
        fact = (fact*i) % mod;
    }
    return (2*fact) % mod;
}
