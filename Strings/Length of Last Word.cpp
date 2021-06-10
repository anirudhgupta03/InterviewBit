//Method - 1
int Solution::lengthOfLastWord(const string A) {
    
    string res;
    
    bool flag = false;
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] == ' '){
            flag = true;
        }
        else{
            if(flag){
                res.clear();
                flag = false;
            }
            res.push_back(A[i]);
        }
    }
    
    return res.size();
}

//Method - 2
int Solution::lengthOfLastWord(const string A) {
    
    int ans = 0;    //In case the string is empty
    
    stringstream X(A);  //It ignores the empty spaces
    
    string s;
    
    while(X >> s){
        ans = s.size();
    }
    
    return ans;
}

//Method - 3
int Solution::lengthOfLastWord(const string A) {
    
    string s;
    int ans = 0;
    
    for(auto x : A){
        
        if(x == ' '){
            s.clear();
        }
        else{
            s.push_back(x);
            ans = s.size();
        }
    }
    
    return ans;
}
