int Solution::braces(string A) {
    
    stack<char> s;
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] == '('){
            s.push(A[i]);
        }
        else if(A[i] == '+' || A[i] == '-' || A[i] == '*' || A[i] == '/'){
            s.push(A[i]);
        }
        else if(A[i] == ')'){
            
            if(s.top() == '('){
                return 1;
            }
            while(s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/'){
                s.pop();
            }
            s.pop(); //Pop opening bracket
        }
    }
    return 0;
}
