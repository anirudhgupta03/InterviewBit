int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    
    int n = A.size(), m =A[0].size();
    
    for(int i = 0; i < n; i++){
        int l = 0, r= m - 1;
       
        while(l<=r){
            int mid = (l+r)/2;
            if(A[i][mid] > B){
                r = mid - 1;
            }
            else if(A[i][mid] < B){
                l = mid + 1;
            }
            else{
                return 1;
            }
        }
    }
    return 0;
}
