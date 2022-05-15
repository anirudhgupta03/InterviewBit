//Method - 1
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

//Method - 2
int Solution::solve(vector<int> &A, int B) {

    int n = A.size();

    int lo = 0, hi = 0;

    int maxLen = 0;

    while(hi < A.size()){
        if(A[hi] == 1){
            hi++;
        }
        else{
            B--;
            if(B < 0){
                while(lo < hi && A[lo] == 1) lo++;
                lo++;
                B++;
            }
            hi++;
        }
        maxLen = max(maxLen, hi - lo);
    }
    maxLen = max(maxLen, hi - lo);
    return maxLen;
}
