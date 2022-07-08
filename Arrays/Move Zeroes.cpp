vector<int> Solution::solve(vector<int> &A) {
    
    int pos = 0;
    
    for(int i = 0; i < A.size(); i++){
        if(A[i]){
            swap(A[i], A[pos]);
            pos++;
        }
    }
    return A;
}
