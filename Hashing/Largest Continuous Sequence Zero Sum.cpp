vector<int> Solution::lszero(vector<int> &A) {
    
    int n = A.size();
    
    vector<int> temp(n+1);
    
    temp[0] = 0;
    
    for(int i = 1; i < n + 1; i++){
        temp[i] = temp[i-1] + A[i-1];
    }
    
    unordered_map<int,int> umap;
    
    int start = -1, end = -1;
    
    int diff = 0;
    
    for(int i = 0; i < n + 1; i++){
        
        if(umap.find(temp[i]) == umap.end()){
            umap[temp[i]] = i;
        }
        else{
            if(i - umap[temp[i]] > diff){
                diff = i - umap[temp[i]];
                start = umap[temp[i]];
                end = i-1;
            }
        }
    }
  
    vector<int> res;
    
    if(start == -1){
        return res;
    }
    for(int j = start; j <= end; j++){
        res.push_back(A[j]);
    }
    return res;
}
