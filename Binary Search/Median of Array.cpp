//Method - 1
//Optimal Approach
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

//Method - 2
#define ll long long
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    
    if(A.size() < B.size()){
        return findMedianSortedArrays(B, A);
    }
    int m = A.size(), n = B.size();

    if(m == 0){
        if(n % 2 == 0){
            return (B[n/2 - 1] + B[n/2])/2.0;
        }
        else{
            return B[n/2];
        }
    }
    if(n == 0){
        if(m % 2 == 0){
            return (A[m/2 - 1] + A[m/2])/2.0;
        }
        else{
            return A[m/2];
        }
    }

    ll count = (m + n + 1)/2;

    ll lo = 0, hi = m;

    while(lo <= hi){

        ll mid = (lo + hi)/2;

        if(mid > count){
            hi--;
            continue;
        }
        ll temp = count - mid;
        
        if(temp > n){
            lo++;
            continue;
        }

        ll lu, ru, ld, rd;

        if(mid == 0) lu = INT_MIN;
        else lu = A[mid - 1];

        if(mid == m) ru = INT_MAX;
        else ru = A[mid];

        if(temp == 0) ld = INT_MIN;
        else ld = B[temp - 1];

        if(temp == n) rd = INT_MAX;
        else    rd = B[temp];
        
        if(lu <= rd && ld <= ru){
            if((m + n) % 2 == 0){
                return (max(lu,ld) + min(ru, rd))/2.0;
            }
            else{
                return max(lu,ld);
            }
        } 
        else if(lu > rd){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
}
