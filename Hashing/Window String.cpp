string Solution::minWindow(string A, string B) {
    
    unordered_map<char,int> pat,txt;
    
    for(int i = 0; i < B.size(); i++){
        pat[B[i]]++;
    }
    
    int l = 0, r = 0;
    
    int min_len = INT_MAX;
    
    int count = 0;  
    
    string ans;
    
    int k = pat.size();
    
    while(r < A.size()){
        
        txt[A[r]]++;
        
        if(pat.find(A[r]) != pat.end()){
            if(pat[A[r]] == txt[A[r]]){
                count++;
            }
        }
        
        if(count == k){
            
            if(r-l+1 < min_len){
                min_len = r - l + 1;
                ans = A.substr(l,r-l+1);
            }
            
            while(l < r){
                txt[A[l]]--;
                if(pat.find(A[l]) != pat.end() && txt[A[l]] < pat[A[l]]){   //If the current count of a character in txt is less than the required count in pat then decrease count
                    count--;
                    if(txt[A[l]] == 0){
                        txt.erase(A[l]);
                    }
                    l++;  //Move the left pointer one step right
                    break;
                }
                l++;
                if(r-l+1 < min_len){
                    min_len = r - l + 1;
                    ans = A.substr(l,r-l+1);
                }
            }
        }
        r++;
    }
    return ans;
}
