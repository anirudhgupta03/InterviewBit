int Solution::solve(vector<int> &A) {
    
    sort(A.begin(),A.end());
    
    int n = A.size();
    
    int x = 0, y = 1, ele = A[n-1];
    
    int arr[n];
    
    arr[n-1] = 0;
    
    for(int i = n-2; i>=0; i--){
        if(A[i] < ele){
            arr[i] = y;
            x = y;
            y++;
        }
        else{
            arr[i] = x;
            y++;
        }
        ele = A[i];
    }
    
    for(int i = 0; i < n; i++){
        if(arr[i] == A[i]){
            return 1;
        }
    }
    
    return -1;
}
