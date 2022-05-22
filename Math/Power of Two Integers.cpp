//Method - 1
int Solution::isPower(int A) {

    if(A == 1) return 1;

    for(int i = 2; i * i <= A; i++){

        if(A % i == 0){
            int B = A;
            while(B % i == 0){
                B /= i;
            }
            if(B == 1){
                return 1;
            }
        }
    }
    return 0;
}

//Method - 2
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

//Method - 3
int Solution::isPower(int A) {
    if(A == 1) return 1;
    int gcd = 0;
    
    for(int i = 2; i * i <= A; i++){
        if(A % i == 0){
            int count = 0;
            while(A % i == 0){
                A /= i;
                count++;
            }
            gcd = __gcd(gcd, count);
        }
    }
    if(A != 1) return 0;
    if(gcd != 1) return 1;
    return 0;
}
