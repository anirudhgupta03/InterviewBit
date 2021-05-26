int Solution::solve(vector<int> &A, int B) {
    
    unordered_map<int,int> umap;
    
    for(int i = 0; i < A.size(); i++){
        umap[A[i]]++;
    }
    
    int count = 0;
    
    for(int i = 0; i < A.size(); i++){
        
        if(umap.find(A[i]^B) != umap.end()){
            count++;
        }
    }
    return count/2;
}
