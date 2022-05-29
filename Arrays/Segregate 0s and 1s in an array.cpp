vector<int> Solution::solve(vector<int> &A) {

    int lo = 0;

    for(int i = 0; i < A.size(); i++){
        if(A[i] == 0){
            swap(A[lo], A[i]);
            lo++;
        }
    }
    return A;
}
