//Ref: https://www.youtube.com/watch?v=9vYCQLYF6ng&t=768s
int Solution::solve(vector<vector<int> > &A) {
    
    for(int j = 0; j < A[0].size(); j++){
        for(int i = 1; i < A.size(); i++){
            if(A[i][j] != 0)
            A[i][j] += A[i-1][j];
        }
    }
    
    for(int i = 0; i < A.size(); i++){
        sort(A[i].begin(),A[i].end());
    }
    
    int maxArea = 0;
    
    for(int i = 0; i < A.size(); i++){
        
        for(int j = A[0].size() - 1; j >= 0; j--){
            
            int area = A[i][j]*(A[0].size() - j);

            maxArea = max(maxArea,area);
        }
    }
    
    return maxArea;
}
