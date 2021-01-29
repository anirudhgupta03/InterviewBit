int Solution::gcd(int A, int B) {
    
    int a = max(A,B);
    int b = min(A,B);
    
    if(b == 0) 
        return a;
    
    while(a % b !=0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    return b;
}
