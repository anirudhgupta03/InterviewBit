int findP(int node, vector<int> &par){
    if(par[node] == node){
        return node;
    }
    return par[node] = findP(par[node], par);
}
void unionP(int node1, int node2, vector<int> &par){
    par[node2] = node1;
}
int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    
    vector<int> par(n + 1);
    
    for(int i = 1; i <= n; i++){
        par[i] = i;
    }
    
    for(int i = 1; i < n; i++){
        int pari = findP(i + 1, par);
        if(pari == 1) continue;
        int parj = findP(A[i], par);
        unionP(pari, parj, par);
    }
    
    unordered_set<int> heads;
    for(int i = 0; i < A.size(); i++){
        heads.insert(findP(i + 1, par));
    }
    return heads.size() - 1;
}
