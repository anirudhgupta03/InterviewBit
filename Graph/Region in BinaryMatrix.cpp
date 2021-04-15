//Find the connected component with maximum size
int dx[8] = {-1,-1,1,1,0,0,1,-1};
int dy[8] = {-1,1,-1,1,-1,1,0,0};

bool isValid(int x, int y, vector<vector<int>> &vis, vector<vector<int>> &A){
    
    int n = A.size(), m = A[0].size();
    
    if(x < 0 || x >= n || y < 0 || y >= m){
        return false;
    }
    
    if(vis[x][y] == 1 || A[x][y] == 0){
        return false;
    }
    
    return true;
}
void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<int>> &A, int &count){
    
    vis[x][y] = 1;
    
    for(int i = 0; i < 8; i++){
        
        int newx = x + dx[i];
        int newy = y + dy[i];
        
        if(isValid(newx,newy,vis,A)){
            dfs(newx,newy,vis,A,count);
            count++;
        }
    }
}
int Solution::solve(vector<vector<int> > &A) {
    
    int n = A.size(), m = A[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    
    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int count = 1;
            if(A[i][j] == 1 && vis[i][j] == 0){
                dfs(i,j,vis,A,count);
                ans = max(ans,count);
            }
        }
    }
    return ans;
}
