int Solution::solve(vector<int> &A, int B, int C) {
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] == B){        //Set A[i] = 1 if A[i] == B
            A[i] = 1;
        }
        else if(A[i] == C){
            A[i] = -1;        //Set A[i] = -1 if A[i] == C
        }
        else{
            A[i] = 0;
        }
    }
    //Now we'll find number of subarrays with sum 0
    int currsum = 0;
    
    unordered_map<int,int> umap;
    
    int count = 0;
    
    for(int i = 0; i < A.size(); i++){
        
        currsum += A[i];
        
        if(currsum == 0){
            count++;
        }
        
        if(umap.find(currsum) != umap.end()){
            count += umap[currsum];
        }
        
        umap[currsum]++;
    }
    
    return count;
}
