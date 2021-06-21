//Method - 1
int Solution::removeElement(vector<int> &A, int B) {
    
    bool flag = false;
    
    int l = A.size(), r = 0;
    
    while(r < A.size()){
        
        if(A[r] == B && !flag){
            l = r;
            flag = true;
        }
        else if(A[r] != B && flag){
            A[l] = A[r];
            l++;
        }
        r++;
    }
    return l;
}

//Method - 2
//Nice Approach
int Solution::removeElement(vector<int> &A, int B) {
    
    int l = 0;
    
    for(int r = 0; r < A.size(); r++){
        
        if(A[r] != B){
            
            A[l] = A[r];
            l++;
        }
    }
    return l;
}
