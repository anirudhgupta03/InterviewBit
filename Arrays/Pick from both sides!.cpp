//Method - 1
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

//Method - 2
int Solution::solve(vector<int> &A, int B) {

    int n = A.size();

    int sum = 0, maxSum = INT_MIN;

    for(int i = 0; i < B; i++){
        sum += A[i];
    }
    maxSum = max(maxSum, sum);

    for(int i = n - 1; i >= n - B; i--){
        sum -= A[B - (n - i)];
        sum += A[i];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}
