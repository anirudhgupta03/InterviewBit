void Solution::rotate(vector<vector<int> > &A) {
    
    for(int i = 0; i < A.size(); i++){
        for(int j = i+1; j < A.size(); j++){
            swap(A[i][j],A[j][i]);
        }
    }
    
    for(int i = 0; i < A.size(); i++){
        
        int l = 0, r = A.size()-1;
        while(l<r){
            swap(A[i][l],A[i][r]);
            l++;
            r--;
        }
    }
    
}
