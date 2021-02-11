int integervalue(char roman){
    
    switch(roman){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
}
int Solution::romanToInt(string A) {
    
    int n = A.size();
    
    int value = integervalue(A[n - 1]);
    
    for(int i = n - 2; i >= 0; i--){
        
        if(integervalue(A[i]) >= integervalue(A[i+1])){
            value += integervalue(A[i]);
        }
        else{
            value -= integervalue(A[i]);
        }
        
    }
    return value;
}
