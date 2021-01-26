void Solution::setZeroes(vector<vector<int> > &A) {
    
    int M = A.size(), N = A[0].size();
    int row[M] = {0}, column[N] = {0};
    
    for(int i = 0; i < M; i++){
        for(int j = 0 ; j < N; j++){
            
            if(A[i][j] == 0){
                row[i] = 1;
                column[j] = 1;
            }
            
        }
    }
    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            
            if(row[i] == 1){
                A[i][j] = 0;
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            
            if(column[i] == 1){
                A[j][i] = 0;
            }
        }
    }
}
