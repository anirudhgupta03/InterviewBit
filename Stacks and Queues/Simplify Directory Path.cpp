//Ref: https://www.youtube.com/watch?v=h1KVmq2oGhE
string Solution::simplifyPath(string path) {
    
    string s1 = ".", s2 = "..";
        
        stack<string> st;
        
        for(int i = 0; i < path.size(); i++){
            
            if(path[i] == '/') 
                continue;
            string s;
            
            while(i < path.size() && path[i] != '/'){
                s.push_back(path[i]);
                i++;
            }
            
            if(s == s1){
                continue;
            }
            else if(s == s2){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(s);
            }
        }
        
        if(st.empty()){
            return "/";
        }
        
        string ans;
        
        while(st.size()){
            
            string temp = st.top();
            st.pop();
            reverse(temp.begin(),temp.end());
            temp.push_back('/');
            
            ans += temp;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
}

//Method - 2
//TLE
string Solution::simplifyPath(string A) {

    stack<string> st;
    string s;

    for(int i = 0; i < A.size(); i++){
        if(A[i] == '/'){
            if(s == "."){
                if(st.size() != 1){
                    st.pop();
                    st.push("/");
                }
            }
            else if(s == ".."){
                if(st.size() != 1){
                    st.pop();
                    st.pop();
                }
            }
            else if(s == ""){
                if(st.empty()){
                    st.push("/");
                }
            }
            else{
                st.push(s);
                st.push("/");
            }
            s = "";
        }
        else{
            s.push_back(A[i]);
        }
    }
    if(s == "."){
        if(st.size() != 1){
            st.pop();
            st.push("/");
        }
    }
    else if(s == ".."){
        if(st.size() != 1){
            st.pop();
            st.pop();
        }
    }
    else if(s == ""){
        if(st.empty()){
            st.push("/");
        }
    }
    else{
        st.push(s);
    }

    string res;
    while(!st.empty()){
        res = st.top() + res;
        st.pop();
    }
    if(res.size() != 1 && res[res.size() - 1] == '/') res.pop_back();
    return res;
}

//Method - 3
//Ref: https://www.interviewbit.com/problems/simplify-directory-path/discussion/p/my-code-runs-fine-but-i-am-getting-tle-while-submission/39670/473
string Solution::simplifyPath(string A) {

    stack<string> st;
    string s;

    for(int i = 0; i < A.size(); i++){
        if(A[i] == '/'){
            if(s == "."){
                if(st.size() != 1){
                    st.pop();
                    st.push("/");
                }
            }
            else if(s == ".."){
                if(st.size() != 1){
                    st.pop();
                    st.pop();
                }
            }
            else if(s == ""){
                if(st.empty()){
                    st.push("/");
                }
            }
            else{
                st.push(s);
                st.push("/");
            }
            s = "";
        }
        else{
            s.push_back(A[i]);
        }
    }
    if(s == "."){
        if(st.size() != 1){
            st.pop();
            st.push("/");
        }
    }
    else if(s == ".."){
        if(st.size() != 1){
            st.pop();
            st.pop();
        }
    }
    else if(s == ""){
        if(st.empty()){
            st.push("/");
        }
    }
    else{
        st.push(s);
    }

    stack<string> temp;
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    string res;
    while(!temp.empty()){
        res += temp.top();
        temp.pop();
    }
    if(res.size() != 1 && res[res.size() - 1] == '/') res.pop_back();
    return res;
}
