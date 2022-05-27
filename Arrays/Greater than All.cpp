int Solution::solve(vector<int> &A) {

    int maxEle = INT_MIN;

    int count = 0;

    for(int i = 0; i < A.size(); i++){
        if(A[i] > maxEle){
            count++;
            maxEle = A[i];
        }
    }
    return count;
}
