string Solution::reverseString(string A) {
    stack<char> st;
    for(int i = 0; i < A.size(); i++){
        st.push(A[i]);
    }
    string ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
