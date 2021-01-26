void Solution::setZeroes(vector<vector<int> > &A) {
    
    int M = A.size(), N = A[0].size();
    
    bool b1 = false, b2 = false;
    
    for(int i = 0; i < N; i++){
        if(A[0][i] == 0){
            b1 = true;
        }
    }
    
    for(int i = 0; i < M; i++){
        if(A[i][0] == 0){
            b2 = true;
        }
    }
    
    for(int i = 1; i < M; i++){
        for(int j = 1; j < N; j++){
            if(A[i][j] == 0){
                A[i][0] = 0;
                A[0][j] = 0;
            }
        }
    }
    
    for(int i = 1; i < M; i++){
        for(int j = 1; j < N; j++){
            if(A[i][0] == 0 || A[0][j] == 0){
                A[i][j] = 0;
            }
        }
    }
    
    if(b1){
        for(int i = 0; i < N; i++){
            A[0][i] = 0;
        }
    }
    if(b2){
        for(int i = 0; i < M; i++){
            A[i][0] = 0;
        }
    }
}
