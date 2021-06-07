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
