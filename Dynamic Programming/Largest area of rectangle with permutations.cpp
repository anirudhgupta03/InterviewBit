//Ref: https://www.youtube.com/watch?v=9vYCQLYF6ng&t=768s
//TC - O(n*m*log(m))
//SC - O(1)
int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j]){
                A[i][j] += A[i - 1][j];
            }
        }
    }
    int maxArea = 0;
    for(int i = 0; i < n; i++){
        sort(A[i].begin(),A[i].end());
        for(int j = 0; j < m; j++){
            maxArea = max(maxArea, A[i][j]*(m - j));
        }
    }
    return maxArea;
}
