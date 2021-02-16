long long pw(int base, int exponent, int d){
    
    if(exponent == 0){
        return 1;
    }
    if(exponent == 1){
        return base%d;
    }
    
    if(exponent%2==0){
        long long ans = pw(base,exponent/2,d)%d;
        return (ans*ans)%d;
    }
    else{
        long long ans = pw(base,(exponent-1)/2,d);
        return ((base*ans)%d*ans)%d;
    }
}
int Solution::pow(int x, int n, int d) {
    
    if(pw(x,n,d) > 0){
        return pw(x,n,d)%d;
    }
    else{
        return (pw(x,n,d) + d)%d;
    }
}
