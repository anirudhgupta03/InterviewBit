int Solution::solve(int A, int B, int C, int D) {

    if(A == B){
        if(C == D) return 1;
    }
    if(A == C){
        if(B == D) return 1;
    }
    if(A == D){
        if(B == C) return 1;
    }
    return 0;
}
