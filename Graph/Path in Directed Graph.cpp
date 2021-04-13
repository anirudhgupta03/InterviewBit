int bfs(int A, vector<int> al[]){
   
    vector<int> vis(A+1,0);
    
    queue<int> q;
    vis[1] = 1;
    q.push(1);
    
    while(!q.empty()){
        
        int curr = q.front();
        q.pop();
        
        for(int i = 0; i < al[curr].size(); i++){
            
            int child = al[curr][i];
            
            if(vis[child] == 0){
                q.push(child);
                vis[child] = 1;
            }
        }
    }
    
    return vis[A];
}
int Solution::solve(int A, vector<vector<int> > &B) {
    
    vector<int> al[A+1];
    
    for(int i = 0; i < B.size(); i++){
        
        int a = B[i][0], b = B[i][1];
        al[a].push_back(b);
    }
    
    return bfs(A,al);
}
