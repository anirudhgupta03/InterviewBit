//Method - 1
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

//Method - 2
int Solution::gcd(int A, int B) {

    if(A > B) return gcd(B, A);

    if(A == 0) return B;

    return gcd(B % A, A);
}

