//Using KMP LPS 
int Solution::solve(string A) {
    
    string B = A;
    reverse(B.begin(),B.end());
    
    A = A + "#" + B;
    
    int n = A.size();
    
    int lps[n];
    
    lps[0] = 0;
    
    int l = 0, r = 1;
    
    while(r < n){
        
        if(A[l] == A[r]){
            lps[r] = l + 1;
            l++;
            r++;
        }
        else if(A[l] != A[r] && l == 0){
            lps[r] = 0;
            r++;
        }
        else if(A[l] != A[r]){
            
            while(l != 0){
                l = lps[l-1];
                if(A[l] == A[r]){
                    lps[r] = l + 1;
                    l++;
                    r++;
                    break;
                }
            }
            
            if(l == 0){
                
                if(A[l] == A[r]){
                    lps[r] = l + 1;
                    l++;
                    r++;
                }
                else{
                    lps[r] = 0;
                    r++;
                }
            }
        }
    }
    return (B.size() - lps[n-1]);
}
