//Similar to number of subarrays with sum k
int Solution::solve(vector<int> &A, int B) {
    
    int currxor = 0;
    
    unordered_map<int,int> umap;
    
    int count = 0;
    
    for(int i = 0; i < A.size(); i++){
        
        currxor ^= A[i];
        
        if(currxor == B){
            count++;
        }
        
        if(umap.find(currxor^B) != umap.end()){
            count += umap[currxor^B];
        }
        
        umap[currxor]++;
    }
    return count;
}
