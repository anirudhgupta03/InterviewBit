//Method - 1
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

//Method - 2
int Solution::solve(vector<int> &A, int B) {
    
    int currsum = 0, count = 0;
    
    unordered_map<int,int> umap;
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] % 2 != 0){
            currsum += 1;
        }
        
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

//Method - 3
int Solution::solve(vector<int> &A, int B) {

    vector<int> v;

    for(int i = 0; i < A.size(); i++){
        if(A[i] % 2 == 0){
            v.push_back(0);
        }
        else{
            v.push_back(1);
        }
    }
    unordered_map<int,int> umap;
    umap[0] = 1;
    int sum = 0, count = 0;

    for(int i = 0; i < v.size(); i++){
        sum += v[i];
        if(umap.find(sum - B) != umap.end()){
            count += umap[sum - B];
        }
        umap[sum]++;
    }
    return count;
}
