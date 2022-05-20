//Method - 1
int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    
    int lo = 0, hi = A.size() - 1;
    
    int bitonicInd;
    
    while(lo <= hi){
        int mid = (lo + hi)/2;
        
        if(mid != 0 && mid != n-1 && A[mid] > A[mid+1] && A[mid] > A[mid-1]){
           bitonicInd = mid;
           break;
        }
        else if((mid == 0 || mid != 0 && A[mid] > A[mid-1]){
            lo = mid + 1;
        }
        else if(mid == n -  || mid != n - 1 && A[mid] < A[mid-1]){
            hi = mid - 1;
        }
    }
    
    lo = 0, hi = bitonicInd;
    
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
    
    lo = bitonicInd + 1, hi = n - 1;
    
    while(lo <= hi){
        
        int mid = (lo + hi)/2;
        
        if(A[mid] == B){
            return mid;
        }
        else if(A[mid] < B){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    return -1;
}

//Method - 2
//Optimal Method
int Solution::solve(vector<int> &A, int B) {

    int n = A.size();

    int lo = 0, hi = n - 1, pivot;

    while(lo <= hi){
        int mid = (lo + hi)/2;

        if(A[mid] > A[mid - 1] && A[mid] > A[mid + 1]){
            pivot = mid;
            break;
        }
        else{
            if(A[mid] < A[mid + 1]){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
    }
    
    if(A[pivot] == B){
        return pivot;
    }
    lo = 0, hi = pivot - 1;

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

    lo = pivot + 1, hi = n - 1;

    while(lo <= hi){
        int mid = (lo + hi)/2;

        if(A[mid] == B){
            return mid;
        }
        else if(A[mid] < B){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    return -1;
}
