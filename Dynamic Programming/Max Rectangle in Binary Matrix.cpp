//Stack Based Approach
//TC - O(n*n)
//SC - O(n*n)
//Maximum Area Histogram
int maxAreaHistogram(vector<int> v){
   
    int n = v.size();
    vector<int> nsl(n);
    vector<int> nsr(n);
    
    nsl[0] = -1;

    stack<int> st;

    st.push(0);

    for(int i = 1; i < n; i++){

        if(v[i] > v[st.top()]){
            nsl[i] = st.top();
        }
        else{
            while(!st.empty() && v[st.top()] >= v[i]){
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
    
    nsr[n-1] = n;

    while(st.size()){
        st.pop();
    }
    
    st.push(n-1);
    
    for(int i = n - 2; i >= 0; i--){

        if(v[i] > v[st.top()]){
            nsr[i] = st.top();
        }
        else{
            while(!st.empty() && v[st.top()] >= v[i]){
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
        maxArea = max(maxArea,(nsr[i] - nsl[i] - 1)*v[i]);
    }

    return maxArea;
}
int Solution::maximalRectangle(vector<vector<int> > &A) {

    vector<vector<int>> B = A;

    for(int i = 1; i < B.size(); i++){
        for(int j = 0; j < B[0].size(); j++){
            if(B[i][j] == 1){
                B[i][j] += B[i-1][j];
            }
        }
    }

    int maxArea = INT_MIN;
    for(int i = 0; i < B.size(); i++){
        maxArea = max(maxArea,maxAreaHistogram(B[i]));
    }
    return maxArea;
}
