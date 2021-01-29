string Solution::solve(string A) {
    
    int ind1 = A.size()-2;
    
    while(A[ind1] >= A[ind1+1] && ind1>=0){
        ind1--;
    }
    
    if(ind1 == -1){
        return "-1";
    }
    
    int ind2;
    for(int i = ind1+1; i < A.size(); i++){
        
        if(A[i] > A[ind1]){
            ind2 = i;
        }
        else{
            break;
        }
        
    }
    swap(A[ind1],A[ind2]);
    
    int i = ind1 + 1, j = A.size()-1;
    while(i <= j){
        swap(A[i],A[j]);
        i++;
        j--;
    }
    
    return A;
}
