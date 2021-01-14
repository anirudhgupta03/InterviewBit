int Solution::solve(vector<int> &A, int B) {
    
    int sum = 0;
    
    for(int i = 0; i < B; i++){
        
        sum = sum + A[i];
    }
    
    int l = B-1, r = A.size()-1, temp = sum;
    
    while(l != -1){
        temp = temp + A[r] - A[l];
        
        if(temp > sum){
            sum = temp;
        }
        l--;
        r--;
    }
    return sum;
}
