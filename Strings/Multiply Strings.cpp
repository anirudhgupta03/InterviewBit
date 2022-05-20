//Method - 1
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

//Method - 2
string Solution::multiply(string A, string B) {

    int len1 = A.size(), len2 = B.size();

    vector<int> res(len1 + len2, 0);

    for(int i = len2 - 1; i >= 0; i--){
        int ind = res.size() - (len2 - i), carry1 = 0, carry2 = 0;
        for(int j = len1 - 1; j >= 0; j--){
            int curr1 = (B[i] - '0')*(A[j] - '0') + carry1;
            int curr2 = res[ind] + curr1 % 10 + carry2;
            res[ind] = curr2 % 10;
            carry2 = curr2 / 10;
            carry1 = curr1 / 10;
            ind--;
        }
        if(carry1){
            int curr1 = carry1;
            int curr2 = res[ind] + curr1 % 10 + carry2;
            res[ind] = curr2 % 10;
            carry2 = curr2 / 10;
            carry1 = curr1 / 10;
            ind--;
        }
        while(carry2){
            res[ind] = carry2 % 10;
            carry2 /= 10;
            ind--;
        }
    }
    string ans;
    int ptr = 0;
    while(ptr < res.size() - 1 && res[ptr] == 0) ptr++;
    
    while(ptr < res.size()){
        ans.push_back(res[ptr] + '0');
        ptr++;
    }
    return ans;
}

//Method - 3
//Optimised Method - 2
//Ref: https://www.youtube.com/watch?v=5NdhK3tZViQ
string Solution::multiply(string A, string B) {

    int len1 = A.size(), len2 = B.size();

    vector<int> res(len1 + len2, 0);

    for(int i = len2 - 1; i >= 0; i--){
        int ind = res.size() - (len2 - i), carry = 0;
        for(int j = len1 - 1; j >= 0; j--){
            int curr = (B[i] - '0')*(A[j] - '0') + carry + res[ind];
            res[ind] = curr % 10;
            carry = curr / 10;
            ind--;
        }
        while(carry){
            int curr = res[ind] + carry;
            res[ind] = curr % 10;
            carry = curr / 10;
            ind--;
        }
    }
    string ans;
    int ptr = 0;
    while(ptr < res.size() - 1 && res[ptr] == 0) ptr++;
    
    while(ptr < res.size()){
        ans.push_back(res[ptr] + '0');
        ptr++;
    }
    return ans;
}

//Method - 4
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

//Method - 5
//Best Method
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
