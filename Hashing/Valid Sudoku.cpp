//Method - 1
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

//Method - 2
int Solution::isValidSudoku(const vector<string> &A) {
    
    for(int j = 0; j < 9; j++){
        vector<int> vis(10, 0);
        for(int i = 0; i < 9; i++){
            if(A[i][j] == '.') continue;
            if(vis[A[i][j] - '0']){
                return 0;
            }
            vis[A[i][j] - '0'] = 1;
        }
    }

    for(int i = 0; i < 9; i++){
        vector<int> vis(10,0);
        for(int j = 0; j < 9; j++){
            if(A[i][j] == '.') continue;
            if(vis[A[i][j] - '0']){
                return 0;
            }
            vis[A[i][j] - '0'] = 1;
        }
    }  
    int i = 0, j = 0, count = 1, tcount = 0;
    while(1){
        if(i == 9 && j == 9){
            break;
        }
        if(j == 9){
            tcount = 1;
            i = 3*count;
            count++;
            j = 0;
        }
        else{
            tcount++;
            i = 3*(count - 1);
        }
       
        vector<int> vis(10, 0);
        for(; i < count*3; i++){
            for(int k = j; k < tcount*3; k++){
                if(A[i][k] == '.') continue;
                if(vis[A[i][k] - '0']){
                    return 0;
                }
                vis[A[i][k] - '0'] = 1;
            }
        }
        j = 3*tcount;
    }
    return 1;
}
