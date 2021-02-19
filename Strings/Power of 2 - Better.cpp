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
