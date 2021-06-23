//Recurive Approach
int Solution::isScramble(const string A, const string B) {
    
    if(A.size() != B.size()){
        return false;
    }
    int n = A.size();
    
    if(n == 0){
        return 1;
    }
    if(A == B){
        return true;
    }
    if(n < 1){
        return false;
    }
    
    for(int i = 1; i <= n - 1; i++){
        
        if(isScramble(A.substr(0,i),B.substr(n-i,i)) && isScramble(A.substr(i,n-i), B.substr(0,n-i))){
            return true;
        }
        
        if(isScramble(A.substr(0,i),B.substr(0,i)) && isScramble(A.substr(i,n-i), B.substr(i,n-i))){
            return true;
        }
    }
    return false;
}

//Top-Down Approach
bool solve(string A, string B, unordered_map<string,int> &umap){
     
    if(A.size() != B.size()){
        return false;
    }
    int n = A.size();
    
    if(n == 0){
        return 1;
    }
    if(A == B){
        return true;
    }
    if(n < 1){
        return false;
    }
    
    string key = A + " " + B;
    
    if(umap.find(key) != umap.end()){
        return umap[key];
    }
    for(int i = 1; i <= n - 1; i++){
        
        if(solve(A.substr(0,i),B.substr(n-i,i),umap) && solve(A.substr(i,n-i), B.substr(0,n-i), umap)){
            return umap[key] = true;
        }
        
        if(solve(A.substr(0,i),B.substr(0,i),umap) && solve(A.substr(i,n-i), B.substr(i,n-i),umap)){
            return umap[key] = true;
        }
    }
    return umap[key] = false;
}
int Solution::isScramble(const string A, const string B) {
    
    unordered_map<string,int> umap;
    
    return solve(A,B,umap);
}
