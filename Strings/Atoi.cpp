//Method - 1
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

//Method - 2
//Optimal Approach
#define ll long long
int Solution::atoi(const string A) {

    double res = 0;
    int sign = 1;
    bool flag = false;

    for(ll i = 0; i < A.size(); i++){
        if(isdigit(A[i])){
            res = 10*res + (A[i] - '0');
            flag = true;
        }
        else if(A[i] == '+' || A[i] == '-'){
            if(flag) break; 
            flag = true;
            if(A[i] == '-') sign = -1;
        }
        else if(A[i] == ' '){
            if(flag) break;
        }
        else{
            break;
        }
    }
    res = sign*res;
    if(res > INT_MAX) return INT_MAX;
    if(res < INT_MIN) return INT_MIN;
    return res;
}

//Method - 3
#define ld long double
int Solution::atoi(const string A) {
    
    ld val = 0;
    
    int i = 0;
    
    while(i < A.size() && A[i] == ' '){
        i++;
    }
    int sign = 1;
    if(A[i] == '-'){
        sign = -1;
        i++;
    }
    else if(A[i] == '+'){
        i++;
    }
    
    while(i < A.size() && isdigit(A[i])){
        val = 10*val + (ld)(A[i] - '0');
        i++;
    
    val *= sign;
    
    if(val >= INT_MAX){
       return INT_MAX; 
    }
    if(val < INT_MIN){
        return INT_MIN;
    }
    return val;
}
