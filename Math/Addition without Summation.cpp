//Method - 1
int reverseBits(int num){
    
    int rev = 0;
    while(num){
        rev <<= 1;
        rev |= (num & 1);
        num >>= 1;
    }
    return rev;
}
int Solution::addNumbers(int A, int B) {
    
    int ans = 0, carry = 0, pos = 0;
    
    while(A || B){
        
        int bit1 = (A & 1);
        int bit2 = (B & 1);
        
        int val = bit1 ^ bit2 ^ carry;
        carry = (bit1 & bit2) | (bit1 & carry) | (bit2 & carry);
        
        if(val) ans |= (1 << pos);
        pos++;
        
        A >>= 1;
        B >>= 1;
    }
    
    if(carry){
        ans |= (1 << pos);
    }
    return ans;
}

//Method - 2
//Ref: https://www.youtube.com/watch?v=kIXhc8nZKIo
int Solution::addNumbers(int A, int B) {

    while(B){
        int carry = A & B;
        A = A ^ B;
        B = carry << 1;
    }
    return A;
}
