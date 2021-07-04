//Method - 1
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

//Method - 2
vector<int> Solution::dNums(vector<int> &A, int B) {
    
    vector<int> res;
    
    int n = A.size();
    
    if(B > n){
        return res;
    }
    
    int l = 0, r = 0;
    
    unordered_map<int,int> umap;
    
    while(r < n){
        
        if(r - l + 1 < B){
            umap[A[r]]++;
        }
        else{
            umap[A[r]]++;
            
            res.push_back(umap.size());
            
            umap[A[l]]--;
            
            if(umap[A[l]] == 0){
                umap.erase(A[l]);
            }
            l++;
        }
        r++;
    }
    return res;
}
