int Solution::isValidSudoku(const vector<string> &A) {
    
    int temp2[A.size()][A.size()+1];
    
    memset(temp2,0,sizeof(temp2));
    
    int n = sqrt(A.size());
    
    for(int i = 0; i < A.size(); i++){
        
        int temp1[A.size()+1] ={0};
        
        for(int j = 0; j < A.size(); j++){
            
            if(A[i][j] != '.'){
                
                //Checking in row
                if(temp1[A[i][j]-48] != 0){
                    return 0;
                }
                else{
                    temp1[A[i][j]-48]++;
                }
                //Checking in column 
                if(temp2[j][A[i][j]-48] != 0){
                 return 0;
                }
                else{
                    temp2[j][A[i][j]-48]++;
                }
                
                for(int k = (i/n)*n; k < (i/n)*n + n; k++){
                    for(int l = (j/n)*n; l < (j/n)*n + n; l++){
                        
                        if(k == i && l == j){
                            continue;
                        }
                        
                        if(A[k][l] == A[i][j]){
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 1;
}
