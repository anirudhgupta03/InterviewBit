string Solution::addBinary(string A, string B) {
    
    int i = A.size() - 1, j = B.size() - 1, carry = 0;
    
    string s;
    
    while(i >=0 && j >= 0){
        
        int a = A[i] - 48;
        int b = B[j] - 48;
        
        s = to_string(a ^ b ^ carry) + s;
        
        carry = (a && carry || b && carry || a && b);
        
        i--;
        j--;
    }
    
    if(i == -1 && j == -1){
        if(carry == 1){
            s = to_string(carry) + s;
        }
        return s;
    }
    else if(i == -1){
        while(j >= 0){
            
            int b = B[j] - 48;
            s = to_string(b ^ carry) + s;
            carry = (b && carry);
            j--;
        }
        if(carry == 1){
            s = to_string(carry) + s;
        }
        return s;
    }
    else{
        while(i >= 0){
            int a = A[i] - 48;
            s = to_string(a ^ carry) + s;
            carry = (a && carry);
            i--;
        }
        if(carry == 1){
            s = to_string(carry) + s;
        }
        return s;
    }
}
