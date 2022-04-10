//Method - 1
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i = 0; i < B.size(); i++){
        
        pq.push(A[0] + B[i]);
        
        if(pq.size() > C){
            pq.pop();
        }
    }
    
    for(int i = 1; i < A.size(); i++){
        for(int j = 0; j < B.size(); j++){
            
            int sum = A[i] + B[j];
            
            if(sum > pq.top()){
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
    sort(res.begin(),res.end(),greater<int>());
    return res;
}

//Method - 2
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < B.size(); j++){
            
            int sum = A[i] + B[j];
            
            if(pq.size() < C){
                pq.push(sum);
            }
            else{
                
                if(pq.top() < sum){
                    pq.pop();
                    pq.push(sum);
                }
                else{
                    break;
                }
            }
        }
    }
    
    vector<int> res;
    while(pq.size()){
        res.push_back(pq.top());
        pq.pop();
    }
    reverse(res.begin(),res.end());
    return  res;
}

//Method - 3
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {

    priority_queue<int, vector<int>, greater<int>> pq;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int n = A.size();

    for(int i = n - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            if(i == n - 1){
                if(pq.size() < C){
                    pq.push(A[i] + B[j]);
                }
                else{
                    break;
                }
            }
            else{
                int sum = A[i] + B[j];
                if(sum > pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
                else{
                    break;
                }
            }
        }
    }
    vector<int> res;
    while(!pq.empty()){
        res.push_back(pq.top());
        pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

//Method - 4
#define pipii pair<int,pair<int,int>>
struct cmp{
    bool operator()(pipii &p1, pipii &p2){
        return p1.first < p2.first;
    }
};
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int n = A.size();

    priority_queue<pipii, vector<pipii>, cmp> pq;
    pq.push({A[n - 1] + B[n - 1],{n - 1, n - 1}});

    set<pair<int,int>> vis;

    vector<int> res;
    while(!pq.empty() && C){
        pipii p = pq.top();
        pq.pop();

        int curr = p.first, i = p.second.first, j = p.second.second;

        if(vis.find({i,j}) != vis.end()) continue;
        vis.insert({i,j});

        C--;
        res.push_back(curr);

        if(i - 1 >= 0){
            pq.push({A[i - 1] + B[j],{i - 1,j}});
        }
        if(j - 1 >= 0){
            pq.push({A[i] + B[j - 1], {i, j - 1}});
        }
    }
    return res;
}
