int Solution::solve(string A, string B) {

    int n1 = A.size(), n2 = B.size();

    int ld1 =  A[n1 - 1] - '0', ld2 = 0;

    for(int i = n2 - 2; i < n2; i++){
        ld2 = 10*ld2 + B[i] - '0';
    }

    int cyclicity = 1;

    if(ld1 == 2 || ld1 == 3 || ld1 == 7 ||  ld1 == 8){
        cyclicity = 4;
    }
    if(ld1 == 4 || ld1 == 9){
        cyclicity = 2;
    }

    ld2 %= cyclicity;

    if(ld2 == 0){
        ld2 = cyclicity;
    }

    int temp = pow(ld1, ld2);

    return temp % 10;
}
