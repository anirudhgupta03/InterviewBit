void Solution::arrange(vector<int> &A) {
    
    for(int i = 0; i < A.size(); i++){
        int b = A[A[i]]%A.size();
        A[i] = A[i] + b*A.size();
    }
    
    for(int i = 0; i < A.size(); i++){
        A[i] = A[i]/A.size();
    }
}
