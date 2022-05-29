vector<vector<int> > Solution::solve(vector<int> &A, int B, int C) {

    vector<vector<int>> res(B, vector<int>(C));

    int ind = 0, left = 0, right = C - 1, top = 0, down = B - 1, dir = 0;

    while(top <= down && left <= right){
        if(dir == 0){
            for(int i = left; i <= right; i++){
                res[top][i] = A[ind];
                ind++;
            }
            top++;
        }
        else if(dir == 1){
            for(int i = top; i <= down; i++){
                res[i][right] = A[ind];
                ind++;
            }
            right--;
        }
        else if(dir == 2){
            for(int i = right; i >= left; i--){
                res[down][i] = A[ind];
                ind++;
            }
            down--;
        }
        else if(dir == 3){
            for(int i = down; i >= top; i--){
                res[i][left] = A[ind];
                ind++;
            }
            left++;
        }
        dir = (dir + 1)%4;
    }
    return res;
}
