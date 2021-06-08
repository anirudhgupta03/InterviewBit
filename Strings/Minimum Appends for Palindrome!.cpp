//Similar to Minimum Characters required to make a String Palindromic except that here we will find longest prefix of rev_s which is equal to longest suffix of s
int Solution::solve(string A) {
    
    string B = A;
    reverse(B.begin(),B.end());
    
    A = B + "#" + A;
    
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
            l = lps[l-1];
        }
    }
    
    return (B.size() - lps[n-1]);
}
