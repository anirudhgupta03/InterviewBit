/*
Run bfs twice, one from all the co-ordinates connected to red lake and other from blue lake.
Mark the visited cell and count the cell which are visited in both bfs.
Maintain a queue, initially append all the co-ordinates adjacent to blue lake. After that append all the cells adjacent to the current cell 
and have height >= height of current cell. Mark the cell blue. Do similar with cells adjacent to red lake.
Count the cells with both red and blue visited.
Ref: https://www.youtube.com/watch?v=krL3r7MY7Dc
*/
//Method - 1
//Using DFS
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

//Method - 2
//Using BFS
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int Solution::solve(vector<vector<int> > &A) {
    
    int n = A.size(), m = A[0].size();
    vector<vector<int>> redLake(n, vector<int>(m,0)), blueLake(n, vector<int>(m, 0));
    queue<pair<int,int>> q;
    
    for(int i = 0; i < n; i++){
        q.push({i, 0});
    }
    for(int j = 1; j < m; j++){
        q.push({0, j});
    }
    
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        if(redLake[x][y]) continue;
        redLake[x][y] = 1;
        
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < n && yo < m && A[xo][yo] >= A[x][y] && redLake[xo][yo] == 0){
                q.push({xo, yo});
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        q.push({i, m - 1});
    }
    for(int j = 0; j < m - 1; j++){
        q.push({n - 1, j});
    }
    
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        if(blueLake[x][y]) continue;
        blueLake[x][y] = 1;
        
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < n && yo < m && A[xo][yo] >= A[x][y] && blueLake[xo][yo] == 0){
                q.push({xo, yo});
            }
        }
    }
    
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(redLake[i][j] && blueLake[i][j]){
                count++;
            }
        }
    }
    return count;
}
