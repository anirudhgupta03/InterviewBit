//Time Complexity - O(N^2)
//Space Complexity - O(N)
int Solution::colorful(int A) {
    
    string s = to_string(A);
    
    unordered_map<int,int> umap;
    
    for(int i = 0; i < s.size(); i++){
        
        int prod = 1;
        
        for(int j = i; j < s.size(); j++){
          
            prod *= s[j] - '0';
         
            if(umap.find(prod) != umap.end()){
                return 0;
            }
            umap[prod]++;
        }
    }
    return 1;
}
