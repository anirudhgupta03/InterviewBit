int Solution::diffPossible(vector<int> &A, int B) {
    
    int l = 0, r = 1;
    
    while(r < A.size()){
        
        if(l == r){
            r++;
        }
        
        if(A[r] - A[l] > B){
            l++;
        }
        else if(A[r] - A[l] == B){
            return 1;
        }
        else{
            r++;
        }
    }
    return 0;
}
