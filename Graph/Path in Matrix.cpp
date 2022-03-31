int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int Solution::checkPath(vector<vector<int> > &A) {

    int sx,sy,destx,desty;
    int n = A.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(A[i][j] == 1){
                sx = i;
                sy = j;
            }
            if(A[i][j] == 2){
                destx = i;
                desty = j;
            }
        }
    }

    queue<pair<int,int>> q;
    q.push({sx, sy});
    vector<vector<int>> vis(n, vector<int>(n, 0));

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == destx && y == desty){
            return 1;
        }
        if(vis[x][y]) continue;
        vis[x][y] = 1;

        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < n && yo < n){
                if(vis[xo][yo] == 0 && A[xo][yo] != 0){
                    q.push({xo,yo});
                }
            }
        }
    }
    return 0;
}
