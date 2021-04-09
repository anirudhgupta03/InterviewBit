bool dfs(int node, int parent, vector<int> &vis, vector<int> al[]){
    
    vis[node] = 1;
    
    for(int i = 0; i < al[node].size(); i++){
        
        int child = al[node][i];
        
        if(child == parent){
            continue;
        }
        
        if(vis[child] == 1){
            return true;
        }
        else{
            bool flag = dfs(child, node, vis, al);
            
            if(flag){
                return true;
            }
        }
    }
    return false;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    
    vector<int> al[A+1];
    
    for(int i = 0; i < B.size(); i++){
        int a = B[i][0];
        int b = B[i][1];
        
        al[a].push_back(b);
        al[b].push_back(a);
    }
    
    vector<int> vis(A+1,0);
    
    for(int i = 1; i <= A; i++){
        
        if(vis[i] == 0){
            if(dfs(i, -1, vis, al)){
                return 1;
            }
        }
    }
    return 0;
}
