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
