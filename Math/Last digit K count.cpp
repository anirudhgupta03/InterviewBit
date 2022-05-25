int Solution::solve(int A, int B, int C) {

    while(A <= B){
        if(A % 10 == C){
            break;
        }
        A++;
    }

    if(A > B) return 0;

    return (B - A)/10 + 1;
}
