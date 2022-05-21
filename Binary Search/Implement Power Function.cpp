//Method - 1
#define ll long long
ll myPower(ll x, ll n, ll d){

    if(n == 0) return 1 % d;
    if(n == 1) return (x % d + d) % d;

    ll temp;
    if(n % 2 == 0){
        temp = myPower(x, n/2, d);
        return (temp*temp)%d;
    } 
    temp = myPower(x, (n - 1)/2, d);
    return ((((x*temp)%d)*temp)%d + d)%d;
}
int Solution::pow(int x, int n, int d) {
    return myPower(x, n, d);
}

//Method - 2
#define ll long long
ll power(int base, int exponent, int d){
    
    if(exponent == 0){
        return 1;
    }
    if(exponent == 1){
        return base%d;
    }
    
    if(exponent%2==0){
        ll ans = power(base,exponent/2,d)%d;
        return (ans*ans)%d;
    }
    else{
        ll ans = power(base,(exponent-1)/2,d);
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
