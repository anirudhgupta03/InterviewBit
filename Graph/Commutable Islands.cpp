//MST using Kruskal's Algorithm
bool cmp(vector<int> v1, vector<int> v2){
    return v1[2] < v2[2];
}
int findp(int node, vector<int> &parent){
    
    if(parent[node] == -1){
        return node;
    }
    return parent[node] = findp(parent[node],parent);
}
void unionp(int node1, int node2, vector<int> &parent){
    
    parent[node2] = node1;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    
    sort(B.begin(),B.end(),cmp);
    
    vector<int> parent(A+1,-1);
    
    int cost = 0;
    
    for(int i = 0; i < B.size(); i++){
        
        int u = B[i][0], v = B[i][1], w = B[i][2];
        
        int paru = findp(u,parent);
        int parv = findp(v,parent);
        
        if(paru != parv){
            unionp(paru, parv, parent);
            cost += w;
        }
    }
    return cost;
}
