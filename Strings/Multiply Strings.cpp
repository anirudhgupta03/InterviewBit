//Brute Force Approach
string Solution::multiply(string A, string B) {
    
    if(B.size() > A.size()){
        return multiply(B,A);
    }
    
    string res;
    
    for(int i = B.size() - 1; i >= 0; i--){
        
        string temp;
        int d1 = B[i] - '0';
        int carry = 0;
        
        for(int j = A.size() - 1; j>= 0; j--){
            int d2 = A[j] - '0';
            int pro = (d1*d2 + carry)%10;
            carry = (d1*d2 + carry)/10;
            temp.push_back(pro + '0');
        }
        
        if(carry != 0){
            temp.push_back(carry + '0');
        }
        reverse(temp.begin(),temp.end());
        
        if(res == ""){
            res = temp;
        }
        else{
            int p1 = res.size() - (B.size() - i), p2 = temp.size() - 1;
            carry = 0;
            while(p1 >= 0 && p2 >= 0){
                int t = (res[p1] - '0' + temp[p2] - '0' + carry) % 10;
                carry = (res[p1] - '0' + temp[p2] - '0'+ carry)/10;
                res[p1] = t + '0';
                p1--;
                p2--;
            }
            
            while(p2 >= 0){
                int t = (temp[p2] - '0' + carry) % 10;
                carry = (temp[p2] - '0'+ carry)/10;
                res.insert(res.begin(),t+'0');
                p2--;
            }
            
            if(carry != 0){
                res.insert(res.begin(),carry+'0');
            }
        }
    }
    
    int i = 0;
    while(res[i] == '0' && i < res.size() - 1){
        i++;
    }
    return res.substr(i,res.size()-i);
}

//Optimal Approach
//Ref: https://www.youtube.com/watch?v=CnEFY5Y3Z68
//Time Complexity - O(M*N)
//Space Complexity - O(M+N)
string Solution::multiply(string A, string B) {
    
    int m = A.length(), n = B.length();
    
    int val[m+n];
    memset(val,0,sizeof(val));
    
    for(int i = m - 1; i >=0; i--){
        for(int j = n - 1; j >= 0; j--){
            
            int mult = (A[i] - '0')*(B[j] - '0');
            int sum = val[i+j+1] + mult;
            val[i+j] += sum / 10;
            val[i+j+1] = sum % 10;
        }
    }
    string s;
    int i = 0;
    while(i < m + n){
        if(val[i] != 0){
            break;
        }
        i++;
    }
    if(i == m + n){
        return "0";
    }
    for(int j = i; j < m + n; j++){
        string p = to_string(val[j]);
        s += p;
    }
    return s;
    
}

string Solution::multiply(string A, string B) {
    
    int m = A.size(), n = B.size();
    
    string s(m+n,'0');
    
    for(int i = m - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            
            int mult = (A[i] - '0')*(B[j] - '0') + s[i+j+1] - '0';
            s[i+j+1] = mult % 10 + '0';
            s[i+j] += mult / 10;
        }
    }
    
    int i = 0;
    
    while(i < (m+n-1)){
        if(s[i] != '0'){
            break;
        }
        i++;
    }
    return s.substr(i);
}
