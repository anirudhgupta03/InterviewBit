//Ref: https://www.youtube.com/watch?v=elADMOC_hDI
int Solution::solve(vector<vector<int> > &A) {
    
    int n = A.size(), m = A[0].size();
    
    if(n == 0){
        return 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++){
            A[i][j] += A[i][j-1];
        }
    }
    
    int count = 0;
    
    for(int c1 = 0; c1 < m; c1++){
        for(int c2 = c1; c2 < m; c2++){
            
            unordered_map<int,int> umap;
            umap[0] = 1;
            
            int sum = 0;
            
            for(int row = 0; row < n; row++){
                sum += A[row][c2] - (c1 > 0 ? A[row][c1-1] : 0);
                count += umap[sum];
                umap[sum]++;
            }
        }
    }
    
    return count;
}
