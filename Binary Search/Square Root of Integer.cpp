#define ll long long
int Solution::sqrt(int A) {
    
    ll lo = 1, hi = A;
    
    ll ans;
    
    while(lo <= hi){
        
        ll mid = (lo+hi)/2;
        
        if(mid*mid == A){
            return (int)mid;
        }
        else if(mid*mid < A){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    return (int)ans;
}
