//Ref: https://youtu.be/tZ7ISzMAYds?t=3110
#define ll long long
#define mod 1000003
ll power(ll base, ll exp){

    if(exp == 0) return 1 % mod;
    if(exp == 1) return base % mod;

    ll temp = power(base, exp/2);
    
    if(exp % 2 == 0) return (temp*temp)%mod;
    
    return (((base*temp)%mod)*temp)%mod;
}
int Solution::findRank(string A) {

    int n = A.size();

    vector<ll> fact(n);

    fact[0] = 1;
    fact[1] = 1;
    for(int i = 2; i < n; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }

    ll ans = 0;

    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = i + 1; j < n; j++){
            if(A[j] < A[i]){
                count++;
            }
        }

        unordered_map<char,int> umap;

        for(int k = i; k < n; k++){
            umap[A[k]]++;
        }

        ll d = 1;

        for(auto x: umap){
            d = (d*fact[x.second])%mod;
        }

        ans = (ans + (count*(fact[n - i - 1] * power(d, mod - 2))%mod)%mod)%mod;
    }
    return (ans + 1)%mod;
}
