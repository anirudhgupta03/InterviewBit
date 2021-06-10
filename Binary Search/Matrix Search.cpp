//Brute Force Approach
//Time Complexity - O(NlogM)
//Space Complexity - O(1)
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

//Optimal Approach
//Time Complexity - O(log(M*N))
//Space Complexity - O(1)
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
