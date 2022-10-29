//Ref: https://www.youtube.com/watch?v=gt46R1opCVw
//Method - 1
#define mod 1000000007
#define ll long long
ll findProductOfDivisors(int num){
    ll prod = 1;
    for(int i = 1; i * i <= num; i++){
        if(num % i == 0){
            prod = (prod * i) % mod;
            if(num / i != i) prod = (prod * (num/i)) % mod;
        }
    }
    return prod % mod;
}
bool cmp(pair<ll,ll> &p1, pair<ll,ll> &p2){
    return p1.second > p2.second;
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {

    int n = A.size();

    vector<ll> ngl(n), ngr(n);

    ngl[0] = -1;
    stack<ll> st;
    st.push(0);

    for(int i = 1; i < n; i++){
        if(A[i] < A[st.top()]){
            ngl[i] = st.top();
        }
        else{
            while(!st.empty() && A[i] >= A[st.top()]){
                st.pop();
            }
            if(st.empty()){
                ngl[i] = -1;
            }
            else{
                ngl[i] = st.top();
            }
        }
        st.push(i);
    }

    while(!st.empty()) st.pop();

    ngr[n - 1] = n;
    st.push(n - 1);

    for(int i = n - 2; i >= 0; i--){
        if(A[i] <= A[st.top()]){
            ngr[i] = st.top();
        }
        else{
            while(!st.empty() && A[i] > A[st.top()]){       //https://youtu.be/gt46R1opCVw?t=501
                st.pop();
            }
            if(st.empty()){
                ngr[i] = n;
            }
            else{
                ngr[i] = st.top();
            }
        }
        st.push(i);
    }

    vector<pair<ll,ll>> temp;
    ll count = 0;

    for(int i = 0; i < n; i++){
        count = (ngr[i] - i)*(i - ngl[i]);
        ll productOfDivisors = findProductOfDivisors(A[i]);
        temp.push_back({count, productOfDivisors});
    }

    sort(temp.begin(), temp.end(), cmp);

    // for(int i = 0; i < temp.size(); i++){
    //     cout << temp[i].second << " ";
    // }
    // cout << endl;
    vector<ll> prefix(n,0);
    prefix[0] = temp[0].first;

    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i - 1]+ temp[i].first;
        // cout << prefix[i] << " ";
    }
    // cout << endl;
    vector<int> res;

    for(int i = 0; i < B.size(); i++){
        int lo = 0, hi = n - 1, ind;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(B[i] == prefix[mid]){
                ind = mid;
                break;
            }
            else if(B[i] < prefix[mid]){
                ind = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        res.push_back(temp[ind].second);
    }
    return res;
}

//Method - 2
#define mod 1000000007
#define ll long long
bool cmp(pair<ll,ll> &p1, pair<ll,ll> &p2){
    return p1.first > p2.first;
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    
    int n = A.size();
    
    vector<int> ngl(n), ngr(n);
    
    stack<int> st;
    
    ngl[0] = -1;
    st.push(0);
    
    for(int i = 1; i < n; i++){
        if(A[st.top()] > A[i]){
            ngl[i] = st.top();
        }
        else{
            while(!st.empty() && A[i] >= A[st.top()]){
                st.pop();
            }
            if(st.empty()){
                ngl[i] = -1;
            }
            else{
                ngl[i] = st.top();
            }
        }
        st.push(i);
    }
    
    ngr[n - 1] = n;
    while(!st.empty()){
        st.pop();
    }
    st.push(n - 1);
    
    for(int i = n - 2; i >= 0; i--){
        if(A[i] <= A[st.top()]){
            ngr[i] = st.top();
        }
        else{
            while(!st.empty() && A[i] > A[st.top()]){
                st.pop();
            }
            if(st.empty()){
                ngr[i] = n;
            }
            else{
                ngr[i] = st.top();
            }
        }
        st.push(i);
    }
    
    unordered_map<int,ll> umap;
    
    for(int i = 0; i < n; i++){
        umap[A[i]] += (ll)(i - ngl[i])*(ngr[i] - i);
    }
    
    int maxVal = *max_element(A.begin(), A.end());
    
    vector<ll> prodOfDivisors(maxVal + 1);
    
    for(int i = 1; i <= maxVal; i++){
        prodOfDivisors[i] = i;
    }
    
    for(int i = 2; i <= maxVal; i++){
        for(int j = 2*i; j <= maxVal; j += i){
            prodOfDivisors[j] = (prodOfDivisors[j]*i)%mod;
        }
    }
    vector<pair<ll,ll>> v;
    
    for(auto &x: umap){
        v.push_back({prodOfDivisors[x.first], x.second});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i].first << " " << v[i].second << endl;
    // }
    
    vector<ll> prefix(v.size(), 0);
    prefix[0] = v[0].second;
    
    for(int i = 1; i < v.size(); i++){
        prefix[i] = prefix[i - 1] + v[i].second;
    }
    
    // for(int i = 0; i < v.size(); i++){
    //     cout << prefix[i] << " ";
    // }
    // cout << endl;
    vector<int> res;
    
    for(auto &query: B){
        int lo = 0, hi = prefix.size() - 1, ans;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;   
            if(prefix[mid] >= query){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        res.push_back(v[ans].first);
    }
    return res;
}
