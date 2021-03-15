bool isSafe(int num, vector<vector<char> > &A, int row, int col, int block){
    
    for(int j = 0; j < block*block; j++){
        
        if(A[row][j] == num + 48){
            return false;
        }
    }
    
    for(int i = 0; i < block*block; i++){
        
        if(A[i][col] == num + 48){
            return false;
        }
    }
    
    for(int i = (row/block)*block; i < (row/block)*block + block; i++){
        for(int j = (col/block)*block; j < (col/block)*block + block; j++){
            if(A[i][j] == num + 48){
                return false;
            }
        }
    }
    
    return true;
}
void solve(int row,int col,vector<vector<char> > &A, int n, vector<vector<char> > &ans){
    
    if(row == n - 1 && col == n){   //row will be n - 1 
        ans = A;
        return;
    }
    
    if(col == n){
        col = 0;
        row++;
    }
    
    if(A[row][col] == '.'){
        
        for(int k = 1; k <= 9; k++){
                    
            if(isSafe(k,A,row,col,sqrt(n))){
                A[row][col] = k+48;         // no need of typecasting
                solve(row,col+1,A,n,ans);
                A[row][col] = '.';
            }
            
        }
    }
    else{
        solve(row,col+1,A,n,ans);
    }
}
void Solution::solveSudoku(vector<vector<char> > &A) {
    
    int n = A.size();
    
    vector<vector<char> > ans;    //to store the answer matrix A
    
    solve(0,0,A,n,ans);
    
    A = ans;
}
