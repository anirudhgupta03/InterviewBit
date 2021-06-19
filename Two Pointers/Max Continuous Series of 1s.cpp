vector<int> Solution::maxone(vector<int> &A, int B) {
    
    int n = A.size();
    
    int lo = 0, hi = 0, count = 0;
    
    int maxLen = 0, start = 0;
    
    while(hi < A.size()){
        
        if(A[hi] == 0){
            count++;
        }
        
        if(count > B){
            if(hi-lo > maxLen){
                start = lo;
                maxLen = hi-lo;
            }
            while(lo < hi && A[lo] != 0){
                    lo++;
            }
            lo++;
            count--;
        }
        hi++;
    }
    if(hi-lo > maxLen){
        start = lo;
        maxLen = hi-lo;
    }
  
    vector<int> res;
    for(int j = start; j < start + maxLen; j++){
        res.push_back(j);
    }
    return res;
}
