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
