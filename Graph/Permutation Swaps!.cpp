bool isReachable(int src, int dest, unordered_map<int,vector<int>> &umap, unordered_map<int,int> &vis){
    
    if(src == dest){
        return true;
    }
    
    vis[src] = 1;
    
    for(int i = 0; i < umap[src].size(); i++){
        int child = umap[src][i];
        
        if(vis[child] == 0){
            if(isReachable(child,dest,umap,vis)){
                return true;
            }
        }
    }
    return false;
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {

    unordered_map<int,vector<int>> umap;
    
    for(int i = 0; i < C.size(); i++){
        int ind1 = C[i][0], ind2 = C[i][1];
        umap[A[ind1-1]].push_back(A[ind2-1]);
        umap[A[ind2-1]].push_back(A[ind1-1]);
    }
    
    for(int i = 0; i < A.size(); i++){
        unordered_map<int,int> vis;
        if(A[i] != B[i]){
            if(!isReachable(A[i],B[i],umap,vis)){
                return false;
            }
        }
    }
    return true;
}
