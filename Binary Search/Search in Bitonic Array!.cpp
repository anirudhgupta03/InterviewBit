int Solution::solve(vector<int> &A, int B) {
    
    int l = 0, r = A.size() - 1 ,ind;
    
    while(l<=r){
        
        int mid = (l+r)/2;
        
        if(A[mid] > A[mid-1] && A[mid] > A[mid+1]){
                ind = mid;
                break;
        }
        else if(A[mid] < A[mid+1]){
            l = mid + 1;
        }
        else if( A[mid] < A[mid-1]){
            r = mid - 1;
        }
        
    }
    
    l = 0, r= ind - 1;
    
    while(l<=r){
        
        int mid = (l+r)/2;
        
        if(A[mid] < B){
            l =  mid + 1;
        }
        else if(A[mid] > B){
            r = mid - 1;
        }
        else{
            return mid;
        }
    }
    
    l = ind+1, r= A.size()-1;
    
    while(l<=r){
        
        int mid = (l+r)/2;
        
        if(A[mid] > B){
            l =  mid + 1;
        }
        else if(A[mid] < B){
            r = mid - 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
