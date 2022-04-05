//Method - 1
#define pii pair<int,int>
struct cmp{
    bool operator()(pii &p1, pii &p2){
        return p1.second > p2.second;
    }
};
int dijkstra(int A, vector<pair<int,int>> al[], int start, int end){

    priority_queue<pii, vector<pii>, cmp> pq;
    pq.push({start, 0});

    vector<int> vis(A + 1, 0);
    vector<int> cost(A + 1,INT_MAX);

    cost[start] = 0;

    while(!pq.empty()){
        pii p = pq.top();
        pq.pop();

        int curr = p.first, currw = p.second;
        if(curr == end){
            return currw;
        }

        if(vis[curr]) continue;
        vis[curr] = 1;

        for(int i = 0; i < al[curr].size(); i++){
            int child = al[curr][i].first;
            if(vis[child] == 0 && currw + al[curr][i].second < cost[child]){
                cost[child] = currw + al[curr][i].second;
                pq.push({child, cost[child]});
            }
        }
    }
    return -1;
}
int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {

    vector<pair<int,int>> al[A + 1];

    for(int i = 0; i < B.size(); i++){
        int u = B[i][0], v = B[i][1], w = B[i][2];
        al[u].push_back({v, w});
        al[v].push_back({u, w});
    }

    int minCost = INT_MAX;

    minCost = min(minCost, dijkstra(A, al, C, D));

    for(int i = 0; i < E.size(); i++){
        int u = E[i][0], v = E[i][1], w = E[i][2];
        al[u].push_back({v, w});
        al[v].push_back({u, w});
        int temp = dijkstra(A, al, C, D);
        if(temp != -1)
        minCost = min(minCost, temp);
        al[u].pop_back();
        al[v].pop_back();
    }
    return minCost == INT_MAX ? -1 : minCost;
}

//Method - 2
/*
Use dijkstra 2 times. Once with C as origin and another
with D as origin. Now for every node, you have the length of the shortest path from
C and from D. Now you can just iterate over each road and check if this road
helps you decreasing the existing distance between C and D.
whenever you get a better answer, you can update your answer to this
value and keep iterating on the auxillary roads.
*/
#define pii pair<int,int>
struct cmp{
    bool operator()(pii &p1, pii &p2){
        return p1.second > p2.second;
    }
};
vector<int> dijkstra(int A, vector<pair<int,int>> al[], int start, int end){

    priority_queue<pii, vector<pii>, cmp> pq;
    pq.push({start, 0});

    vector<int> vis(A + 1, 0);
    vector<int> cost(A + 1,INT_MAX);

    cost[start] = 0;

    while(!pq.empty()){
        pii p = pq.top();
        pq.pop();

        int curr = p.first, currw = p.second;
        if(curr == end){
            break;
        }

        if(vis[curr]) continue;
        vis[curr] = 1;

        for(int i = 0; i < al[curr].size(); i++){
            int child = al[curr][i].first;
            if(vis[child] == 0 && currw + al[curr][i].second < cost[child]){
                cost[child] = currw + al[curr][i].second;
                pq.push({child, cost[child]});
            }
        }
    }
    return cost;
}
int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {

    vector<pair<int,int>> al[A + 1];

    for(int i = 0; i < B.size(); i++){
        int u = B[i][0], v = B[i][1], w = B[i][2];
        al[u].push_back({v, w});
        al[v].push_back({u, w});
    }

    int minCost = INT_MAX;

    vector<int> ste = dijkstra(A, al, C, D);
    vector<int> ets = dijkstra(A, al, D, C);
    minCost = ste[D];

    for(int i = 0; i < E.size(); i++){
        int u = E[i][0], v = E[i][1], w = E[i][2];
        if(ste[u] != INT_MAX && ets[v] != INT_MAX){
            minCost = min(minCost, ste[u] + w + ets[v]);
        }
        if(ste[v] != INT_MAX && ets[u] != INT_MAX){
            minCost = min(minCost, ste[v] + w + ets[u]);
        }
    }
    return minCost == INT_MAX ? -1 : minCost;
}
