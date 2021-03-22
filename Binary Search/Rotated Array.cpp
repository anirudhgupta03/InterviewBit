int Solution::findMin(const vector<int> &A) {
    
    int n = A.size();
    int l = 0, r = n - 1;
    
    while(l <= r){
        
        if(A[l] <= A[r]){
            return A[l];
        }
        int mid = (l+r)/2;
        int prev = (mid + n - 1)%n;
        int next = (mid+1)%n;
        
        if(A[mid] <= A[prev] && A[mid] <= A[next]){
            return A[mid];
        }
        else if(A[mid] >= A[l]){
            l = mid + 1;
        }
        else if(A[mid] <= A[r]){
            r = mid -1;
        }
    }
}
