//Dijkstra Algo on 2D Grid
#define pii pair<int,pair<int,int>>

char dir[4] = {'U','D','L','R'};
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool isValid(int x, int y, int A, int B, vector<vector<int>> &vis){
    
    if(x < 0 || x >= A || y < 0 || y >= B){
        return false;
    }
    
    if(vis[x][y] == true){
        return false;
    }
    
    return true;
}
int dijkstra(int A, int B, vector<string> &C){
    
    vector<vector<int>> dist(A,vector<int>(B,INT_MAX));
    
    dist[0][0] = 0;
    
    vector<vector<int>> vis(A,vector<int>(B,0));
    
    priority_queue<pii, vector<pii> ,greater<pii>> pq;
    
    pq.push({0,{0,0}});
    
    while(!pq.empty()){
        
        int currx = pq.top().second.first, curry = pq.top().second.second, currc = pq.top().first;
        pq.pop();
        
        vis[currx][curry] = 1;
        
        for(int i = 0; i < 4; i++){
            
            int newx = currx + dx[i], newy = curry + dy[i];
            
            int add=(C[currx][curry]==dir[i])?0:1;
            
            if(isValid(newx,newy,A,B,vis) && currc + add < dist[newx][newy]){
               
               dist[newx][newy] = currc + add;
               pq.push({dist[newx][newy],{newx,newy}});
            }
        }
    }
    return dist[A-1][B-1];
}
int Solution::solve(int A, int B, vector<string> &C) {
    
    return dijkstra(A,B,C);
}

//Alter
#define ppiii pair<pair<int,int>,int>
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
char dc[4] = {'U','D','L','R'};
struct cmp{
    bool operator()(ppiii &p1, ppiii &p2){
        return p1.second > p2.second;
    }
};
int Solution::solve(int A, int B, vector<string> &C) {

    vector<vector<int>> vis(A, vector<int>(B,0));

    priority_queue<ppiii,vector<ppiii>,cmp> pq;
    pq.push({{0,0},0});

    while(!pq.empty()){

        int x = pq.top().first.first, y = pq.top().first.second;
        int cost = pq.top().second;
        pq.pop();

        if(x == A - 1 && y == B - 1){
            return cost;
        }

        if(vis[x][y]) continue;
        vis[x][y] = 1;
        
        for(int i = 0; i < 4; i++){
            int xo = x + dx[i], yo = y + dy[i];
            if(xo >= 0 && yo >= 0 && xo < A && yo < B){
                if(vis[xo][yo] == 0){
                    if(dc[i] == C[x][y]){
                        pq.push({{xo, yo},cost});
                    }
                    else{
                        pq.push({{xo,yo},cost + 1});
                    }
                }
            }
        }
    }
}
