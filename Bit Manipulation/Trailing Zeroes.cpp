int Solution::solve(int A) {
    
    for(int i = 0; i < 32; i++){
        
        if((A & (1 << i)) != 0){
            return i;
        }
    }
}
