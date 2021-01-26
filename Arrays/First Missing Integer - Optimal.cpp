int Solution::firstMissingPositive(vector<int> &A) {
    
    for(int i = 0; i < A.size(); i++){
        
        while(A[i] != i+1 && A[i] <= A.size() && A[i] > 0){
            if(A[i] != A[A[i]-1])
                swap(A[i],A[A[i]-1]);
            else 
                break;
        }
        
    }
    
    for(int i = 0; i < A.size(); i++){
        if(A[i]!=i+1){
            return i+1;
        }
    }
    return A.size()+1;
}
