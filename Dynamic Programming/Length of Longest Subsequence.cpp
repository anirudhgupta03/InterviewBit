//Find LIS for original array and reverse array
int Solution::longestSubsequenceLength(const vector<int> &A) {
    
    int n = A.size();
    
    vector<int> fl(n,1);
    for(int i = 1; i < n; i++){
        
        for(int j = i - 1; j >= 0; j--){
            if(A[i] > A[j])
            fl[i] = max(fl[j]+1,fl[i]);
        }
    }
    
    vector<int> lf(n,1);
    for(int i = n - 2; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            
            if(A[i] > A[j])
            lf[i] = max(lf[j] +1, lf[i]);
        }
    }
    
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        ans = max(lf[i] + fl[i] - 1,ans);
    }
    
    return ans;
}
