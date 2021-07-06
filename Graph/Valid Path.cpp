//Ref: https://www.youtube.com/watch?v=In6MrAYjeZw
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
