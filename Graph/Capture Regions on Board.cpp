//Ref: https://www.youtube.com/watch?v=_KLesu_89Ec
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
void change(int x, int y, vector<vector<char>> &A){

    A[x][y] = '*';

    for(int i = 0; i < 4; i++){
        int xo = x + dx[i], yo = y + dy[i];
        if(xo >= 0 && xo < A.size() && yo >= 0 && yo < A[0].size() && A[xo][yo] == 'O'){
            change(xo,yo,A);
        }
    }
}
void Solution::solve(vector<vector<char> > &A) {
    
    int n = A.size(), m = A[0].size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
                if(A[i][j] == 'O')
                change(i,j,A);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] == 'O'){
                A[i][j] = 'X';
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] == '*'){
                A[i][j] = 'O';
            }
        }
    }
}
