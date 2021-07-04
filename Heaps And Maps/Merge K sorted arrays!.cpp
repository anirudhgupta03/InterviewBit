//Ref: https://www.youtube.com/watch?v=VV19JFP6-0c&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=133
//Method - 1
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

//Method - 2
#define pivi pair<int,pair<vector<int>,int>> 
vector<int> Solution::solve(vector<vector<int> > &A) {
    
    priority_queue<pivi,vector<pivi>,greater<pivi>> pq;
    
    for(int i = 0; i < A.size(); i++){
        pq.push({A[i][0],{A[i],0}});
    }
    
    vector<int> res;
    
    while(!pq.empty()){
        
        res.push_back(pq.top().first);
        
        int ind = pq.top().second.second;
        
        vector<int> temp = pq.top().second.first;
        
        pq.pop();
        
        if(ind < temp.size() - 1){
            int val = temp[ind + 1];
            pq.push({val,{temp,ind+1}});
        }
    }
    return res;
}
