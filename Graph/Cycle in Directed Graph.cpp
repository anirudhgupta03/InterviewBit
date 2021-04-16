bool dfs(int v, vector<int> &color, vector<int> al[]){
    
    color[v] = 1;
    for(int i = 0; i < al[v].size(); i++){
        
        int u = al[v][i];
        
        if(color[u] == 0){
            if(dfs(u,color,al)){
                return true;
            }
        }
        else if(color[u] == 1){
            return true;
        }
    }
    color[v] = 2;
    return false;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    
    vector<int> al[A+1];
    
    for(int i = 0; i < B.size(); i++){
        int u = B[i][0], v = B[i][1];
        al[u].push_back(v);
    }
    
    vector<int> color(A+1,0);
    
    for(int i = 1; i <= A; i++){
        
        if(color[i] == 0){
            
            if(dfs(i,color,al))
            return true;
        }
    }
    return false;
}
