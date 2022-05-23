//Method - 1
int Solution::isPalindrome(int A) {

    if(A >= 0 && A <= 9) return 1;

    if(A < 0) return 0;

    int len = 0, temp = A;

    while(temp){
        len++;
        temp /= 10;
    }

    int lo = pow(10, len - 1);
    int hi = 10;

    int temp1 = A, temp2 = A;

    len /= 2;

    while(len--){
        if(temp1 / lo != temp2 % hi){
            return false;
        }
        temp1 = temp1 % lo;
        temp2 = temp2 / hi;
        lo /= 10;
    }
    return true;
}

//Method - 2
int Solution::isPalindrome(int A) {

    if(A < 0) return 0;
    
    int B = 0, temp = A;

    while(temp){
        B = 10*B + temp % 10;
        temp /= 10;
    }

    if(A == B){
        return 1;
    }
    return 0;
}
