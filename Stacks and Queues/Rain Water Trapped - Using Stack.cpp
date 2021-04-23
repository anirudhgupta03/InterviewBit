int Solution::trap(const vector<int> &A) {
    
    int n = A.size();
    
    vector<int> gl;
    vector<int> gr;
    
    gl.push_back(-1);
    
    stack<int> s;
    
    s.push(A[0]);
    
    for(int i = 1; i < n; i++){
        
        if(s.top() > A[i]){
            gl.push_back(s.top());
        }
        else{
            
            while(!s.empty() && s.top() <= A[i]){
                s.pop();
            }
            
            if(s.empty()){
                gl.push_back(-1);
                s.push(A[i]);
            }
            else{
                gl.push_back(s.top());
            }
        }
    }
    
    gr.push_back(-1);
    while(s.size()){
        s.pop();
    }
    
    s.push(A[n-1]);
    for(int i = n - 2; i >= 0; i--){
        
        if(s.top() > A[i]){
            gr.push_back(s.top());
        }
        else{
            
            while(!s.empty() && s.top() <= A[i]){
                s.pop();
            }
            
            if(s.empty()){
                gr.push_back(-1);
                s.push(A[i]);
            }
            else{
                gr.push_back(s.top());
            }
        }
    }
    reverse(gr.begin(),gr.end());
    
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        ans += max(0,min(gl[i],gr[i])-A[i]);
    }
    
    return ans;
}
