//Method - 1
//Time Complexity - O(logN)
//Space Complexity - O(1)
int Solution::findCount(const vector<int> &A, int B) {
    
    int start = -1, n = A.size();
    
    int lo = 0, hi = n - 1;
    
    while(lo <= hi){
        
        int mid = (lo + hi)/2;
        
        if(A[mid] == B){
            start = mid;
            hi = mid - 1;
        }
        else if(A[mid] < B){
            lo = mid + 1;
        }
        else if(A[mid] > B){
            hi = mid - 1;
        }
    }
    
    if(start == -1){
        return 0;
    }
    
    int end = -1;
    lo = 0, hi = n -1;
    
    while(lo <= hi){
        
        int mid = (lo + hi)/2;
        
        if(A[mid] == B){
            end = mid;
            lo = mid + 1;
        }
        else if(A[mid] < B){
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    
    return end - start + 1;
}

//Method - 2
//Time Complexity - O(logN)
//Space Complexity - O(1)
int Solution::findCount(const vector<int> &A, int B) {
    
    return upper_bound(A.begin(),A.end(),B) - lower_bound(A.begin(),A.end(),B);
}
