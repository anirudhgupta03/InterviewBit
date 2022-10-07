//Method - 1
int rec(int node, vector<int> al[], vector<int> &subSize, vector<int> &vis){

    vis[node] = 1;
    for(int i = 0; i < al[node].size(); i++){
        int child = al[node][i];
        if(vis[child]) continue;
        subSize[node] += rec(child, al, subSize, vis);
    }
    return subSize[node];
}
int Solution::solve(int A, vector<vector<int> > &B) {

    vector<int> al[A + 1];

    for(int i = 0; i < B.size(); i++){
        int u = B[i][0], v = B[i][1];
        al[u].push_back(v);
        al[v].push_back(u);
    }

    vector<int> subSize(A + 1, 1);
    vector<int> vis(A + 1, 0);
    
    rec(1, al, subSize, vis);

    int count = 0;
    for(int i = 2; i <= A; i++){
        if(subSize[i] % 2 == 0){
            count++;
        }
    }
    return count;
}

//Method - 2
//Without using visited array
int rec(int node, int par, vector<int> &subSize, vector<int> al[]){
    
    int count = 1;
    for(auto &x: al[node]){
        if(x == par) continue;
        count += rec(x, node, subSize, al);
    }
    return subSize[node] = count;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    
    vector<int> al[A + 1];
    
    for(auto &x: B){
        al[x[0]].push_back(x[1]);
        al[x[1]].push_back(x[0]);
    }
    
    vector<int> subSize(A + 1,0);
    
    rec(1, -1, subSize, al);
    
    int count = 0;
    for(int i = 2; i <= A; i++){
        if(subSize[i] % 2 == 0){
            count++;
        }
    }
    return count;
}

//Method - 3
int findSubSize(int node, vector<int> al[], vector<int> &subSize){
    subSize[node] = 1;
    for(int i = 0; i < al[node].size(); i++){
        int child = al[node][i];
        subSize[node] += findSubSize(child, al, subSize);
    }
    return subSize[node];
}
int Solution::solve(int A, vector<vector<int> > &B) {
    
    vector<int> al[A + 1];
    
    for(auto &x: B){
        al[x[0]].push_back(x[1]);
    }
    
    vector<int> subSize(A + 1, 0);
    for(int i = 1; i <= A; i++){
        if(subSize[i] == 0){
            findSubSize(i, al, subSize);
        }
    }
    int count = 0;
    for(int i = 1; i <= A; i++){
        if(subSize[i] % 2 == 0){
            count++;
        }
    }
    return count - 1;
}
