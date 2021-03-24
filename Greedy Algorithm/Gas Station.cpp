int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    
    int s = 0, d = 0, start = 0, n = A.size();
    
    for(int i = 0; i < n; i++){
        
        if(A[i] + s >= B[i]){
            s += A[i] - B[i];
        }
        else{
            start = (i + 1)%n;
            d += A[i] + s - B[i];
            s = 0;
        }
    }
    
    if(s + d >= 0){
        return start;
    }
    return -1;
}
