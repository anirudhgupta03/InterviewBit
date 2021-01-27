int Solution::repeatedNumber(const vector<int> &A) {
    
    int arr[A.size()];
    
    for(int i = 0; i < A.size(); i++){
        arr[i] = A[i];
    }
    
    for(int i = 0; i < A.size(); i++){
        
        int j = abs(arr[i]);
        
        if(arr[j] < 0){
            return j;
        }
        
        arr[j] = -abs(arr[j]);
    }
    
    return -1;
}
