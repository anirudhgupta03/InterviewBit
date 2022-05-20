//Method - 1
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

//Method - 2
int Solution::findMin(const vector<int> &A) {
    
    int n = A.size();
    
    if(n == 1){
        return A[0];
    }
    int lo = 0, hi = n - 1;
    
    while(lo <= hi){
        
        int mid = (lo + hi)/2;
        int prev = (mid+n-1)%n;
        int next = (mid + n - 1)%n;
        
        if(A[mid] < A[prev] && A[mid] < A[next]){
            return A[mid];
        }
        else if(A[mid] < A[n-1]){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
}

//Method - 3
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

//Method - 4
int Solution::findMin(const vector<int> &A) {
    
    int n = A.size();

    if(n == 1){
        return A[0];
    }
    int lo = 0, hi = A.size() - 1;

    while(lo <= hi){

        int mid = (lo + hi)/2;
        int next = (mid + 1)%n;
        int prev = (mid - 1 + n)%n;

        if(A[mid] < A[prev] && A[mid] < A[next]){
            return A[mid];
        }
        else if(A[mid] < A[hi]){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
}

//Method - 5
int Solution::findMin(const vector<int> &A) {
    
    int n = A.size();
    
    if(n == 1){
        return A[0];
    }
    
    int lo = 0, hi = n - 1;

    while(lo <= hi){

        int mid = (lo + hi)/2;
        int prevEle = (mid == 0) ? A[n - 1] : A[mid - 1];
        int nextEle = (mid == n - 1) ? A[0] : A[mid + 1];

        if(A[mid] < prevEle && A[mid] < nextEle){
            return A[mid];
        }
        else if(A[mid] > A[hi]){
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
}
