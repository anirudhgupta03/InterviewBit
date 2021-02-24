int Solution::isNumber(const string A) {
    
    int len = A.length();
    
    bool sign = false;
    bool num = false;
    bool e = false;
    bool dot = false;
    
    int l = 0, r = A.length() - 1;
    
    while(l <=r && A[l] == ' ')l++;
	while(r >= 0 && A[r] == ' ')r--;

    while(l <= r){
        
        char ch = A[l];
        
        if(isdigit(ch)){
            num = true;
        }
        else if(ch == 'e'){
            if(!num || e){
                return false;
            }
            e = true;
            num = false;
            sign = false; 
        }
        else if(ch == '+' || ch == '-'){
            if(sign || num){
                return false;
            }
            sign = true;
        }
        else if(ch == '.'){
            if(dot || e){
                return false;
            }
            dot = true;
            sign = true;
            num = false;
        }
        else{
            return false;
        }
        l++;
    }
    return num;
}
