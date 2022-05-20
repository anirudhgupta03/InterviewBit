//Method - 1
//Time Complexity - O(32*NlogM)
//Space Complexity - O(1)
int Solution::findMedian(vector<vector<int> > &A) {
    
    int l = INT_MAX, r = INT_MIN, n = A.size(), m = A[0].size();
    
    for(int i = 0; i < n; i++){
        l = min(l,A[i][0]);
    }
    
    for(int i = 0; i < n; i++){
        r = max(r,A[i][m-1]);
    }
    
    int count = (1+n*m)/2, sum , median;
    
    while(l <= r){
        
        int mid = (l+r)/2;
        
        sum = 0;
        
        for(int i = 0; i < n; i++){
            sum += upper_bound(A[i].begin(),A[i].end(),mid) - A[i].begin();
        }
        
        if(sum >= count){   //In case of equal elements sum can be greater than count but that mid can also be an answer
            median= mid;
            r = mid-1;
        }
        else if(sum < count){
            l = mid + 1;
        }
    }
    return median;
}

//Method - 2
int elementsLessThanOrEqualToMedian(int median, vector<vector<int>> &A){
    int count = 0, n = A.size(), m = A[0].size();
    
    for(int i = 0; i < n; i++){
        
        int ind = -1, lo = 0, hi = m - 1;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(A[i][mid] <= median){
                ind = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        count += ind + 1;
    }
    return count;
}
int Solution::findMedian(vector<vector<int> > &A) {

    int n = A.size(), m = A[0].size();

    int lo = INT_MAX, hi = INT_MIN;

    for(int i = 0; i < n; i++){
        lo = min(lo, A[i][0]);
        hi = max(hi, A[i][m - 1]);
    }

    int count = (m*n + 1)/2, ans;

    while(lo <= hi){
        int mid = (lo + hi)/2;
        
        if(elementsLessThanOrEqualToMedian(mid, A) >= count){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    return ans;
}
