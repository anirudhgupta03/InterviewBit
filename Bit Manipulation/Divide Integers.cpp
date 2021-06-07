//Ref: https://www.youtube.com/watch?v=X2Ko1Jt9bL4
//Ref: https://www.youtube.com/watch?v=bdxJHWIyyqI&t=920s
#define ll long long
int Solution::divide(int A, int B) {
    
    int sign = 0;
    
    ll a = A, b = B;
    
    if(a < 0 && b > 0 || a > 0 && b < 0){
        sign = 1;
    }
    a = abs(a);
    b = abs(b);
    
    ll t = 0, q = 0;
    
    for(int i = 31; i >= 0; i--){
        
        if(t + (b << i) <= a){
            t = t + (b << i);
            q += 1LL << i;      //In case the value exceeds the INT_MAX 
        }
    }
    if(sign) q = -q;
    
    if(q > INT_MAX || q < INT_MIN){
        return INT_MAX;
    }
    
    return q;
}
