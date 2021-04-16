int Solution::solve(string A) {
    
    stack<char> s;
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] == '('){
            s.push('(');
        }
        else if(!s.empty() && A[i] == ')'){
            s.pop();
        }
        else if(s.empty() && A[i] == ')'){
            return 0;
        }
    }
    
    if(s.size() != 0){
        return 0;
    }
    return 1;
}
