//Ref: https://discuss-files.s3.dualstack.us-west-2.amazonaws.com/original/4X/8/e/b/8ebc61de734c588cfab93e9b253b35a0df2e78a7.gif
//Time Complexity - O(N)
//Space Complexity - O(1)
int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    
    int p1 = 0, p2 = 0, p3 = 0;
    
    int m = A.size(), n = B.size(), p = C.size();
    
    int ans = INT_MAX;
    
    while(p1 < m && p2 < n && p3 < p){
        
        int d12 = A[p1] - B[p2], d23 = B[p2] - C[p3], d31 = C[p3] - A[p1];
        
        int abs1 = abs(d12), abs2 = abs(d23), abs3 = abs(d31);
        
        int maxDiff = max(abs1,max(abs2,abs3));
        
        ans = min(ans,maxDiff);
        
        if(maxDiff == abs1){
            if(d12 < 0) p1++;
            else        p2++;
        }
        else if(maxDiff == abs2){
            if(d23 < 0) p2++;
            else        p3++;
        }
        else{
            if(d31 < 0) p3++;
            else        p1++;
        }
    }
    return ans;
}
