int Solution::majorityElement(const vector<int> &A) {
    
    int e1,e2,c1 = 0,c2 = 0;
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] == e1){
            c1++;
        }
        else if(A[i] == e2){
            c2++;
        }
        else if(c2 > c1){
            e1 = A[i];
            c1 = 1;
        }
        else {
            e2 = A[i];
            c2 = 1;
        }
    }
    if(c1 > c2){
        return e1;
    }
    return e2;
}
