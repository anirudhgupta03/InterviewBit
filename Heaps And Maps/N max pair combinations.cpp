//Method - 1
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    
    int n = A.size();
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
            int sum = A[i] + B[j];
            
            if(i == 0) pq.push(sum);
            else if(pq.top() < sum){
                pq.pop();
                pq.push(sum);
            }
            else{
                break;
            }
        }
    }
    vector<int> res;
    while(pq.size()){
        res.push_back(pq.top());
        pq.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}

//Method - 2
//Ref: https://www.youtube.com/watch?v=btjG9eLNYcg
#define pipii pair<int,pair<int,int>>
struct cmp{
    bool operator()(pipii &p1, pipii &p2){
        return p1.first < p2.first;
    }
};
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {

    priority_queue<pipii, vector<pipii>, cmp> pq;
    set<pair<int,int>> vis;

    vector<int> ans;
    int n = A.size();

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    pq.push({A[n - 1] + B[n - 1], {n - 1, n - 1}});

    while(ans.size() != n){
        pipii p = pq.top();
        int val = p.first;
        int x = p.second.first, y = p.second.second;
        
        pq.pop();
        
        if(vis.find({x,y}) != vis.end()) continue;
        vis.insert({x, y});

        ans.push_back(val);

        if(x - 1 >= 0){
            if(vis.find({x - 1, y}) == vis.end()){
                pq.push({A[x - 1] + B[y], {x - 1, y}});
            }
        }
        if(y - 1 >= 0){
            if(vis.find({x, y - 1}) == vis.end()){
                pq.push({A[x] + B[y - 1], {x, y - 1}});
            }
        }
    }
    return ans;
}
