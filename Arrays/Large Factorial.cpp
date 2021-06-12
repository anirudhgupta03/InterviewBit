//Method - 1
string Solution::solve(int A) {
    
    int fact[201]={0};
    
    fact[0] = 1;
    
    int carry,len=1;
    
    for(int i = 2; i<= A; i++){
        carry = 0;
        int j=0;
        while(j< len){
            
            int n = i * fact[j] + carry;
            fact[j] = (n)%10;
            carry = (n)/10;
            j++;

        }
        
        while(carry>0){                       //Till carry does not become zero keep on increasing the length and decreasing the carry
            int n =  i * fact[j] + carry;
            fact[j] = (n)%10;
            carry = (n)/10;
            len++;
            j++;
        }
        
    }
    string s;
    
    for(int i=0; i< len; i++){
        s = s + to_string(fact[i]);
    }
    
    reverse(s.begin(),s.end());
    
    return s;
}

//Method - 2
//Ref: https://www.youtube.com/watch?v=2fYZERB2Yng
string Solution::solve(int A) {
    
    vector<int> fact;
    fact.push_back(1);
    
    for(int i = 2; i <= A; i++){
        
        int carry = 0;
        
        for(int j = 0; j < fact.size(); j++){
            int t = fact[j]*i + carry;
            fact[j] = t%10;
            carry = t/10;
        }
        
        while(carry != 0){
            fact.push_back(carry%10);
            carry = carry/10;
        }
        
    }
    
    string res;
    for(int i = fact.size() - 1; i >= 0; i--){
        res.push_back(fact[i] + '0');
    }
    return res;
}
