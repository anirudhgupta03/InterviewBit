//TC - O(n*n)
//SC - O(n)
#define ll long long
int Solution::findRank(string A) {

    int n = A.size();

    vector<ll> fact(n + 1);

    ll ans = 0, mod = 1000003, k = n - 1;
    fact[0] = 1;
    fact[1] = 1;

    for(int i = 2; i <= n; i++){
        fact[i] = (fact[i - 1] * i)%mod;
    }

    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = i + 1; j < n; j++){
            if(A[j] < A[i]) count++;
        }
        ans = (ans + (count*fact[n - i - 1])%mod)%mod;
    }
    return (ans + 1)%mod;
}
