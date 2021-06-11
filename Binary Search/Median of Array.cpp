double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    
    if(A.size() > B.size()){
        return findMedianSortedArrays(B,A);
    }
    
    double e1,e2;
    
    int n1 = A.size(), n2 = B.size();
    
    int lo = 0, hi = n1, la, lb, ra, rb;
    
    while(lo <= hi){
        
        int cut1 = (lo + hi) >> 1;
        int cut2 = ((n1+n2+1)/2 - cut1);
        
        if(cut1 == 0){
            la = INT_MIN;
        }
        else{
            la = A[cut1-1];
        }
        
        if(cut1 == n1){
            ra = INT_MAX;
        }
        else{
            ra = A[cut1];
        }
        
        int temp = p - mid;
        
        if(cut2 == 0){
            lb = INT_MIN;
        }
        else{
            lb = B[cut2-1];
        }
        
        if(cut2 == n2){
            rb = INT_MAX;
        }
        else{
            rb = B[cut2];
        }
        
        if(la <= rb && lb <= ra){
            e1 = max(la,lb);
            e2 = min(ra,rb);
            break;
        }
        else if(la > rb){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    
    if((n1+n2) % 2 == 0){
        return (e1 + e2)/2;
    }
    return e1;
} 
