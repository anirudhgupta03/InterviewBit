int Solution::solve(vector<int> &A, int B) {
    
    sort(A.begin(),A.end());
    
    int l = 0, r = 1;
    
    while(r < A.size()){
        
        if(A[r] - A[l] == B && l != r){
            return 1;
        }
        else if(A[r] - A[l] > B){
            l++;
        }
        else{
            r++;
        }
    }
    
    return 0;
}
