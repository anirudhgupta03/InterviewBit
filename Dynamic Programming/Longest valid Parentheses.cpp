//Ref: https://www.youtube.com/watch?v=qC5DGX0CPFA
int Solution::longestValidParentheses(string A) {
    
    int n = A.size();
    
    int dp[n];
    
    stack<char> st1; 
    stack<int> st2;
    
    st2.push(-1);
    
    int maxLen = 0;
    
    for(int i = 0; i < n; i++){
        
        if(A[i] == '('){
            st1.push('(');
            st2.push(i);
        }
        else{
            if(!st1.empty()){
                st1.pop();
                st2.pop();
                maxLen = max(maxLen,i-st2.top());
            }
            else{
                st2.push(i);
            }
        }
    }
    return maxLen;
}
