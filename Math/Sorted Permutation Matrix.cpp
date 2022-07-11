//Method - 1
//TC - O(N*N)
//SC - O(N)
#define mod 1000003
#define ll long long
ll myPower(ll base, ll exponent){
    
    if(exponent == 0){
        return 1;
    }
    if(exponent == 1){
        return base % mod;
    }
    ll temp = myPower(base, exponent/2);
    if(exponent % 2 == 0){
        return (temp*temp)%mod;
    }
    else{
        return (((base*temp)%mod)*temp)%mod;
    }
}
int Solution::findRank(string A) {
    
    int len = A.size(), fact = 1;
    
    for(ll i = 1; i <= len - 1; i++){
        fact = (fact*i)%mod;
    }
    ll last = len - 1;
    
    unordered_map<char,int> freq;
    
    for(int i = 0; i < A.size(); i++){
        freq[A[i]]++;
    }
    
    ll pos = 0;
    for(int i = 0; i < A.size(); i++){
        ll count = 0;
        for(auto &x: freq){
            if(x.first < A[i] && x.second) count++;
        }
        pos = (pos + count*fact)%mod;
        freq[A[i]] = 0;
        fact = (fact*(myPower(last, mod - 2)))%mod;
        last--;
    }
    return (pos + 1)%mod;
}

//Method - 2
//TC - O(N*N)
//SC - O(1)
#define mod 1000003
#define ll long long
ll myPower(ll base, ll exponent){
    
    if(exponent == 0){
        return 1;
    }
    if(exponent == 1){
        return base % mod;
    }
    ll temp = myPower(base, exponent/2);
    if(exponent % 2 == 0){
        return (temp*temp)%mod;
    }
    else{
        return (((base*temp)%mod)*temp)%mod;
    }
}
int Solution::findRank(string A) {
    
    int len = A.size(), fact = 1;
    
    for(ll i = 1; i <= len - 1; i++){
        fact = (fact*i)%mod;
    }
    ll last = len - 1;
    
    ll pos = 0;
    for(int i = 0; i < A.size(); i++){
        ll count = 0;
        for(int j = i + 1; j < A.size(); j++){
            if(A[j] < A[i]) count++;
        }
        pos = (pos + count*fact)%mod;
        fact = (fact*(myPower(last, mod - 2)))%mod;
        last--;
    }
    return (pos + 1)%mod;
}

//Method - 3
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

//Method - 4
//TC - O(NlogN)
//SC - O(N)
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
    vector<int> v;
    for(int i = 0; i < A.size(); i++){
        v.push_back(A[i] - 'a');
    }
    sort(v.begin(), v.end());
    
    for(int i = 0; i < n; i++){
        int count = lower_bound(v.begin(), v.end(), (A[i] - 'a')) - v.begin();
        v.erase(v.begin() + count);
        ans = (ans + (count*fact[n - i - 1])%mod)%mod;
    }
    return (ans + 1)%mod;
}
