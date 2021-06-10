//Method - 1
int Solution::search(const vector<int> &A, int B) {
    
    int n = A.size();
    
    int lo = 0, hi = n - 1;
    
    int pivotInd;
    
    while(lo <= hi){
        
        int mid = (lo + hi)/2;
        int prev = (mid + n - 1)%n;
        int next = (mid + 1)%n;
        
        if(A[mid] < A[prev] && A[mid] < A[next]){
            pivotInd = mid;
            break;
        }
        else if(A[mid] < A[hi]){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    
    lo = 0, hi = pivotInd - 1;
    
    while(lo <= hi){
        
        int mid = (lo + hi)/2;
        
        if(A[mid] == B){
            return mid;
        }
        else if(A[mid] < B){
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    
    lo = pivotInd, hi = n - 1;
    
    while(lo <= hi){
        
        int mid = (lo + hi)/2;
        
        if(A[mid] == B){
            return mid;
        }
        else if(A[mid] < B){
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    return -1;
}

//Method - 2
//Optimal Approach
int Solution::search(const vector<int> &A, int B) {
    
    int l = 0, r = A.size() - 1;
    
    while(l <= r){
        int mid = (l+r)/2;
        
        if(A[mid] == B){
            return mid;
        }
        else if(A[mid] >= A[l]){
            if(B>=A[l] && B < A[mid]){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        else if(A[mid] <= A[r]){
            if(B<=A[r] && B > A[mid]){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
    }
    
    return -1;
}
