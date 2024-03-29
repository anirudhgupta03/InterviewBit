int Solution::solve(int A) {

    if(A == 0) return 0;
    
    int prod = 1;

    while(A){
        prod *= (A % 10);
        A /= 10;
    }
    return prod;
}
