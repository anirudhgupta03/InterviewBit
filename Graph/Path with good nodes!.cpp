//Method - 1
void dfs(int node, int par, vector<int> &val, int &count, vector<int> al[], vector<int> &A, vector<int> &vis, int C){
    
    vis[node] = 1;
    
    for(int i = 0; i < al[node].size(); i++){
        
        int child = al[node][i];
        
        if(vis[child] == 0){
            val[child] = val[node] + A[child-1];                //Storing the total value from src till the child 
            dfs(child,node,val,count,al,A,vis,C);
        }
    }
    
    if(al[node].size() == 1 && A[node-1] + val[par] <= C){      //Checking for leaf node
            count++;
    }
}
int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    
    int n = A.size();
    
    vector<int> al[n+1];
    
    for(int i = 0; i < B.size(); i++){
        
        int u = B[i][0], v = B[i][1];
        al[u].push_back(v);
        al[v].push_back(u);
        
    }
    
    vector<int> val(n+1);
    vector<int> vis(n+1,0);
    val[1] = A[0];
    int count = 0;
    
    dfs(1,-1,val,count,al,A,vis,C);
    
    return count;
}

//Method - 2
void dfs(int node, int &tcount, int count, vector<int> &A, vector<int> al[], int C, vector<int> &vis){
    
    vis[node] = 1;
    if(al[node].size() == 1){
        if(count <= C){
            tcount++;
        }
        return;
    }
    for(int i = 0; i < al[node].size(); i++){

        int child = al[node][i];

        if(vis[child] == 0 && A[child-1] == 1){
            dfs(child,tcount,count+1,A,al,C,vis);
        }
        else if(vis[child] == 0){
            dfs(child,tcount,count,A,al,C,vis);
        }
    }
    vis[node] = 0;      //Not Required
}
int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {

    int n = A.size();

    vector<int> al[n+1];

    for(int i = 0; i < B.size(); i++){
        int a = B[i][0], b = B[i][1];
        al[a].push_back(b);
        al[b].push_back(a);
    }

    int tcount = 0, count;
    
    vector<int> vis(n+1,0);
    
    if(A[0] == 1) count++;
    
    dfs(1,tcount,count,A,al,C,vis);

    return tcount;
}

//Method - 3
void rec(int node, int count, vector<int> al[], int &paths, vector<int> &A, int C, vector<int> &vis){
    vis[node] = 1;
    if(al[node].size() == 1){
        if(count + A[node - 1] <= C){
            paths++;
        }
        return;
    }
    for(int i = 0; i < al[node].size(); i++){
        int child = al[node][i];
        if(vis[child] == 0)
        rec(child, count + A[node - 1], al, paths, A, C, vis);
    }
}
int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int n = A.size();
    vector<int> al[n + 1];
    for(int i = 0; i < n - 1; i++){
        int u = B[i][0], v = B[i][1];
        al[u].push_back(v);
        al[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);
    int paths = 0;
    rec(1, 0, al, paths, A, C, vis);
    return paths;
}

//Method - 4
void dfs(int node, int par, int C, int &count, vector<int> al[], vector<int> &A){
    bool flag = false;
    for(auto &child: al[node]){
        if(child == par) continue;
        flag = true;
        dfs(child, node, C - A[child - 1], count, al, A);
    }
    if(flag == false){
        if(C >= 0) count++;
    }
}
int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int n = A.size();
    int count = 0;
    vector<int> al[n + 1];
    for(auto &x: B){
        al[x[0]].push_back(x[1]);
        al[x[1]].push_back(x[0]);
    }
    dfs(1, -1, C - A[0], count, al, A);
    return count;
}
