int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    
    int n = A.size(), m =A[0].size(),l = 0, r = n*m - 1;
       
        while(l<=r){
            int mid = (l+r)/2;
            
            int x = mid/m;
            int y = mid%m;
            if(A[x][y] > B){
                r = mid - 1;
            }
            else if(A[x][y] < B){
                l = mid + 1;
            }
            else{
                return 1;
            }
        }
    return 0;
}
