void solve(string op, vector<string> &v, int c1, int c2, int A){
    
    if(c1 == A && c2 == A){
        v.push_back(op);
        return;
    }
    
    string op1 = op;
    string op2 = op;
    
    if(c1 != A && c1 - c2 > 0){
        
        op1.push_back('(');
        op2.push_back(')');
        
        solve(op1,v,c1+1,c2,A);
        solve(op2,v,c1,c2+1,A);
    }
    else if(c1 != A && c1 - c2 == 0){
        
        op1.push_back('(');
        solve(op1,v,c1+1,c2,A);
    }
    else{
        op2.push_back(')');
        solve(op2,v,c1,c2+1,A);
    }
    return;
}
vector<string> Solution::generateParenthesis(int A) {
    
    int c1 = 1, c2 = 0;
    
    vector<string> v;
    
    string op;
    op.push_back('(');
    
    solve(op,v,c1,c2,A);
    
    return v;    
}
