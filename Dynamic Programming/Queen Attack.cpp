//Time Complexity - O(8*n*m)
//Method - 1
int dx[8] = {-1,1,-1,-1,1,1,0,0};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

bool isValid(int x, int y, int n, int m){
    
    if(x < 0 || x >= n || y < 0 || y >= m){
        return false;
    }
    return true;
}
void solve(int x, int y, vector<vector<int>> &res, vector<string> &A, int n, int m){
    
    for(int i = 0; i < 8; i++){
        
        int xo = x, yo = y;
        
        while(1){
            xo = xo + dx[i], yo = yo + dy[i];
            
            if(isValid(xo,yo,n,m)){
                res[xo][yo] += 1;
            }
            else{
                break;
            }
            
            if(A[xo][yo] == '1'){       //Now after this queen can't attack as it can't jump over another queen
                break;
            }
        }
    }
}
vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    
    int n = A.size(), m = A[0].size();
    
    vector<vector<int>> res(n,vector<int>(m,0));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] == '1'){
                solve(i,j,res,A,n,m);
            }
        }
    }
    return res;
}

//Method - 2
int dx[8] = {-1,1,0,0,1,1,-1,-1};
int dy[8] = {0,0,-1,1,1,-1,1,-1};
int solve(int i, int j, vector<vector<int>> &dp, vector<string> &A, int dirx, int diry){
    
    if(i < 0 || j < 0 || i >= A.size() || j >= A[0].size()){
        return 0;
    }
    
    if(dp[i][j] != -1) return dp[i][j];
    if(A[i][j] == '1') return 1;
    
    return dp[i][j] = solve(i + dirx,j + diry, dp, A, dirx, diry);
}
vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    
    int n = A.size(), m = A[0].size();
    
    vector<vector<int>> ans(n, vector<int>(m, 0));
    vector<vector<vector<int>>> dir(8, vector<vector<int>>(n, vector<int>(m, -1)));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 8; k++){
                
                int x = i + dx[k], y = j + dy[k];
                ans[i][j] += solve(x, y, dir[k], A, dx[k], dy[k]);
            }
        }
    }
    return ans;
}
