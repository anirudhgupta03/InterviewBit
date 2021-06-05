//Method - 1
//Time Complexity - O(N^2)
//Space Complexity - O(1)
void Solution::rotate(vector<vector<int> > &A) {
    
    for(int i = 0; i < A.size(); i++){              //Transpose
        for(int j = i+1; j < A.size(); j++){
            swap(A[i][j],A[j][i]);
        }
    }
    
    for(int i = 0; i < A.size(); i++){
        
        int l = 0, r = A.size()-1;
        while(l<r){
            swap(A[i][l],A[i][r]);                  //Reverse every row now
            l++;
            r--;
        }
    }
    
}
//Method - 2
//Time Complexity - O(N^2)
//Space Complexity - O(1)
void Solution::rotate(vector<vector<int> > &A) {
    
    int n = A.size();
    
    int l = 0, r = n - 1;
    
    while(l < r){
        for(int i = 0; i < n; i++){
            swap(A[l][i],A[r][i]);
        }
        l++;
        r--;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            swap(A[i][j],A[j][i]);
        }
    }
}
