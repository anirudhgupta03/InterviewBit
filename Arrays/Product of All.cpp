#define ll long long
vector<int> Solution::solve(vector<int> &A) {

    int n = A.size(), mod = 1e9 + 7;

    vector<ll> left(n + 1), right(n + 1);

    left[0] = 1;

    for(int i = 1; i <= n; i++){
        left[i] = (left[i - 1]*A[i - 1])%mod;
    }

    right[n] = 1;

    for(int i = n - 1; i >= 0; i--){
        right[i] = (right[i + 1]*A[i])%mod;
    }

    vector<int> res;
    for(int i = 0; i < n; i++){
        res.push_back((left[i]*right[i + 1])%mod);
    }
    return res;
}
