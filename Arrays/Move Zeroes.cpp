vector<int> Solution::solve(vector<int> &A) {

    int ind = 0;
    for(int i = 0; i < A.size(); i++){
        if(A[i]){
            A[ind] = A[i];
            ind++;
        }
    }
    for(int i = ind; i < A.size(); i++){
        A[i] = 0;
    }
    return A;
}
