int Solution::majorityElement(const vector<int> &A) {
    
    int ele = A[0], count = 1;
    
    for(int i = 1; i < A.size(); i++){
        
        if(A[i] != ele){
            count--;
        }
        else{
            count++;
        }
        
        if(count == 0){
            ele = A[i];
            count = 1;
        }
    }
    return ele;
}
