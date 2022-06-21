//Method - 1
int Solution::solve(int A) {
    
    if(A == 1){
        return 1;
    }
    int len = 0, count = 1, sum = 0;
    
    while(1){
        len++;
        sum += count;
        if(A <= sum){
            break;
        }
        len++;
        sum += count;
        if(A <= sum){
            break;
        }
        count *= 2;
    }

    int elementsInGroup = (1 << ((len - 1)/2));
    int startOfGroup = sum - elementsInGroup + 1;
    
    int diff = A - startOfGroup;
    
    int res = 1;
    res = (res << ((len - 1)/2));
    res += diff;
    
    if(len % 2 != 0){
        diff >>= 1;   
    }
    
    res <<= (len/2);
    int revdiff = 0, ptr = 1;
    
    while(ptr < len/2){
        revdiff <<= 1;
        revdiff |= (diff & 1);
        diff >>= 1;
        ptr++;
    }
    revdiff <<= 1;
    revdiff += 1;
    
    res += revdiff;
    return res;
}

//Method - 2
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
