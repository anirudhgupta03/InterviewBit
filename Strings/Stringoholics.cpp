//Expert Problem
#define ll long long
#define mod 1000000007
ll power(ll base, ll exp){

    if(exp == 0) return 1;
    if(exp == 1) return base%mod;
    
    if(exp % 2 == 0){
        ll temp = power(base, exp/2);
        return (temp*temp)%mod;
    }
    ll temp = power(base, (exp - 1)/2);
    return (((base*temp)%mod)*temp)%mod;
}
int Solution::solve(vector<string> &A) {

    int n = A.size();
    int a[n];

    for(int p = 0; p < n; p++){
        string s = A[p];
        int len = s.size();
        vector<int> lps(s.size());
        lps[0] = 0;
        int j = 0, i = 1;
        while(i < s.size()){
            if(s[i] == s[j]){
                lps[i] = j + 1;
                i++;
                j++;
            }
            else{
                if(j != 0){
                    j = lps[j - 1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        int tempLen = len - lps[len - 1];
        int minLen = len;

        if(minLen % tempLen == 0){
            minLen = tempLen;
        }
        int op = 1;
        ll sum = 1;

        while(1){
            if(sum % minLen == 0) break;
            op++;
            sum += op;
        }
        a[p] = op;
    }
    unordered_map<int,int> umap;

    for(int i = 0; i < n; i++){
        for(int j = 2; j * j <= a[i]; j++){
            int count = 0;
            while(a[i] % j == 0){
                a[i] /= j;
                count++;
            }
            if(count){
                umap[j] = max(umap[j], count);
            }
        }
        if(a[i] > 1){
            umap[a[i]] = max(umap[a[i]], 1);
        }
    }
    ll res = 1;
    for(auto it: umap){
        res = (res* power(it.first, it.second))%mod;
    }
    return res;
}
