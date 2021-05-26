int Solution::solve(vector<int> &A, int B) {

    if(B == 0){
        int l = 0, r = 0;
        
        while(r < A.size()){
            
            if(A[r] % 2 != 0){
                int n = r-l;
                ans += n*(n+1)/2;
                l = r + 1;
                r++;
            }
            else{
                r++;
            }
        }
        int n = r-l;
        ans += n*(n+1)/2;
        return ans;
    }
    
    if(B == 1){
        
        int l = 0, r = 0, i1;
        
        while(l <= r && r < A.size()){
        
            if(A[r] % 2 == 0){
                r++;
            }
            else{
                count++;
                
                if(count > B){
                    ans += i1-l + 1 + (r-1-i1) + (i1-l)*(r-1-i1);
                    l = i1+1;
                    i1 = r;
                    count--;
                }
                else{
                    i1 = r;
                }
                r++;
            }
        }
        if(count == B){
          ans += i1-l + 1 + (r-1-i1) + (i1-l)*(r-1-i1);
          return ans;
        }
        return 0;
    }
    
    unordered_map<int,int> umap;
    
    int ans = 0;
    
    int l = 0, r = 0;
    
    int count = 0;
    
    int prev = -1, i1,i2;
    
    while(l <= r && r < A.size()){
        
        if(A[r] % 2 == 0){
            r++;
        }
        else{
            count++;
            
            if(count > B){
                ans += i1-l + 1 + (r-1-i2) + (i1-l)*(r-1-i2);
                umap[prev] = r;
                i2 = r;
                l = i1+1;
                i1 = umap[i1];
                prev = r;
                count--;
            }
            else{
                if(prev == -1){
                    i1 = r;
                    prev = r;
                    r++;
                    continue;
                }
                if(count == B){
                    i2 = r;
                }
                umap[prev] = r;
                prev = r;
            }
            r++;
        }
    }
    if(count == B){
      ans += i1-l + 1 + (r-1-i2) + (i1-l)*(r-1-i2);
      return ans;
    }
    return 0;
}
