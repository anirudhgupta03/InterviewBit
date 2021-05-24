int Solution::diffPossible(const vector<int> &A, int B) {
    
    vector<int> temp = A;
    
    sort(temp.begin(),temp.end());
    
    unordered_map<int,int> umap;
    
    for(int i = 0; i < temp.size(); i++){
        
        if(umap.find(temp[i]-B) != umap.end()){
            return 1;
        }
        else{
            umap[temp[i]] = 1;
        }
    }
    return 0;
}
