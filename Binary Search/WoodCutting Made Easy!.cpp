//Method - 1
long long woodcut(int height, vector<int> A){
    
    long long wood = 0;
    for(auto x : A){
        wood += max(x-height,0); 
    }
    
    return wood;
}
int Solution::solve(vector<int> &A, int B) {
    
    int l = 0 , r = INT_MIN;
    
    for(auto x : A){
        r = max(r,x);
    }
    
    int ans;
    while(l<=r){
        
        int mid = (l+r)/2;
        
        if(woodcut(mid,A) > B){
            ans = mid;
            l = mid + 1;
        }
        else if(woodcut(mid,A) == B){
            return mid;
        }
        else if(woodcut(mid,A) < B){
            r = mid - 1;
        }
    }
    return ans;
}

//Method - 2
#define ll long long
bool isPossibleToCut(int h, vector<int> &A, int B){
    
    ll woodCut = 0;
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i]-h > 0){
            woodCut += A[i]-h;
        }
    }
    
    if(woodCut >= B){
        return true;
    }
    return false;
}
int Solution::solve(vector<int> &A, int B) {
    
    int lo = 0, hi = INT_MIN;
    
    for(int x: A){
        hi = max(hi,x);
    }
    
    int reqHeight;
    
    while(lo <= hi){
        
        int mid = (lo + hi)/2;
        
        if(isPossibleToCut(mid,A,B)){
            reqHeight = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    return reqHeight;
}
