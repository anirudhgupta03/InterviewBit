int Solution::maximumGap(const vector<int> &A) {
    
    int n = A.size();
    int right[n];
    
    right[n-1] = A[n-1];
    
    for(int i = n-2; i>=0; i--){
        right[i] = max(right[i+1],A[i]);
    }
    
    int ans = 0, j = 0;
    
    for(int i = 0; i < A.size(); i++){
        
        while(A[i] <= right[j] && j < A.size()){
            j++;
        }
        ans = max(ans,j-i-1);
    }
    return ans;
}
