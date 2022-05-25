int Solution::solve(int A) {

    int sum = A;

    while(sum > 9){
        int currsum = 0;
        while(sum){
            currsum += sum % 10;
            sum /= 10;
        }
        sum = currsum;
    }
    return sum;
}
