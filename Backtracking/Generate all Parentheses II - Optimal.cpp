void solve(int c1, int c2, int A, vector<string> &res, string s){
    
    if(c1 == A && c2 == A){
        res.push_back(s);
        return;
    }
    
    if(c1 < A){
        s.push_back('(');
        solve(c1+1,c2,A,res,s);
        s.pop_back();
    }
    
    if(c2 < c1){
        s.push_back(')');
        solve(c1,c2+1,A,res,s);
        s.pop_back();
    }
}
vector<string> Solution::generateParenthesis(int A) {
    
    int c1 = 0, c2 = 0;
    
    vector<string> res;
    string s;
    
    solve(c1,c2,A,res,s);
    
    return res;
}
