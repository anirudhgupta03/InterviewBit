int power(int A, int B, int C){
    
    if(B == 0){
        return 1;
    }
    if(B == 1){
        return A;
    }
    
    if(B % 2 == 0){
        long long ans = power(A,B/2,C);
        return (ans*ans)%C;
    }
    else{
        long long ans = power(A,(B-1)/2,C);
        return (((A*ans)%C)*ans)%C;
    }
}
int Solution::Mod(int A, int B, int C) {
     
    if(power(A,B,C)<0){
        return (power(A,B,C)+C)%C;
    }
    return power(A,B,C)%C;
}
