int Solution::solve(vector<int> &A) {

    unordered_map<int,int> umap;
    int count = 0;
    
    for(int i = 0; i < A.size(); i++){
        if(umap[A[i]]){
            count++;
            umap[A[i]]--;
        }
        else{
            umap[A[i]]++;
        }
    }
    return count;
}
