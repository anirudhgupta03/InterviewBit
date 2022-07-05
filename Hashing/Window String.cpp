//Method - 1
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

//Method - 2
//Short and Concise
string Solution::minWindow(string A, string B) {
 
    unordered_map<char,int> umap;
    
    for(auto &x: B){
        umap[x]++;
    }
    int count = umap.size();
    
    int lo = 0, hi = 0, minLen = INT_MAX, start = -1, tcount = 0;
    
    unordered_map<char,int> tumap;
    
    while(hi < A.size()){
        
        tumap[A[hi]]++;
        if(tumap[A[hi]] == umap[A[hi]]){
            tcount++;
        }
        
        if(tcount == count){
            while(lo <= hi){
                if(hi - lo + 1 < minLen){
                    start = lo;
                    minLen = hi - lo + 1;
                }
                tumap[A[lo]]--;
                if(tumap[A[lo]] < umap[A[lo]]){
                    tcount--;
                    lo++;
                    break;
                }
                lo++;
            }
        }
        hi++;
    }
    if(start == -1) return "";
    return A.substr(start, minLen);
}
