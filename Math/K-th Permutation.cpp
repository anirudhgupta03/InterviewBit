//Method - 1
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

//Method - 2
#define ll long long
vector<int> Solution::findPerm(int A, long B) {
    
    vector<ll> fact(A,LLONG_MAX);
    fact[0] = 1;
    
    for(ll i = 1; i < A; i++){
        if(i > 20) break;
        fact[i] = i*fact[i - 1];
    }
    
    vector<ll> temp;
    
    vector<int> res;
    int ind = A - 1, i = 0;
    
    while(ind >= 0 && fact[ind] > B){
        res.push_back(i + 1);
        i++;
        ind--;
    }
    
    while(i < A){
        temp.push_back(i + 1);
        i++;
    }
    
    while(ind){
        int tind = B/fact[ind];
        if(B % fact[ind] == 0){
            tind--;
        }
        res.push_back(temp[tind]);
        temp.erase(temp.begin() + tind);
        B -= tind*fact[ind];
        ind--;
    }
    res.push_back(temp[0]);
    return res;
}
