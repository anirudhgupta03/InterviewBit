//Method - 1
//Ref: https://www.youtube.com/watch?v=maVlQElsS5A
//Time Complexity - O(1)
//Space Complexity - O(1)
unsigned int Solution::reverse(unsigned int A) {
    
    int b = 0;
    
    for(int i = 0; i < 32; i++){
        
        b <<= 1;
        b |= A & 1;
        A >>= 1;
    }
    
    return b;
}

//Method - 2
unsigned int Solution::reverse(unsigned int A) {
    unsigned int revA = 0;
    
    for(int i = 0; i < 32; i++){
        int bit = A % 2;
        revA = (revA << 1);
        revA = (revA | bit);
        A /= 2;
    }
    return revA;
}
