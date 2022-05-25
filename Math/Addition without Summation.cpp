//Method - 1
int Solution::addNumbers(int A, int B) {

    int ans = 0, c = 0, pos = 0;

    while(A != 0 || B != 0){
        int x = A % 2;
        int y = B % 2;
        int one = x ^ y ^ c;
        c = (x & y) | (c & y) | (c & x);

        if(one) ans |= (1 << pos);

        A /= 2;
        B /= 2;
        pos++;
    }
    if(c){
        ans |= (1 << pos);
    }
    return ans;
}

//Method - 2
int Solution::addNumbers(int A, int B) {

    while(B){
        int carry = A & B;
        A = A ^ B;
        B = carry << 1;
    }
    return A;
}
