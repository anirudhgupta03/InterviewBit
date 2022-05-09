//Method - 1
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

//Method - 2
bool isValid(char ch, int row, int col, vector<vector<char>> &A){
    for(int j = 0; j < A[0].size(); j++){
        if(A[row][j] == ch){
            return false;
        }
    }
    for(int i = 0; i < A.size(); i++){
        if(A[i][col] == ch){
            return false;
        }
    }
    int temp = sqrt(A.size());
    for(int i = (row/temp)*temp; i < (row/temp)*temp + temp; i++){
        for(int j = (col/temp)*temp; j < (col/temp)*temp + temp; j++){
            if(A[i][j] == ch){
                return false;
            }
        }
    }
    return true;
}
bool solve(int row, int col, vector<vector<char>> &A){
    if(row == A.size()){
        return true;
    }
    if(col == A[0].size()){
        bool flag = solve(row + 1, 0, A);
        return flag;
    }
    if(A[row][col] != '.'){
        bool flag = solve(row, col + 1, A);
        return flag;
    }
    for(char ch = '1'; ch <= '9'; ch++){
        if(isValid(ch, row, col, A)){
            A[row][col] = ch;
            bool flag = solve(row, col + 1, A);
            if(flag){
                return true;
            }
            A[row][col] = '.';
        }
    }
    return false;
}
void Solution::solveSudoku(vector<vector<char> > &A) {
    solve(0,0,A);   
}
