//Ref1: https://www.youtube.com/watch?v=fUS9G-WG9SQ
//Ref2: https://youtu.be/Yr441TH97eA?t=923
#define ll long long
#define mod 1000000007

ll fact(ll n){
    ll ans = 1;
    for(ll i = 2; i <= n; i++){
        ans = (ans*i)%mod;
    }
    return ans;
}
ll myPower(ll base, ll exponent){

    if(exponent == 0) return 1 % mod;
    if(exponent == 1) return base % mod;

    ll temp = myPower(base, exponent/2);

    if(exponent % 2 == 0) return (temp*temp)%mod;

    return (((base*temp)%mod)*temp)%mod;
}
int Solution::solve(int A, vector<int> &B) {

    sort(B.begin(), B.end());

    int n = A - B.size();

    vector<int> gaps;
    gaps.push_back(B[0] - 1);

    for(int i = 1; i < B.size(); i++){
        gaps.push_back(B[i] - B[i - 1] - 1);
    }
    gaps.push_back(A - B.back());

    ll ans = fact(n);

    for(int i = 0; i < gaps.size(); i++){
        ans = (ans * myPower(fact(gaps[i]), mod - 2))%mod; 
    }
    ll z = 1;
    for(int i = 0; i < gaps.size(); i++){
        if(i == 0 || i == gaps.size() - 1) continue;
        if(gaps[i] < 2) continue;
        z = (z * myPower(2, gaps[i] - 1))%mod;
    }
    return (ans*z)%mod;
}
