//https://www.youtube.com/watch?v=iYUil_m64Xg
void dfs(int node, vector<int> al[], vector<int> &vis){

    vis[node] = 1;

    for(int i = 0; i < al[node].size(); i++){
        int child = al[node][i];
        if(vis[child] == 0){
            dfs(child, al, vis);
        }
    }
}
int Solution::motherVertex(int A, vector<vector<int> > &B) {

    vector<int> al[A + 1];

    for(int i = 0; i < B.size(); i++){
        int u = B[i][0], v = B[i][1];
        al[u].push_back(v);
    }

    vector<int> vis(A + 1,0);
    int ele;
    for(int i = 1;  i <= A; i++){
        if(!vis[i]){
            ele = i;
            dfs(i, al, vis);
        }
    }

    for(int i = 1; i <= A; i++){
        vis[i] = 0;
    }
    dfs(ele, al, vis);

    for(int i = 1; i <= A; i++){
        if(vis[i] == 0){
            return 0;
        }
    }
    return 1;
}
