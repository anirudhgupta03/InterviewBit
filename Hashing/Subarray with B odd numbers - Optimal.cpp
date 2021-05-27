//TC - O(N)
//SC - O(1)
int Solution::solve(vector<int> &A, int B) {
    
        int currsum = 0;
        
        unordered_map<int,int> umap;
        
        int count = 0;
  
        for(int i = 0; i < A.size(); i++){
            
            if(A[i] % 2 != 0)
            currsum += 1;
            
            if(currsum == B){
                count++;
            }
            
            if(umap.find(currsum-B) != umap.end()){
                count += umap[currsum-B];
            }
            
            umap[currsum]++;
        }
        
        return count;
    
}
