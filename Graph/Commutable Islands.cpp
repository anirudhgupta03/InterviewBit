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

//MST using Prim's Algorithm
#define pii pair<int,int>
struct cmp{
    bool operator()(pii &p1, pii &p2){
        return p1.second > p2.second;
    }
};
int Solution::solve(int A, vector<vector<int> > &B) {

    vector<pii> al[A + 1];

    for(int i = 0; i < B.size(); i++){
        al[B[i][0]].push_back({B[i][1], B[i][2]});
        al[B[i][1]].push_back({B[i][0], B[i][2]});
    }
    vector<int> vis(A + 1,0);
    
    priority_queue<pii,vector<pii>,cmp> pq;
    pq.push({1,0});
    
    int minCost = 0;
    
    while(!pq.empty()){
        int curr = pq.top().first, cost = pq.top().second;
        pq.pop();
    
        if(vis[curr]) continue;
        vis[curr] = 1;
        minCost += cost;
        
        for(int i = 0; i < al[curr].size(); i++){
            int child = al[curr][i].first;
            if(vis[child] == 0){
                pq.push({child, al[curr][i].second});
            }
        }
    }
    return minCost;
}
