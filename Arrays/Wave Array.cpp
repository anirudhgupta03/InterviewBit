vector<int> Solution::wave(vector<int> &A) {
    
    sort(A.begin(),A.end());
    
    int n = A.size();
    
    vector<int> v;
    if(n % 2 == 0){
        for(int i = 0; i < n; i+=2){
            swap(A[i],A[i+1]);
        }
    }
    else{
        for(int i = 0; i < n -1; i+=2){
            swap(A[i],A[i+1]);
        }
    }
    return A;
}
