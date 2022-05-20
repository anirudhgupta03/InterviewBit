//Method - 1
int Solution::solve(vector<int> &A, int B) {
    
    int l = 0, r = A.size() - 1, ind = -1;
    
    while(l <= r){
        int mid = (l+r)/2;
        
        if(A[mid] > B){
            r = mid - 1;
        }
        else if(A[mid] <= B){
            ind  = mid;
            l = mid+1;
        }
    }
    return ind+1;
}

//Method - 2
int Solution::solve(vector<int> &A, int B) {

    int lo = 0, hi = A.size() - 1, ans = A.size();

    while(lo <= hi){

        int mid = (lo + hi)/2;

        if(A[mid] > B){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    return ans;
}
