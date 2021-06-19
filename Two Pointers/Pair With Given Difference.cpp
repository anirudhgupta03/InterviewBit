//Method - 1
//Time Complexity - O(NlogN)
//Space Complexity - O(1)
int Solution::solve(vector<int> &A, int B) {
    
    sort(A.begin(),A.end());
    
    int l = 0, r = 1;
    
    while(r < A.size()){
        
        if(A[r] - A[l] == B && l != r){
            return 1;
        }
        else if(A[r] - A[l] > B){
            l++;
        }
        else{
            r++;
        }
    }
    
    return 0;
}

//Method - 2
//Time Complexity - O(N)
//Space Complexity - O(N)
int Solution::solve(vector<int> &A, int B) {
    
    unordered_map<int,int> umap;
    
    for(int i = 0; i < A.size(); i++){
        
        if(umap.find(A[i]-B) != umap.end() || umap.find(A[i]+B) != umap.end()){
            return 1;
        }
        umap[A[i]]++;
    }
    
    return 0;
}
