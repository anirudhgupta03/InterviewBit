int Solution::solve(vector<int> &A) {
    int n = A.size();
    int prevtoprev = A[0], prev = A[0] + A[1];
    for(int i = 2; i < n; i++){
        int temp = min(prevtoprev, prev) + A[i];
        prevtoprev = prev;
        prev = temp;
    }
    return prev;
}
