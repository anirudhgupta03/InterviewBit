//Method - 1
#define ll long long
int Solution::maxSpecialProduct(vector<int> &A) {
    
    vector<ll> ngl;
    vector<ll> ngr;
    
    int n = A.size();
    
    stack<pair<ll,ll>> s;
    s.push({A[0],0});
    
    ngl.push_back(-1);
    
    for(ll i = 1; i < A.size(); i++){
        
        if(s.top().first > A[i]){
            ngl.push_back(s.top().second);
        }
        else{
            
            while(!s.empty() && s.top().first <= A[i]){
                s.pop();
            }
            
            if(s.empty()){
                ngl.push_back(-1);
            }
            else{
                ngl.push_back(s.top().second);
            }
        }
        s.push({A[i],i});
    }
    
    while(s.size()){
        s.pop();
    }
    
    ngr.push_back(-1);
    s.push({A[n-1],n-1});
    
    for(ll i = n - 2; i >= 0; i--){
        
        if(s.top().first > A[i]){
            ngr.push_back(s.top().second);
        }
        else{
            
            while(!s.empty() && s.top().first <= A[i]){
                s.pop();
            }
            
            if(s.empty()){
                ngr.push_back(-1);
            }
            else{
                ngr.push_back(s.top().second);
            }
        }
        s.push({A[i],i});
    }
    reverse(ngr.begin(),ngr.end());
    
    ll ans = 0;
    
    for(ll i = 1; i <= n - 2; i++){
        
        if(ngl[i] != -1 && ngr[i] != -1){
            ans = max(ans,(ngl[i]*ngr[i]));
        }
    }
    return ans%1000000007;
}

//Method - 2
#define ll long long
#define mod 1000000007
int Solution::maxSpecialProduct(vector<int> &A) {

    int n = A.size();

    ll maxProd = 0;

    vector<ll> ngl(n), ngr(n);

    stack<ll> st;
    st.push(0);

    ngl[0] = -1;
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
    st.push(n - 1);
    ngr[n - 1] = -1;

    for(int i = n - 2; i >= 0; i--){
        if(A[i] < A[st.top()]){
            ngr[i] = st.top();
        }  
        else{
            while(!st.empty() && A[i] >= A[st.top()]){
                st.pop();
            }

            if(st.empty()){
                ngr[i] = -1;
            }
            else{
                ngr[i] = st.top();
            }
        }
        st.push(i);
    }

    for(int i = 1; i < n - 1; i++){
        if(ngl[i] != -1 && ngr[i]  != -1){
            maxProd = max(maxProd, ngl[i]*ngr[i]);
        }
    }
    return maxProd%mod;
}
