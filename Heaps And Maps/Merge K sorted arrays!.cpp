//Ref: https://www.youtube.com/watch?v=VV19JFP6-0c&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=133
#define pii pair<int,int>
vector<int> Solution::solve(vector<vector<int> > &A) {
    
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    
    int k = A.size(), n = A[0].size();
    
    for(int i = 0; i < k; i++){
        pq.push({A[i][0],i});
    }
    
    vector<int> ans;
    
    vector<int> idx(k,0);
    
    while(!pq.empty()){
        
        pair<int,int> p = pq.top();
        pq.pop();
        
        ans.push_back(p.first);
        
        if(idx[p.second] + 1 < n){
            pq.push({A[p.second][idx[p.second]+1],p.second});
            idx[p.second] += 1;
        }
    }
    
    return ans;
}
