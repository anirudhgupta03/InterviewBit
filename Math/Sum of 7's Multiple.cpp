long Solution::solve(int A, int B) {

    while(A <= B){
        if(A % 7 == 0){
            break;
        }
        A++;
    }
    if(A > B) return 0;
    
    long n = (B - A)/7 + 1;

    return (long)(n*A + (n*(n - 1)*7)/2);
}
