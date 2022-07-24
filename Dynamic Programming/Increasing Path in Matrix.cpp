//Top-Down Approach
//TC - O(m*n)
//SC - O(m*n)
int dx[2] = {0,1};
int dy[2] = {1,0};
int incrPath(int x, int y, vector<vector<int>> &A, vector<vector<int>> &dp){
    
    if(x == A.size() - 1 && y == A[0].size() - 1){
        return 0;
    }

    if(dp[x][y] != -1){
        return dp[x][y];
    }
    
    int mn = INT_MIN;
    
    for(int i = 0; i < 2; i++){
        
        int newx = x + dx[i], newy = y + dy[i];
        
        if(newx < A.size() && newy < A[0].size()){
            if(A[newx][newy] > A[x][y]){
                
                int t = incrPath(newx, newy, A, dp);
                if(t != INT_MIN)
                mn = max(mn, t + 1);
            }
        }
    }
    
    return dp[x][y] = mn;
}
int Solution::solve(vector<vector<int> > &A) {
    
    int m = A.size(), n = A[0].size();
    
    vector<vector<int>> dp(m,vector<int>(n,-1));
    
    int temp = incrPath(0,0,A,dp);
    
    if(temp == INT_MIN){
        return -1;
    }
    return temp + 1;
}

//Alter
int dx[2] = {0,1};
int dy[2] = {1,0};
int dp[1001][1001];
int rec(int x, int y, int n, int m, vector<vector<int>> &A){

    if(x == n - 1 && y == m - 1){
        return 1;
    }
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    int maxLen = -1;
    for(int i = 0; i < 2; i++){
        int xo = x + dx[i], yo = y + dy[i];
        if(xo >= 0 && yo >= 0 && xo < n && yo < m && A[xo][yo] > A[x][y]){
            int temp = rec(xo, yo, n, m, A);
            if(temp != -1) maxLen = max(maxLen,temp + 1);
        }
    }
    return dp[x][y] = maxLen;
}
int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    memset(dp,-1,sizeof(dp));
    return rec(0,0,n,m,A);
}

//Using Priority Queue
#define pipii pair<int,pair<int,int>>
int dx[2] = {1,0};
int dy[2] = {0,1};
struct cmp{
  bool operator()(pipii &p1, pipii &p2){
      return p1.first < p2.first;
  }  
};
int Solution::solve(vector<vector<int> > &A) {
    
    int n = A.size(), m = A[0].size();
    
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    priority_queue<pipii,vector<pipii>,cmp> pq;
    
    pq.push({0,{0,0}});
    
    while(!pq.empty()){
        int dist = pq.top().first, x = pq.top().second.first, y = pq.top().second.second;
        pq.pop();
        
        if(x == n - 1 && y == m - 1){
            return dist + 1;
        }
        if(vis[x][y]) continue;
        vis[x][y] = 1;
        
        for(int i = 0; i < 2; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < n && yo < m && vis[xo][yo] == 0 && A[xo][yo] > A[x][y]){
                pq.push({dist + 1,{xo, yo}});
            }
        }
    }
    return -1;
}
