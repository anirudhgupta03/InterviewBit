bool isPalindrome(string s){
    
    int l = 0, r = s.size() - 1;
    
    while(l <= r){
        if(s[l] != s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
void solve(int ind, string A, vector<string> &temp, vector<vector<string>> &res){
    
    if(ind == A.size()){
        res.push_back(temp);
        return;
    }
    for(int i = ind; i < A.size(); i++){
        
        string p = A.substr(ind,i-ind+1);
        
        if(isPalindrome(p)){
            temp.push_back(p);
            solve(i+1,A,temp, res);
            temp.pop_back();
        }
    }
}
vector<vector<string> > Solution::partition(string A) {
    
    vector<string> temp;
    vector<vector<string>> res;
    
    solve(0,A,temp,res);
    
    return res;
}
