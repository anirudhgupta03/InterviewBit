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
