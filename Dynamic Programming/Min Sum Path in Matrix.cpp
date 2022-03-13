//Top-Down Approach
//TC - O(n*m)
//SC - O(n*m)
int dx[2] = {0,1};
int dy[2] = {1,0};
int solve(int x, int y, vector<vector<int>> &A, vector<vector<int>> &dp){
    
    if(x == A.size() - 1 && y == A[0].size() - 1){
        return A[x][y];
    }
    
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    
    int temp = INT_MAX;
    
    for(int i = 0; i < 2; i++){
        
        int xo = x + dx[i], yo = y + dy[i];
        
        if(xo < A.size() && yo < A[0].size()){
            
            int t = solve(xo,yo,A,dp);
            
            if(t != INT_MAX){
                temp = min(temp,t + A[x][y]);
            }
        }
    }
    return dp[x][y] = temp;
}
int Solution::minPathSum(vector<vector<int> > &A) {
    
    int n = A.size(), m = A[0].size();
    
    vector<vector<int>> dp(n,vector<int>(m,-1));
    
    return solve(0,0,A,dp);
}

//Using Dijkstra's Algo
#define pipii pair<int,pair<int,int>>
int dx[2] = {1,0};
int dy[2] = {0,1};
int Solution::minPathSum(vector<vector<int> > &A) {

    int m = A.size(), n = A[0].size();
    priority_queue<pipii,vector<pipii>,greater<pipii>> pq;
    pq.push({A[0][0],{0,0}});

    vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
    dist[0][0] = A[0][0];
    vector<vector<int>> vis(m,vector<int>(n,0));

    while(!pq.empty()){
        int d = pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
        pq.pop();
        if(vis[x][y]){
            continue;
        }
        vis[x][y] = 1;
        for(int i = 0; i < 2; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo < m && yo < n && vis[xo][yo] == 0){
                if(d + A[xo][yo] < dist[xo][yo]){
                    dist[xo][yo] = d + A[xo][yo];
                    pq.push({dist[xo][yo],{xo,yo}});
                }
            }
        }
    }
    return dist[m-1][n-1];
}
