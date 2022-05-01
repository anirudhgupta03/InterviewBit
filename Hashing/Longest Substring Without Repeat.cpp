//Method - 1
int Solution::lengthOfLongestSubstring(string A) {
    
    if(A.size() == 1){
        return 1;
    }
    int max_len = INT_MIN;
    
    int l = 0, r = 1;
    
    unordered_map<char,int> alpha;
    
    alpha[A[l]] = l;
    
    while(r < A.size()){
        
        if(alpha.find(A[r]) != alpha.end()){
            
            if(alpha[A[r]] >= l)                //We don't need to consider the occurences of a character before l 
            {
                //cout << A.substr(l,r-l) << endl;
                max_len = max(max_len,r-l);
                l = alpha[A[r]] + 1;            //Jump to the next index of the repeated element
                alpha[A[r]] = r;                
                r++;
            }
            else{                               
                alpha[A[r]] = r;
                r++;
            }
        }
        else{
            alpha[A[r]] = r;
            r++;
        }
        //cout << max_len << " ";
    }
    max_len = max(max_len,r-l);
    return max_len;
}

//Method - 2
int Solution::lengthOfLongestSubstring(string A) {
    
    unordered_map<char,int> umap;
    
    int l = 0, r = 0;
    
    int maxLen = 1;
    
    while(r < A.size()){
        
        if(umap.find(A[r]) != umap.end()){
            if(umap[A[r]] >= l){
                maxLen = max(maxLen, r - l);
                l = umap[A[r]] + 1;
            }
        }
        umap[A[r]] = r;
        r++;
    }
    maxLen = max(maxLen, r - l);
    return maxLen;
}

//Method - 3
int Solution::lengthOfLongestSubstring(string A) {

    unordered_map<char,int> umap;
    int maxLen = 0;

    int lo = 0;

    for(int i = 0; i < A.size(); i++){
        if(umap.find(A[i]) != umap.end() && umap[A[i]] >= lo){
            lo = umap[A[i]] + 1;
        }
        maxLen = max(maxLen, i - lo + 1);
        umap[A[i]] = i;
    }
    return maxLen;
}
