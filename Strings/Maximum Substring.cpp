int Solution::solve(string A, int B) {

    int maxCount = 0, count = 0;

    for(int i = 0; i < A.size(); i++){
        if(i % B == 0){
            if(A[i] == 'a') count = 1;
            else count = 0;
        }
        else{
            if(A[i] == 'a') count++;
        }
        maxCount = max(maxCount, count);
    }
    return maxCount;
}
