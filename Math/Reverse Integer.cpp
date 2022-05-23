#define ll long long
int Solution::reverse(int A) {

    int sign = 1;
    if(A < 0) sign = -1;

    A = abs(A);

    ll rev = 0;

    while(A){
        rev = 10*rev + A % 10;
        A /= 10;
    }
    rev = sign*rev;

    if(rev < INT_MIN || rev > INT_MAX){
        return 0;
    }
    return rev;
}
