//Method - 1
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

//Method - 2
void rec(int curr, int parent, vector<int> &vis,  vector<int> al[], vector<int> &A, unordered_set<int> &us, vector<int> &par){
    us.insert(A[curr]);
    vis[curr] = 1;
    par[curr] = parent;

    for(int i = 0; i < al[curr].size(); i++){
        int child = al[curr][i];
        if(vis[child] == 0){
            rec(child, parent, vis, al, A, us, par);
        }
    }
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    int n = A.size();

    vector<int> al[n];
    for(int i = 0; i < C.size(); i++){
        int u = C[i][0], v = C[i][1];
        al[u - 1].push_back(v - 1);
        al[v - 1].push_back(u - 1);
    }

    vector<int> vis(n, 0);
    vector<unordered_set<int>> vec(n);
    vector<int> par(n);

    for(int i = 0; i < n; i++){
        par[i] = i;
    }

    for(int i = 0; i < n; i++){
        if(vis[i] == 0){
            unordered_set<int> us;
            rec(i, i, vis, al, A, us, par);
            vec[i] = us;
        }
    }
    for(int i = 0; i < n; i++){
        if(vec[par[i]].find(B[i]) == vec[par[i]].end()){
            return 0;
        }
        else{
            vec[par[i]].erase(B[i]);
        }
    }
    return 1;
}

//Method - 3
void dfs(int curr, int parent, vector<int> &par, vector<int> &A, unordered_map<int,unordered_map<int,int>> &umap, vector<int> al[]){
    par[curr] = parent;
    umap[parent][A[curr - 1]]++;
    for(auto &child: al[curr]){
        if(par[child] == -1){
            dfs(child, parent,  par, A, umap, al);
        }
    }
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    
    int n = A.size();
    
    vector<int> al[n + 1];
    
    for(auto &x: C){
        al[x[0]].push_back(x[1]);
        al[x[1]].push_back(x[0]);
    }
    
    vector<int> par(n + 1, -1);
    unordered_map<int,unordered_map<int,int>> umap;
    
    for(int i = 1; i <= n; i++){
        if(par[i] == -1){
            dfs(i, i, par, A, umap, al);
        }
    }
    for(int i = 1; i <= n; i++){
        int pari = par[i];
        if(umap[pari][B[i - 1]] == 0){
            return 0;
        }
        else{
            umap[pari][B[i - 1]]--;
        }
    }
    return 1;
}
