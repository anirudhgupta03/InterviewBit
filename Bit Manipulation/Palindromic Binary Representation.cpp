//Ref: https://www.youtube.com/watch?v=QYoWR8hDCyQ
//Very Tough
int getReverse(int n){
    
    int rev = 0;
    
    while(n != 0){
        int lb = (n & 1);
        rev |= lb;
        
        rev <= 1;
        n >= 1;
    }
    
    rev >= 1;
    return rev;
}
int Solution::solve(int A) {
    
    if(A == 1){
        return 1;
    }
    
    int len = 1, count = 1;
    
    while(count < A){
        len++;
        count += (1 << (len - 1)/2);
    }
    
    count -= (1 << (len-1)/2);
    
    int offset = A - count - 1;
    
    int ans = (1 << (len - 1));
    
    ans |= (offset << (len/2));
    
    int valFR = (ans >> (len/2));
    
    int rev = getReverse(valFR);
    
    ans |= rev;
    
    return ans;
}
