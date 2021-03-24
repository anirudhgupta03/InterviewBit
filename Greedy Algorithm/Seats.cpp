int Solution::seats(string A) {
    
    int n = 0;
    
    for(auto x : A){
        
        if(x == 'x'){
            n++;
        }
    }
    int arr[n],j=0;
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] == 'x'){
            arr[j] = i;
            j++;
        }
    }
    
    int mid = n/2;
    
    int jumps = 0;
    
    for(int i = 0; i < n; i++){
        
        int start = arr[i];
        int end = arr[mid] - mid + i;
        
        jumps = (jumps + abs(start - end))%10000003;
    }
    return jumps%10000003;
}
