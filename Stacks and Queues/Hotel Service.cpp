//Multi Source BFS
#define pii pair<int,int>
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
vector<int> Solution::nearestHotel(vector<vector<int> > &A, vector<vector<int> > &B) {

    queue<pii> q;

    int n = A.size(), m = A[0].size();

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j]){
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while(!q.empty()){
        pii p = q.front();
        q.pop();
        int currx = p.first, curry = p.second;
        for(int i = 0; i < 4; i++){
            int newx = currx + dx[i], newy = curry + dy[i];
            if(newx >= 0 && newx < n && newy >=0 && newy < m){
                if(dist[currx][curry] + 1 < dist[newx][newy]){
                    dist[newx][newy] = dist[currx][curry] + 1;
                    q.push({newx, newy});
                }
            }
        }
    }
    vector<int> res;
    for(int i = 0; i < B.size(); i++){
        res.push_back(dist[B[i][0] - 1][B[i][1] - 1]);
    }
    return res;
}
