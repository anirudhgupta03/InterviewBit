//Ref: https://www.youtube.com/watch?v=19tY6Y90TP0
int bfs(vector<int> &game){
    
    vector<int> vis(100,0);
    vector<int> dist(100,-1);
    vis[0] = 1;
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    
    while(!q.empty()){
        
        int curr = q.front();
        q.pop();
        for(int j = curr + 1; (j <= curr + 6) && j < 100; j++){
            
            if(vis[game[j]] == 0){
                vis[game[j]] = 1;
                q.push(game[j]);
                dist[game[j]] = dist[curr] + 1;
            }
        }
    }
    return dist[99];
}
int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    
    vector<int> game(100);
    
    for(int i = 0; i < 100; i++){
        game[i] = i;
    }
    for(int i = 0; i < A.size(); i++){
        game[A[i][0] - 1] = A[i][1] - 1;
    }
    
    for(int i = 0; i < B.size(); i++){
        game[B[i][0] - 1] = B[i][1] - 1;
    }
    
    return bfs(game);
}
