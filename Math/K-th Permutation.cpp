#define ll long long
vector<int> Solution::findPerm(int A, long B) {

    vector<ll> fact(A + 1, LLONG_MAX);
    fact[0] = 1;
    fact[1] = 1;
    
    for(int i = 2; i < A + 1; i++){
        if(i > 20) break;
        else fact[i] = i*fact[i-1];
    }

    vector<int> v(A);
    for(int i = 0; i < A; i++){
        v[i] = i + 1;
    }

    reverse(v.begin(), v.end());

    vector<int> res;
    int i = A - 1;

    while(i >= 0 && fact[i] == LLONG_MAX){
        i--;
        res.push_back(v[v.size() - 1]);
        v.pop_back();
    }

    reverse(v.begin(), v.end());

    while(B){
        int temp = B/fact[i];
        if(B % fact[i] == 0){
            temp--;
        }
        res.push_back(v[temp]);

        v.erase(v.begin() + temp);
        B %= fact[i];
        i--;
    }
    for(int i = v.size() - 1; i >= 0; i--){
        res.push_back(v[i]);
    }
    return res;
}
