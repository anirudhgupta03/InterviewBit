//Method - 1
//Time Complexity - O(M*N)
//Space Complexity - O(M+N)
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

//Method - 2
//Time Complexity - O(M*N)
//Space Complexity - O(M+N)
void Solution::setZeroes(vector<vector<int> > &A) {
    
    int m = A.size(), n = A[0].size();
    
    vector<int> row(m,0);
    vector<int> col(n,0);
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(A[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(row[i] == 1 || col[j] == 1){
                A[i][j] = 0;
            }
        }
    }
    
}

//Method - 3
//Time Complexity - O(M*N)
//Space Complexity - O(1)
//Ref: https://www.youtube.com/watch?v=M65xBewcqcI
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
