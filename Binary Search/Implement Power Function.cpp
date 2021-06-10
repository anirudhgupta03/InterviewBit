//Method - 1
#define ll long long
int power(int base, int expo, int mod){
    
    if(expo == 0){
        return 1;
    }
    if(expo == 1){
        return (base + mod) % mod;
    }
    
    if(expo % 2 == 0){
        ll p = power(base,expo/2,mod);
        return (p*p)%mod;
    }
    else{
        ll p = power(base,(expo-1)/2,mod);
        
        return ((((p*p)%mod)*base)%mod + mod)%mod;    //To handle negative base we add mod
    }
}
int Solution::pow(int x, int n, int d) {
    
    return power(x,n,d)%d;
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
