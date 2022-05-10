//Use NSL and NSR approach
//Method - 1
int Solution::largestRectangleArea(vector<int> &A) {
    
    int n = A.size();
    vector<int> nsl;
    nsl.push_back(-1);
    
    stack<pair<int,int>> s;
    s.push({A[0],0});
    
    for(int i = 1; i < A.size(); i++){
        
        if(s.top().first < A[i]){
            nsl.push_back(s.top().second);
        }
        else{
            
            while(!s.empty() && s.top().first >= A[i]){
                s.pop();
            }
            
            if(s.empty()){
                nsl.push_back(-1);
            }
            else{
                nsl.push_back(s.top().second);
            }
        }
        s.push({A[i],i});
    }
    
    vector<int> nsr;
    nsr.push_back(A.size());

    while(s.size()){
        s.pop();
    }
    s.push({A[A.size()-1],A.size()-1});
    
    for(int i = A.size() - 2; i >= 0; i--){
        
        if(s.top().first < A[i]){
            nsr.push_back(s.top().second);
        }
        else{
            
            while(!s.empty() && s.top().first >= A[i]){
                s.pop();
            }
            
            if(s.empty()){
                nsr.push_back(A.size());
            }
            else{
                nsr.push_back(s.top().second);
            }
        }
        s.push({A[i],i});
    }
    reverse(nsr.begin(),nsr.end());
    int ans = INT_MIN;
    
    for(int i = 0; i < A.size(); i++){
        
        int larea = (i - nsl[i] - 1)*A[i];
        int rarea = (nsr[i] - i - 1)*A[i];
        
        ans = max(ans, larea+rarea+A[i]);
    }
    
    return ans;
}

//Method - 2
int Solution::largestRectangleArea(vector<int> &A) {

    int n = A.size();
    vector<int> nsl(n), nsr(n);

    stack<int> st;
    st.push(0);
    nsl[0] = -1;

    for(int i = 1; i < n; i++){
        if(A[i] > A[st.top()]){
            nsl[i] = st.top();
        }
        else{
            while(!st.empty() && A[i] <= A[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nsl[i] = -1;
            }
            else{
                nsl[i] = st.top();
            }
        }
        st.push(i);
    }

    while(!st.empty()) st.pop();
    nsr[n - 1] = n;
    st.push(n - 1);

    for(int i = n - 2; i >= 0; i--){
        if(A[i] > A[st.top()]){
            nsr[i] = st.top();
        }
        else{
            while(!st.empty() && A[i] <= A[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nsr[i] = n;
            }
            else{
                nsr[i] = st.top();
            }
        }
        st.push(i);
    }

    int maxArea = INT_MIN;
    for(int i = 0; i < n; i++){
        maxArea = max(maxArea, A[i]*(nsr[i] - nsl[i] - 1));
    }
    return maxArea;
}
