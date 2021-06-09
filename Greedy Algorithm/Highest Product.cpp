//Method - 1
int Solution::maxp3(vector<int> &A) {
    
    int  n= A.size();
    
    sort(A.begin(),A.end());
    
    int max_prod = INT_MIN;
    
    max_prod = max(max_prod, A[n-1]*A[n-2]*A[n-3]);
    max_prod = max(max_prod, A[n-1]*A[n-2]*A[0]);
    max_prod = max(max_prod, A[n-1]*A[0]*A[1]);
    max_prod = max(max_prod, A[0]*A[1]*A[2]);
    
    return max_prod;
    
}
//Method - 2
//Better
int Solution::maxp3(vector<int> &A) {
    
    int  n= A.size();
    
    sort(A.begin(),A.end());
    
    int max_prod = INT_MIN;
    
    max_prod = max(max_prod, A[n-1]*A[n-2]*A[n-3]);
    max_prod = max(max_prod, A[n-1]*A[0]*A[1]);
    
    return max_prod;
}
