//Similar to number of subarrays with sum k
//Method - 1
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

//Method - 2
int Solution::solve(vector<int> &A, int B) {

    int count = 0;
    unordered_map<int,int> umap;

    int XOR = 0;
    umap[0] = 1;
    
    for(int i = 0; i < A.size(); i++){
        XOR = XOR^A[i];
        if(umap.find(XOR^B) != umap.end()){
            count += umap[XOR^B];
        }
        umap[XOR]++;
    }
    return count;
}
