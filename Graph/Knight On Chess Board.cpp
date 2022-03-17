//SSSP in 2D grid using BFS
int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {-1,1,-2,2,-2,2,-1,1};

bool isValid(int x, int y, int A, int B, vector<vector<int>> &vis){
    
    if(x < 0 || x >= A || y < 0 || y >= B){
        return false;
    }
    
    if(vis[x][y] == true){
        return false;
    }
    return true;
}
int bfs(int A, int B, int C, int D, int E, int F){
    
    vector<vector<int>> vis(A,vector<int>(B,0));
    vector<vector<int>> dist(A,vector<int>(B,-1));
    
    queue<pair<int,int>> q;
    q.push({C-1,D-1});
    
    dist[C-1][D-1] = 0;
    vis[C-1][D-1] = 1;
    
    while(!q.empty()){
        int currx = q.front().first, curry = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++){
            int newx = currx + dx[i], newy = curry + dy[i];
            if(isValid(newx,newy,A,B,vis)){
                q.push({newx,newy});
                dist[newx][newy] = dist[currx][curry] + 1;
                vis[newx][newy] = 1;
            }
        }
    }
    return dist[E-1][F-1];
}
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    return bfs(A,B,C,D,E,F);
}

//Alter
int dx[8] = {-2,2,-2,2,1,1,-1,-1};
int dy[8] = {1,1,-1,-1,-2,2,-2,2};
#define pii pair<int,int>
int Solution::knight(int A, int B, int C, int D, int E, int F) {

    vector<vector<int>> vis(A, vector<int>(B,0));
    queue<pii> q;
    q.push({C - 1, D - 1});
    int steps = 0;

    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            pii p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            if(x == E - 1 && y == F - 1){
                return steps;
            }
            if(vis[x][y]) continue;
            vis[x][y] = 1;

            for(int i = 0; i < 8; i++){
                int xo = x + dx[i], yo = y + dy[i];
                if(xo >= 0 && yo >= 0 && xo < A && yo < B){
                    if(vis[xo][yo] == 0){
                        q.push({xo, yo});
                    }
                }
            }
        }
        steps++;
    }
    return -1;
}
