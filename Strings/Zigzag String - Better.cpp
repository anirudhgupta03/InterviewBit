string Solution::convert(string A, int B) {
    
    if(B == 1){
        return A;
    }
    string str[B];
    
    int itr = 1, i = -1, j = 0;
    
    while(j < A.size()){
        
        if(itr % 2 == 1){
            i++;
            while(i < B && j < A.size()){
                str[i].push_back(A[j]);
                i++;
                j++;
            }
            itr++;
            i--;
        }
        else{
            i--;
            while(i >=0 && j < A.size()){
                str[i].push_back(A[j]);
                i--;
                j++;
            }
            itr++;
            i++;
        }
    }
    
    string p;
    for(int i = 0; i < B; i++){
        p += str[i];
    }
    
    return p;
}
