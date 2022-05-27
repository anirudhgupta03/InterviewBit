int Solution::solve(int A) {
    int count = 0;
    for(int i = 1; i <= A; i++){
        for(int j = i + 1; j <= A; j++){
            int temp = sqrt(i*i + j*j);
            if(temp*temp == (i*i + j*j) && temp <= A){
                count++;
            }
            if(i*i + j*j > A*A) break;
        }
    }
    return count;
}
