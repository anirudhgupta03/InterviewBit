bool isSafeForQueen(vector<string> &v, int row, int col){
    
    for(int i = row, j = col; i>=0; i--){
        
        if(v[i][j] == 'Q')
            return false;
        
    }
    
    for(int i = row, j = col; i>=0 && j>=0; i--,j--){
        
        if(v[i][j] == 'Q')
            return false;

    }
    
    for(int i = row, j = col; i>=0 && j < v.size(); i--,j++){
        
        if(v[i][j] == 'Q')
            return false;
        
    }
    
    return true;
}
void solve(vector<string> &v, vector<vector<string>> &vec, int A, int row){
    
    if(row == A){
        vec.push_back(v);
        return;
    }
    
    for(int col = 0; col < A; col++){
        
        if(isSafeForQueen(v,row,col) == true){
            
            v[row][col] = 'Q';
            solve(v,vec,A,row+1);
            v[row][col] = '.';
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    
    vector<string> v;
    string s;
    
    for(int i = 0; i < A; i++){
        s.push_back('.');
    }
    for(int i = 0; i < A; i++){
        v.push_back(s);
    }
    
    vector<vector<string>> vec;
    
    solve(v,vec,A,0);
    
    return vec;
}
