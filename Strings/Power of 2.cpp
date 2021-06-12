//Method - 1
string divideBy2(string S){
    
    string ans;
    
    int carry = 0;
    
    int n = S.size();
    int i = 0;
    
    while(i < n){
        
        int num = S[i] - '0';
        num = num + carry * 10;
        carry = num % 2;
        ans.push_back(num/2 + '0');
        i++;
    }
    
    while(ans.length()>0 && ans[0]=='0')
    {
        ans.erase(ans.begin());
    }
    
    return ans;
}
int Solution::power(string A) {
    
    if(A == "1"){
        return 0;
    }
    
    string temp = A;
    
    int n = A.size();
    
    if((temp[n-1] - '0') % 2){
        return 0;
    }
    
    while(temp.length() > 0){
        
        
        if(temp.length() == 1 && temp[0] == '1'){
            return 1;
        }
        
        int n = temp.length();
        int t = temp[n-1] - '0';
        
        if(t % 2 != 0){
            return 0;
        }
        
        temp=divideBy2(temp);
    }
}

//Method - 2
int Solution::power(string A) {
    
    while(1){
        
        int carry = 0;
        
        while(A[0] == '0'){
            A.erase(A.begin());
        }
        
        if(A.size() == 1 && A[0] == '2'){
            return 1;
        }
        
        int i = 0;
        while(i < A.size()){
            
            int t = (10*carry + A[i] - '0');
            
            if(i == A.size() - 1 && t % 2 != 0){
                return 0;
            }
            else if(t % 2 != 0){
                A[i] = t/2 + '0';
                carry = 1;
            }
            else if(t % 2 == 0){
                A[i] = t/2 + '0';
                carry = 0;
            }
            i++;
        }
    }
}


//Method - 3
int Solution::power(string A) {
    if(A == "1"){
        return 0;
    }
    long double n = stold(A);
    if(floor(log2(n)) == ceil(log2(n))){
        return 1;
    }
    return 0;
}
