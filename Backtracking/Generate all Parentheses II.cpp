//Method - 1
void solve(string op, vector<string> &v, int c1, int c2, int A){
    
    if(c1 == A && c2 == A){
        v.push_back(op);
        return;
    }
    
    string op1 = op;
    string op2 = op;
    
    if(c1 != A && c1 - c2 >= 0){
        
        op1.push_back('(');
        op2.push_back(')');
        
        solve(op1,v,c1+1,c2,A);
        solve(op2,v,c1,c2+1,A);
    }
    else if(c1 == A){
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

//Method - 2
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

//Method - 3
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

//Method - 4
void solve(int bal, int A, string &s, vector<string> &res){

    if(s.size() == 2*A){
        if(bal == 0)
        res.push_back(s);
        return;
    }

    if(bal < A){
        s.push_back('(');
        solve(bal + 1, A, s, res);
        s.pop_back();
    }
    if(bal > 0){
        s.push_back(')');
        solve(bal - 1, A, s, res);
        s.pop_back();
    }
}
vector<string> Solution::generateParenthesis(int A) {

    vector<string> res;
    string s;

    solve(0, A, s, res);
    return res;
}
