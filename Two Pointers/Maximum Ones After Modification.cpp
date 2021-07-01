int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    
    int count = 0;
    
    int lo = 0, hi = 0, maxLen = 0;
    
    while(hi < A.size()){
        
        if(A[hi] == 0){
            count++;
        }
        
        if(count > B){
            maxLen = max(maxLen,hi-lo);
            
            while(A[lo] != 0 && lo < hi){
                lo++;
            }
            lo++;
            count--;
        }
        hi++;
    }
    maxLen = max(maxLen,hi-lo);
    return maxLen;
}
