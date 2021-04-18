int Solution::majorityElement(const vector<int> &A) {
    
    int n = 0, ele;
    
    for(int i = 0; i < A.size(); i++){
        
        if(n == 0){
            ele = A[i];
            n++;
        }
        else if(ele == A[i]){
            n++;
        }
        else{
            n--;
        }
        
        
    }
    return ele;
}
