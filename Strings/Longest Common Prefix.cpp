string Solution::longestCommonPrefix(vector<string> &A) {
    
    sort(A.begin(),A.end());
    
    int i = 0;
    
    string ans;
    
    while(A[0][i] == A[A.size()-1][i] && i < min(A[0].size(),A[A.size()-1].size())){
        ans += A[0][i];
        i++;
    }
    
    return ans;
}
