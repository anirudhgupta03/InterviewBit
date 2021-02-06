vector<int> Solution::searchRange(const vector<int> &A, int B) {
    
    int l = 0, r = A.size() - 1, start = -1, end = -1;
    
    while(l <= r){
        
        int mid = (l+r)/2;
        
        if(A[mid] > B){
            r = mid - 1;
        }
        else if(A[mid] < B){
            l = mid + 1;
        }
        else{
            start = mid;
            r = mid - 1;
        }
    }
    vector<int> v;
    if(start == -1){
        v.push_back(-1);
        v.push_back(-1);
        return v;
    }
    
    l = 0, r = A.size() - 1;
    
    while(l<=r){
        
        int mid = (l+r)/2;
        
        if(A[mid] > B){
            r = mid -1;
        }
        else if(A[mid] < B){
            l = mid + 1;
        }
        else if(A[mid] == B){
            end = mid;
            l = mid + 1;
        }
    }
    v.push_back(start);
    v.push_back(end);
    return v;
}
