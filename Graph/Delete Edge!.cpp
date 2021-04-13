#define ll long long
int dfs(int node, vector<int> &vis, vector<ll> &subw, vector<int> al[]){
    
    vis[node] = 1;
    
    for(int i = 0; i < al[node].size(); i++){
        
        int child = al[node][i];
        
        if(vis[child] == 0){
            subw[node] += dfs(child,vis,subw,al);
        }
    }
    return subw[node];
}
int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    
    int n = A.size();
    
    vector<ll> subw(n+1);
    
    for(int i = 0; i < n; i++){
        subw[i+1] = A[i];
    }
    
    vector<int> al[n+1];
    vector<int> vis(n+1,0);
    
    for(int i = 0; i < B.size(); i++){
        int a = B[i][0], b = B[i][1];
        al[a].push_back(b);
        al[b].push_back(a);
    }
    
    dfs(1,vis,subw,al);
    
    ll total = 0;
  
    for(int i = 1; i <= n; i++){
        total += A[i-1];
    }
    
    ll ans = INT_MIN;
    
    for(int i = 1; i <= n; i++){
        ans = max(ans,(subw[i]*(total-subw[i]))%1000000007);
    }
    return ans;
}
