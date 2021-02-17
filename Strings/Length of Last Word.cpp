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
