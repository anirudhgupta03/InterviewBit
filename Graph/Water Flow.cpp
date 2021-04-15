/*
Run bfs twice, one from all the co-ordinates connected to red lake and other from blue lake.
Mark the visited cell and count the cell which are visited in both bfs.
Maintain a queue, initially append all the co-ordinates adjacent to blue lake. After that append all the cells adjacent to the current cell 
and have height >= height of current cell. Mark the cell blue. Do similar with cells adjacent to red lake.
Count the cells with both red and blue visited.
*/

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool isValid(int x, int y, int n, int m, vector<vector<int>> &vis){
    
    if(x < 0 || x >= n || y < 0 || y >= m){
        return false;
    }
    
    if(vis[x][y] == 1){
        return false;
    }
    
    return true;
}
void dfs(int x, int y, int n, int m, vector<vector<int>> &vis, vector<vector<int>> &A){
    
    vis[x][y] = 1;
    
    for(int i = 0; i < 4; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];
        
        if(isValid(newx,newy,n,m,vis)){
            if(A[newx][newy] >= A[x][y]){
                dfs(newx,newy,n,m,vis,A);
            }
        }
    }
}
int Solution::solve(vector<vector<int> > &A) {
    
    int n = A.size(), m = A[0].size();
    
    vector<vector<int>> blue(n,vector<int>(m,0));
    vector<vector<int>> red(n,vector<int>(m,0));
    
    for(int i = 0; i < n; i++){
        dfs(i,0,n,m,blue,A);
    }
    
    for(int i = 0; i < m; i++){
        dfs(0,i,n,m,blue,A);
    }
    
    for(int i = 0; i < n; i++){
        dfs(i,m-1,n,m,red,A);
    }
    
    for(int i = 0; i < m; i++){
        dfs(n-1,i,n,m,red,A);
    }
    
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(blue[i][j] && red[i][j]){
                ans++;
            }
        }
    }
    return ans;
}
