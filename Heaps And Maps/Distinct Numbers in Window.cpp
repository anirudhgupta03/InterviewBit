vector<int> Solution::dNums(vector<int> &A, int B) {
    
    vector<int> res;
    
    int n = A.size();
    
    if(B > n){
        return res;
    }
    
    unordered_map<int,int> umap;
    
    for(int i = 0; i < B; i++){
        umap[A[i]]++;
    }
    
    res.push_back(umap.size());
    
    int count = umap.size();
    
    for(int i = B; i < n; i++){
        
        umap[A[i-B]]--;
        
        if(umap[A[i-B]] == 0){
            count--;
        }
        
        umap[A[i]]++;
        
        if(umap[A[i]] == 1){
            count++;
        }
        
        res.push_back(count);
    }
    
    return res;
}
