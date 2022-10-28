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
