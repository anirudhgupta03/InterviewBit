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
