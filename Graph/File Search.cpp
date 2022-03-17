void dfs(int curr, vector<int> &vis, vector<int> al[]){

    vis[curr] = 1;
    for(int i = 0; i < al[curr].size(); i++){
        int child = al[curr][i];
        if(vis[child] == 0){
            dfs(child, vis, al);
        }
    }
}
int Solution::breakRecords(int A, vector<vector<int> > &B) {

    vector<int> al[A + 1];
    for(int i = 0; i < B.size(); i++){
        al[B[i][0]].push_back(B[i][1]);
        al[B[i][1]].push_back(B[i][0]);
    }

    int count = 0;
    vector<int> vis(A + 1, 0);
    for(int i = 1; i <= A; i++){
        if(vis[i] == 0){
            dfs(i, vis, al);
            count++;
        }
    }
    return count;
}
