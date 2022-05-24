int myPower(int a, int b){

    if(b == 0) return 1;
    if(b == 1) return a;

    int temp = myPower(a, b/2);
    if(b % 2 == 0) return temp*temp;
    return a*temp*temp;
}
int Solution::solve(int A) {

    int count = 0, B = A;

    while(B){
        count++;
        B /= 10;
    }

    int sum = 0;
    B = A;
    while(B){
        sum += myPower(B % 10, count);
        B /= 10;
    }
    
    if(sum == A) return 1;
    return 0;
}
