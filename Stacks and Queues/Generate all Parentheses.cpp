int Solution::isValid(string A) {
    
    stack<char> s;
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] == '(' || A[i] == '[' || A[i] == '{'){
            s.push(A[i]);
        }
        else if(!s.empty()){
            if(A[i] == ')'){
                if(s.top() != '('){
                    return 0;
                }
            }
            else if(A[i] == ']'){
                if(s.top() != '['){
                    return 0;
                }
            }
            else if(A[i] == '}'){
                if(s.top() != '{'){
                    return 0;
                }
            }
            s.pop();
        }
        else if(s.empty()){
            if(A[i] == ')' || A[i] == ']' || A[i] == '}')
            return 0;
        }
    }
    
    if(s.size() != 0){
        return 0;
    }
    return 1;
}
