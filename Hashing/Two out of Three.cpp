vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    vector<int> res;
    
    unordered_map<int,int> umap1,umap2,umap3;
    
    for(int i = 0; i < A.size(); i++){
        umap1[A[i]]++;
    }
    for(int i = 0; i < B.size(); i++){
        umap2[B[i]]++;
    }
    for(int i = 0; i < C.size(); i++){
        umap3[C[i]]++;
    }
    
    for(int i = 0; i < A.size(); i++){
        if(umap2.find(A[i]) != umap2.end() || umap3.find(A[i]) != umap3.end()){
            if(find(res.begin(),res.end(),A[i]) == res.end()){
                res.push_back(A[i]);
            }
        }
    }
    for(int i = 0; i <  B.size(); i++){
        if(umap3.find(B[i]) != umap3.end()){
            if(find(res.begin(),res.end(),B[i]) == res.end()){
                res.push_back(B[i]);
            }
        }
    }
    sort(res.begin(),res.end());
    return res;
}
