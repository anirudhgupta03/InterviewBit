//Time Complexity - O(N^2)
//Space Complexity - O(N^2)
int Solution::solve(vector<vector<int> > &A, int B) {
    
    int n = A.size();
    
    vector<vector<int>> mat(n+1,vector<int>(n+1,0));
    
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < n + 1; j++){
            mat[i][j] = mat[i-1][j] + A[i-1][j-1];
        }
    }
    
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < n + 1; j++){
                mat[i][j] += mat[i][j-1];
        }
    }
    
    int max_sum = INT_MIN;
    
    for(int i = 0; i <= n - B; i++){
        for(int j = 0; j <= n - B; j++){
            max_sum = max(max_sum, (mat[i+B][j+B] - mat[i][j+B]) - (mat[i+B][j] - mat[i][j]));
        }
    }
    return max_sum;
}
