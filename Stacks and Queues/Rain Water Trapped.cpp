//Method - 1
//TC - O(N)
//SC - O(2*N)
int Solution::trap(const vector<int> &A) {
    
    int n = A.size();
    
    int left[n], right[n];
    
    left[0] = A[0];
    
    for(int i = 1; i < n; i++){
        left[i] = max(left[i-1],A[i]);
    }
    
    right[n-1] = A[n-1];
    for(int i = n - 2; i >= 0; i--){
        right[i] = max(right[i+1],A[i]);
    }
    
    int amt = 0;
    for(int i = 1; i <= n - 2; i++){
        
        if(left[i-1] > A[i] && A[i] < right[i+1]){
            amt += min(left[i-1],right[i+1]) - A[i];
        }
    }
    return amt;
}

//Method - 2
//Using Stack
//TC - O(N)
//SC - O(2*N)
int Solution::trap(const vector<int> &A) {

    int n = A.size();

    vector<int> ngl(n), ngr(n);
    stack<int> st;

    st.push(A[0]);
    ngl[0] = -1;

    for(int i = 1; i < n; i++){
        if(A[i] < st.top()){
            ngl[i] = st.top();
        }
        else{
            while(!st.empty() && A[i] >= st.top()){
                st.pop();
            }
            if(st.empty()){
                ngl[i] = -1;
                st.push(A[i]);
            }
            else{
                ngl[i] = st.top();
            }
        }
    }
    while(!st.empty()){
        st.pop();
    }

    st.push(A[n - 1]);
    ngr[n - 1] = -1;
    
    for(int i = n - 2; i >= 0; i--){
        if(A[i] < st.top()){
            ngr[i] = st.top();
        }
        else{
            while(!st.empty() && A[i] >= st.top()){
                st.pop();
            }
            if(st.empty()){
                ngr[i] = -1;
                st.push(A[i]);
            }
            else{
                ngr[i] = st.top();
            }
        }
    }
    
    int totalWater = 0;
    for(int i = 1; i < n - 1; i++){
        if(ngl[i] != -1 && ngr[i] != -1){
            totalWater += min(ngl[i], ngr[i]) - A[i];
        }
    }
    return totalWater;
}

//Method - 3
//Using Two Pointers
//Ref: https://www.youtube.com/watch?v=m18Hntz4go8
//TC - O(N)
//SC - O(1)
int Solution::trap(const vector<int> &A) {

    int n = A.size();

    int lo = 0, hi = n - 1, lmax = 0, rmax = 0;

    int totalWater = 0;

    while(lo <= hi){
        if(A[lo] <= A[hi]){
            if(A[lo] >= lmax){
                lmax = A[lo];
            }
            else{
                totalWater += lmax - A[lo];
            }
            lo++;
        }
        else{
            if(A[hi] >= rmax){
                rmax = A[hi];
            }
            else{
                totalWater += rmax - A[hi];
            }
            hi--;
        }
    }
    return totalWater;
}
