//Method - 1
long long number_of_painters(vector<int> C, int t){
    
    long long count = 1, sum = 0;
    for(auto x : C){
        
        sum += x;
        
        if(sum > t){
            sum = x;
            count++;
        }
    }
    
    return count;
}
int Solution::paint(int A, int B, vector<int> &C) {
    
    int l = INT_MIN;
    long long r = 0;
    
    for(auto x : C){
        r = r+ x;
        l = max(l,x);
    }
    long long ans;
    while(l<=r){
        
        long long mid = (l+r)/2;
        
        if(number_of_painters(C,mid) > A){
            l = mid + 1;
        }
        else if(number_of_painters(C,mid) <= A){
            r = mid - 1;
            ans = mid;
        }
    }
    return (ans*B)%10000003;
}

//Method - 2
#define ll long long
bool isPossible(int t, vector<int> &C, int A){
    
    ll count = 1;
    
    ll sum = 0;
    
    for(int i = 0; i < C.size(); i++){
        
        sum += C[i];
        
        if(sum > t){
            sum = C[i];
            count++;
        }
    }
    
    if(count > A){
        return false;
    }
    return true;
}
int Solution::paint(int A, int B, vector<int> &C) {
    
    int mod = 10000003;
    
    if(A >= C.size()){
        return (*max_element(C.begin(),C.end())*B)%mod;
    }
    
    ll lo = INT_MIN, hi = 0;
    
    for(int i = 0; i < C.size(); i++){
        if(C[i] > lo) lo = C[i];
        hi += C[i];
    }
    ll ans;
    while(lo <= hi){
        
        ll mid = (lo + hi)/2;
        
        if(isPossible(mid,C,A)){
            ans = mid;
            hi = mid -1;
        }
        else{
            lo = mid + 1;
        }
    }
    return (ans*B)%mod;
}
