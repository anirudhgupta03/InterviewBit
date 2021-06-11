//Method - 1
bool ispalindrome(string s){
    for(int i=0;i<s.length()/2;i++){
        if(s[i]!=s[s.length()-i-1])return false;
    }
    return true;
}
void solve(int index, string A, vector<string> &p, vector<vector<string> > &v){
    
    if(index == A.size()){
        v.push_back(p);
        return;
    }
    string s = "";
    for(int i = index; i < A.size(); i++){
        
        s+=A[i];
        
        if(ispalindrome(s)){
            p.push_back(s);
            solve(i+1,A,p,v);
            p.pop_back();
        }
    }
    return;
}
vector<vector<string> > Solution::partition(string A) {
    
    vector<vector<string> > v;
    vector<string> p;
    
    solve(0,A,p,v);
    
    return v;
}

//Method - 2
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
