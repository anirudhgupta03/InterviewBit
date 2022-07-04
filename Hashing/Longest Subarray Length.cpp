//Method - 1
int Solution::solve(vector<int> &A) {

    for(int i = 0; i < A.size(); i++){
        if(A[i] == 0){
            A[i] = -1;
        }
    }
    unordered_map<int,int> umap;

    int sum = 0;
    int maxLen = 0;

    for(int i = 0; i < A.size(); i++){
        sum += A[i];

        if(sum == 1){
            maxLen = i + 1;
        }
        else{
            if(umap.find(sum - 1) != umap.end()){
                maxLen = max(maxLen, i - umap[sum - 1]);
            }
            if(umap.find(sum) == umap.end()){
                umap[sum] = i;
            }
        }
    }
    return maxLen;
}

//Method - 2
int Solution::solve(vector<int> &A) {
    
    unordered_map<int,int> umap;
    umap[0] = -1;
    
    int sum = 0, maxLen = 0;
    
    for(int i = 0; i < A.size(); i++){
        
        sum += (A[i] == 0) ? -1 : 1;
        
        if(umap.find(sum - 1) != umap.end()){
            if(i - umap[sum - 1] > maxLen){
                maxLen = i - umap[sum - 1];
            }
        }
        if(umap.find(sum) == umap.end()){
            umap[sum] = i;
        }
    }
    return maxLen;
}
