vector<int> Solution::maxone(vector<int> &A, int B) {
    
    int n = A.size();
    
    int lo = 0, hi = 0, count = 0;
    
    int maxLen = 0, start = 0;
    
    while(hi < A.size()){
        
        if(A[hi] == 0){
            count++;
        }
        
        if(count > B){
            if(hi-lo > maxLen){
                start = lo;
                maxLen = hi-lo;
            }
            while(lo < hi && A[lo] != 0){
                    lo++;
            }
            lo++;
            count--;
        }
        hi++;
    }
    if(hi-lo > maxLen){
        start = lo;
        maxLen = hi-lo;
    }
  
    vector<int> res;
    for(int j = start; j < start + maxLen; j++){
        res.push_back(j);
    }
    return res;
}

//Alter
vector<int> Solution::maxone(vector<int> &A, int B) {

    int l = 0, r = 0, start = 0, maxLen = 0;

    while(r < A.size()){

        if(A[r] == 0){
            B--;

            if(B < 0){
                
                if(r - l > maxLen){
                    maxLen = r - l;
                    start = l;
                }
                while(l < r && A[l] == 1){
                    l++;
                }
                l++;
            }
        }
        r++;
    }
    if(r - l > maxLen){
        maxLen = r - l;
        start = l;
    }

    vector<int> res;
    for(int i = start; i < start + maxLen; i++){
        res.push_back(i);
    }

    return res;
}
