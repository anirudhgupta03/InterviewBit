int Solution::lengthOfLastWord(const string A) {
    
    int ans = 0;    //In case the string is empty
    
    stringstream X(A);  //It ignores the empty spaces
    
    string s;
    
    while(X >> s){
        ans = s.size();
    }
    
    return ans;
}
