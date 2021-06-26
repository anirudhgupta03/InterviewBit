//Method - 1
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

//Method - 2
int Solution::solve(vector<int> &A, int B) {
    
    unordered_map<int,int> umap;
    
    int count = 0;
    
    for(int i = 0; i < A.size(); i++){
        
        if(umap.find(A[i]^B) != umap.end()){
            count++;
        }
        umap[A[i]]++;
    }
    
    return count;
}
