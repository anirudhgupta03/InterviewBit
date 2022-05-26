//Method - 1
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

//Method - 2
vector<vector<int> > Solution::generateMatrix(int A) {

    vector<vector<int>> res(A, vector<int>(A));

    int count = 1;

    int top = 0, down = A - 1, left = 0, right = A - 1, dir = 0;

    while(top <= down && left <= right){

        if(dir == 0){
            for(int i = left; i <= right; i++){
                res[top][i] = count;
                count++;
            }
            top++;
        }
        else if(dir == 1){
            for(int i = top; i <= down; i++){
                res[i][right] = count;
                count++;
            }
            right--;
        }
        else if(dir == 2){
            for(int i = right; i >= left; i--){
                res[down][i] = count;
                count++;
            }
            down--;
        }
        else if(dir == 3){
            for(int i = down; i >= top; i--){
                res[i][left] = count;
                count++;
            }
            left++;
        }
        dir = (dir + 1) % 4;
    }
    return res;
}
