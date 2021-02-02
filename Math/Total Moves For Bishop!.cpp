int Solution::solve(int A, int B) {
    
    return min(A-1,B-1)+min(A-1,8-B)+min(B-1,8-A)+min(8-A,8-B);
}
