//Bipartite Graph using DFS 
//Graph may have more than one connected component
bool bipartite(int node, vector<int> &color, vector<int> &vis, vector<int> al[]){
    
    vis[node] = 1;
    
    for(int i = 0; i < al[node].size(); i++){
        
        int child = al[node][i];
        
        if(vis[child] == 0){
            
            color[child] = 1 - color[node];
            bool flag = bipartite(child,color,vis,al);
            
            if(flag == false)
            return false;
        }
        else{
            if(color[child] == color[node]){
                return false;
            }
        }
    }
    return true;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    
    vector<int> al[A+1];
    
    for(int i = 0; i < B.size(); i++){
        
        int a = B[i][0], b = B[i][1];
        al[a].push_back(b);
        al[b].push_back(a);
        
    }
    vector<int> vis(A+1,0);
    vector<int> color(A+1);
    
    for(int i = 1; i <= A; i++){
        
        if(vis[i] == 0){
            color[i] = 1;
            if(!bipartite(i,color,vis,al))
            return 0;
        }
    }
    return true;
}
