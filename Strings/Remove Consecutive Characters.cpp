string Solution::solve(string A, int B) {
    
    string ans;
    
    int i = 0;
    
    while(i < A.size()){
        
        string temp;
        
        int j = i;
        
        while(i < A.size() && A[i] == A[j]){
            temp += A[i];
            i++;
        }
        
        if(temp.length() != B){
            ans += temp;
        }
    }
    
    return ans;
}
