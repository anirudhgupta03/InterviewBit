int Solution::solve(string A) {
    
    stack<char> s;
    
    int count = 0;
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] == ')' && !s.empty()){
            s.pop();
        }
        else if(A[i] == ')'){
            count++;
        }
        else{
            s.push('(');
        }
    }
    
    return s.size() + count;
}
