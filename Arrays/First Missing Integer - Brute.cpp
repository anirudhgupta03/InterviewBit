int Solution::firstMissingPositive(vector<int> &A) {
    
    int num = 1;
    
    sort(A.begin(),A.end());
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] > 0 && A[i]!=num){
            return num;
        }
        else if(A[i] > 0 && A[i] == num){
            num++;
        }
        
    }
    
    return num;
}
