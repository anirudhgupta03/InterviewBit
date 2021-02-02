int pw(int base, int exponent){
    
    if(exponent == 0){
        return 1;
    }
    if(exponent == 1){
        return base;
    }
    
    if(exponent % 2==0){
        int a = pw(base,exponent/2);
        return a*a;
    }
    
    return base*pw(base,(exponent-1)/2)*pw(base,(exponent-1)/2);
}
int Solution::isPower(int A) {
    
    if(A==1){
        return 1;
    }
    
    for(int i = 2; i*i <= A; i++){
        
        int exponent = (int)((floor)(log(A)/log(i)));
        
        if(pw(i,exponent) == A){
            return 1;
        }
    }
    return 0;
}
