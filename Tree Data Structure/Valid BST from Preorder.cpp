//Method - 1
//Ref: https://www.youtube.com/watch?v=hPVDhNfO1Ng
//Time Complexity - O(N*N)
//Space Complexity - O(1)
bool helper(vector<int> &A, int l, int r){
    
    if(l >= r){
        return true;
    }
    int i;
    for(i = l + 1; i < r; i++){
        if(A[i] > A[l]){
            break;
        }
    }
    for(int j = i + 1; j < r; j++){
        if(A[j] < A[l]){
            return false;
        }
    }
    bool left = helper(A,l+1,i-1);
    bool right = helper(A,i+1,r);
    return left && right;
}
int Solution::solve(vector<int> &A) {
    return helper(A,0,A.size() - 1);
}

//Method - 2
//Ref: https://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/
//Ref: https://www.youtube.com/watch?v=hPVDhNfO1Ng
//Ref: https://www.youtube.com/watch?v=GYdC4hQSo8A
//Time Complexity - O(N)
//Space Complexity - O(N)
int Solution::solve(vector<int> &A) {
    
    int root = INT_MIN;
    
    stack<int> s;
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] < root){
            return 0;
        }
        while(!s.empty() && A[i] > s.top()){
            root = s.top();
            s.pop();
        }
        s.push(A[i]);
    }
    return 1;
}

//Method - 3(Question Updated)
int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    
    stack<int> st;
    
    int topEle = INT_MIN;
    
    unordered_set<int> us;
    
    for(int i = 0; i < A.size(); i++){
        
        if(us.find(A[i]) != us.end()) return 0;
        
        us.insert(A[i]);
        
        if(A[i] < topEle){
            return 0;
        }
        while(!st.empty() && A[i] > st.top()){
            topEle = st.top();
            st.pop();
        }
        st.push(A[i]);
    }
    return 1;
}
