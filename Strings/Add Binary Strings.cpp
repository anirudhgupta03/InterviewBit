//Method - 1
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

//Method - 2
//Ref: https://www.geeksforgeeks.org/full-adder-in-digital-logic/
string Solution::addBinary(string A, string B) {
    
    if(A.size() > B.size()){
        reverse(B.begin(),B.end());
        while(A.size() != B.size()){
            B.push_back('0');
        }
        reverse(B.begin(),B.end());
    }
    else{
        reverse(A.begin(),A.end());
        while(A.size() != B.size()){
            A.push_back('0');
        }
        reverse(A.begin(),A.end());
    }
    
    int carry = 0;
    
    for(int i = B.size() - 1; i >= 0; i--){
        int a = ((A[i]-'0')^(B[i]-'0')^carry);
        carry = (A[i]-'0')&(B[i]-'0') | (A[i]-'0')&carry | (B[i]-'0')&carry;
        B[i] = a + '0';
    }
    
    if(carry != 0){
        B.insert(B.begin(),1+'0');
    }
    return B;
}
