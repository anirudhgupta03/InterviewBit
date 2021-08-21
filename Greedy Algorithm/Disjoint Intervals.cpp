//TLE
bool cmp(vector<int> v1, vector<int> v2){
    return v1[1] < v2[1];
}
int Solution::solve(vector<vector<int> > &A) {
    
    sort(A.begin(),A.end(),cmp);
    
    int count = 1;
    
    int start = A[0][0], end = A[0][1];
    
    for(int i = 1; i < A.size(); i++){
        
        if(A[i][0] > end){
            count++;
            end = A[i][1];
        }
    }
    return count;
}
//Accepted
bool cmp(vector<int> &v1, vector<int> &v2){         //Pass by reference
    return v1[1] < v2[1];
}
int Solution::solve(vector<vector<int> > &A) {
    
    sort(A.begin(),A.end(),cmp);
    
    int count = 1;
    
    int start = A[0][0], end = A[0][1];
    
    for(int i = 1; i < A.size(); i++){
        
        if(A[i][0] > end){
            count++;
            end = A[i][1];
        }
    }
    return count;
}
