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
