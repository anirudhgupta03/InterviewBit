void dfs(int node, vector<int> &dist, int n, vector<int> al[], vector<int> &vis){
    
    vis[node] = 1;
    
    
    for(int i = 0; i < al[node].size(); i++){
        
        int child = al[node][i];
        
        if(vis[child] == 0){
            dist[child] = dist[node] + 1;
            dfs(child, dist, n, al, vis);
        }
    }
}
int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    
    if(n == 1) return 0;
    
    vector<int> al[n];
    
    int a,b;
    
    for(int i = 0; i < n; i++){
        
        a = i, b = A[i];
        
        if(b == -1){
            continue;
        }
        al[a].push_back(b);
        al[b].push_back(a);
    }
    
    vector<int> dist(n,0);
    vector<int> vis(n,0);
    
    dfs(0, dist, n, al,vis);
    
    int temp, tempd = INT_MIN;
    
    for(int i = 1; i < n; i++){
        
        if(dist[i] > tempd){
            tempd = dist[i];
            temp = i;
        }
    }
    
    for(int i = 0; i < n; i++){
        dist[i] = 0;
        vis[i] = 0;
    }
    
    dfs(temp, dist, n, al, vis);
    
    tempd = INT_MIN;
    
    for(int i = 0; i < n; i++){
        tempd = max(tempd, dist[i]);
    }
    
    return tempd;
}
