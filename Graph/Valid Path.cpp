//Ref: https://www.youtube.com/watch?v=In6MrAYjeZw
//Using BFS
int dx[8] = {1,-1,0,0,1,1,-1,-1};
int dy[8] = {0,0,1,-1,1,-1,-1,1};

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {

    vector<vector<bool>> mat(A+1,vector<bool>(B+1));

    for(int i = 0; i <= A; i++){
        for(int j = 0; j <= B; j++){
            
            bool flag = false;

            int x = i, y = j;

            for(int k = 0; k < E.size(); k++){
                int cx = E[k], cy = F[k];

                if((x-cx)*(x-cx) + (y-cy)*(y-cy) <= D*D){
                    flag = true;
                    break;
                }
            }

            mat[i][j] = flag;
        }
    }

    vector<vector<int>> vis(A+1,vector<int>(B+1,0));
    vis[0][0] = 1;

    queue<pair<int,int>> q;

    q.push({0,0});

    while(!q.empty()){

        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++){
            int xo = x + dx[i], yo = y + dy[i];

            if(xo >= 0 && xo <= A && yo >= 0 && yo <= B && mat[xo][yo] == false && vis[xo][yo] == 0){
                q.push({xo,yo});
                vis[xo][yo] = 1;
            }
        }
    }

    if(vis[A][B]){
        return "YES";
    }
    return "NO";
}

//Using DFS
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool rec(int x, int y, vector<vector<int>> &grid){

    grid[x][y] = 1;

    if(x == grid.size() - 1 && y == grid[0].size() - 1){
        return true;
    }
    for(int i = 0; i < 4; i++){
        int xo = x + dx[i], yo = y + dy[i];
        if(xo >= 0 && yo >= 0 && xo < grid.size() && yo < grid[0].size()){
            if(grid[xo][yo] == 0){
                bool flag = rec(xo, yo, grid);
                if(flag) return true;
            }
        }
    }
    return false;
}
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {

    vector<vector<int>> grid(A + 1, vector<int>(B + 1, 0));

    for(int i = 0; i <= A; i++){
        for(int j = 0; j <= B; j++){

            for(int k = 0; k < C; k++){
                int x1 = i, x2 = E[k], y1 = j, y2 = F[k];
                if((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) <= D*D){
                    grid[x1][y1] = 1;
                    break;
                }
            }
        }
    }
    if(grid[0][0] == 1 || grid[A][B] == 1){
        return "NO";
    }
    bool flag = rec(0,0,grid);
    if(flag) return "YES";
    return "NO";
}

//Using BFS
int dx[8] = {-1,1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    
    vector<vector<int>> grid(A + 1, vector<int>(B + 1, 1));
    
    for(int i = 0; i <= A; i++){
        for(int j = 0; j <= B; j++){
            for(int k = 0; k < E.size(); k++){
                int dist = (E[k] - i)*(E[k] - i) + (F[k] - j)*(F[k] - j);
                if(dist <= D*D){
                    grid[i][j] = 0;
                    break;
                }
            }
        }
    }
    if(grid[0][0] == 0 || grid[A][B] == 0){
        return "NO";
    } 
    queue<pair<int,int>> q;
    q.push({0,0});
    
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        if(x == A && y == B){
            return "YES";
        }
        if(grid[x][y] == 0) continue;
        grid[x][y] = 0;
        for(int i = 0; i < 8; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo <= A && yo <= B && grid[xo][yo]){
                q.push({xo, yo});
            }
        }
    }
    return "NO";
}
