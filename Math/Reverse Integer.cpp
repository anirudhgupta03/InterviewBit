int Solution::reverse(int A) {
    
    int temp = abs(A), length = 0;
    
    while(temp!=0){
        temp = temp/10;
        length++;
    }
    
    temp = abs(A);
    
    long long rev = 0, mult = 1;
    for(int i = 1;i < length; i++){
        mult = mult * 10;
    }
    while(temp!=0){
        
        rev = rev + (temp%10)*mult;
        mult = mult/10;
        temp = temp/10;
    }
    
    if(rev < INT_MIN || rev > INT_MAX){
        return 0;
    }
    if(A<0){
        return -1*rev;
    }
    return rev;
}
