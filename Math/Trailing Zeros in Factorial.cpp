//Method - 1 
int Solution::trailingZeroes(int A) {
    
    int ans = 0;
    while(A>0){
        A=A/5;
        ans += A;
    }
    return ans;
}

//Method - 2
int Solution::trailingZeroes(int A) {

    int count = 0;
    int temp = 5;

    while(A / temp){
        count += A / temp;
        temp *= 5;
    }
    return count;
}
