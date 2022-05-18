int Solution::solve(int A, int B, int C) {

    B--;
    C--;
    int f1 = (A >> B) & 1;
    int f2 = (A >> C) & 1;
    A += (f1 << C) + (f2 << B) - (f1 << B) - (f2 << C);
    return A;
}
