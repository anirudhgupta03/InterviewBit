int Solution::atoi(const string A) {
    
    int len = A.size();
    
    long long res = 0;
    
    int i = 0;
    
    while(A[i] == ' ' && i < len){
        i++;
    }
    
    int sign = 1;
    
    if(i < len && A[i] == '+'){
        i++;
    }
    if(i < len && A[i] == '-'){
         sign = -1;
         i++;
    }
    
    
    while(i < len){
        
        if(!(isdigit(A[i]))){
            break;
        }
        
        res = 10*res + A[i++] - '0';
        
        if(res > INT_MAX){
            if(sign == -1){
                return INT_MIN;
            }
            else{
                return INT_MAX;
            }
        }
    }
    
    if(sign == -1)
    res = -1*res;
    
    return res;
}
