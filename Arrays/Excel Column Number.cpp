int pw(int base, int exponent){
    if(exponent == 1){
        return base;
    }
    if(exponent == 0){
        return 1;
    }
    
    if(exponent % 2 == 0){
        return pw(base,exponent/2)*pw(base,exponent/2);
    }
    return base*pw(base,(exponent-1)/2)*pw(base,(exponent-1)/2);
}
int Solution::titleToNumber(string A) {
    
    int sum = 0;
    for(int i = A.size()-1; i>=0; i--){
        sum = sum + pw(26,A.size()-1-i)*(A[i]-64);
    }
    
    return sum;
}
