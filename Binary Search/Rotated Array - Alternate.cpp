int Solution::findMin(const vector<int> &A) {
    
    int n = A.size();
    
    if(n == 1){
        return A[0];
    }
    int lo = 0, hi = n - 1;
    
    while(lo <= hi){
        
        int mid = (lo + hi)/2;
        
        if(mid == 0 && A[0] <= A[1] && A[0] <= A[n-1]){
            return A[mid];
        }
        else if(mid == n - 1 && A[n-1] <= A[n-2] && A[n-1] <= A[0]){
            return A[mid];
        }
        else if(A[mid] <= A[mid-1] && A[mid] <= A[mid+1]){
            return A[mid];
        }
        else if(A[mid] <= A[hi]){
            hi = mid - 1;
        }
        else if(A[mid] >= A[lo]){
            lo = mid + 1;
        }
    }
}
