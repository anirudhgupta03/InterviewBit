//Finding number of connected components in 2D grid using DFS
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

bool isValid(int x, int y,  vector<vector<int>> &vis, vector<string> &A){
    
    if(x < 0 || x >= A.size() || y < 0 || y >= A[0].size()){
        return false;
    }
    
    if(vis[x][y] == 1 || A[x][y] == 'O'){
        return false;
    }
    return true;
}
void dfs(int x, int y, vector<vector<int>> &vis, vector<string> &A){
    
    vis[x][y] = 1;
    
    for(int i = 0; i < 4; i++){
        
        int newx = x + dx[i], newy = y + dy[i];
        if(isValid(newx,newy,vis,A)){
            dfs(newx,newy,vis,A);
        }
    }
}
int Solution::black(vector<string> &A) {
    
    int n = A.size(), m = A[0].size();
    
    vector<vector<int>> vis(n,vector<int>(m,0));
    
    int count = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            if(vis[i][j] == 0 && A[i][j] == 'X'){
                count++;
                dfs(i,j,vis,A);
            }
        }
    }
    return count;
}
