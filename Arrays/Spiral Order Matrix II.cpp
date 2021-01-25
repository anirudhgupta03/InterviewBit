vector<vector<int> > Solution::generateMatrix(int A) {
    
    int spiral[A][A];
    
    int num = 1, i = 0, j = 0, cnt = 0;
    
    int row[A] = {0},column[A] = {0};
    
    while(num <= A*A){
        
        if(cnt%2==0){
            while(column[j] != 1 && j < A){
                spiral[i][j] = num;
                j++;
                num++;
            }
            row[i] = 1;
            i++;
            j--;
            while(row[i] != 1 && i < A){
                spiral[i][j] = num;
                i++;
                num++;
            }
            column[j] = 1;
            j--;
            i--;
            cnt++;
        }
        else{
            while(column[j] != 1 && j >= 0){
                spiral[i][j] = num;
                j--;
                num++;
            }
            row[i] = 1;
            i--;
            j++;
            while(row[i] != 1 && i >= 0){
                spiral[i][j] = num;
                i--;
                num++;
            }
            column[j] = 1;
            j++;
            i++;
            cnt++;
        }
    }
    
    vector<vector<int> > v;
    for(int i = 0; i < A; i++){
        vector<int> vect;
        for(int j = 0; j < A; j++){
          vect.push_back(spiral[i][j]); 
        }
        v.push_back(vect);
    }
    
    return v;
}
