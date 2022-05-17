//Method - 1
//TC - O(set bits)
//Flip the least significant bit
int Solution::numSetBits(unsigned int A) {
    
    int count = 0;
 
    while(A){
        A = A & (A-1);
        count++;
    }
    return count;
}

//Method - 2
//TC - O(32)
//SC - O(1)
int Solution::numSetBits(unsigned int A) {
    int count = 0;
    while(A){
        if(A % 2 == 1){
            count++;
        }
        A /= 2;
    }
    return count;
}
