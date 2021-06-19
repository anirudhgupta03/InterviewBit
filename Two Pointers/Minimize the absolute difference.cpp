int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    int m = A.size(), n = B.size(), o = C.size();
    
    int p1 = 0, p2 = 0, p3 = 0;
    
    int ans = INT_MAX;
    
    while(p1 < m && p2 < n && p3 < o){
        
        int maxe = max(A[p1],max(B[p2],C[p3]));
        int mine = min(A[p1],min(B[p2],C[p3]));
        
        ans = min(ans,maxe-mine);
        
        if(mine == A[p1]){
            p1++;
        }
        else if(mine == B[p2]){
            p2++;
        }
        else{
            p3++;
        }
    }
    return ans;
}
