int Solution::solve(int A, int B, int C) {
    return (C + A - 1) % B == 0 ? B : (C + A - 1) % B;
}
