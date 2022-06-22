//Method - 1
int Solution::solve(int A, int B, int C) {

    B--;
    C--;
    int f1 = (A >> B) & 1;
    int f2 = (A >> C) & 1;
    A += (f1 << C) + (f2 << B) - (f1 << B) - (f2 << C);
    return A;
}

//Method - 2
int Solution::solve(int A, int B, int C) {
    
    int bitAtB = (A & (1 << (B - 1))) == 0 ? 0 : 1;
    int bitAtC = (A & (1 << (C - 1))) == 0 ? 0 : 1;
    
    if(bitAtB == bitAtC){
        return A;
    }
    
    A = (A ^ (1 << (B - 1)));
    A = (A ^ (1 << (C - 1)));
    return A;
}
