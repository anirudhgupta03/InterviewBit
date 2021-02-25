int Solution::nTriang(vector<int> &A) {
    
    int mod = 1000000007;
    
    sort(A.begin(),A.end());
    
    int count = 0;
    
    int n = A.size();
    
    for(int i = n - 1; i>=0; i--){
        
        int l = 0, r = i-1;
        
        while(l < r){
            if(A[l] + A[r] > A[i]){
                count = (count + r - l)%mod;
                r--;
            }
            else{
                l++;
            }
        }
    }
    return count;
}
