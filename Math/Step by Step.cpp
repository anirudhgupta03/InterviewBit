//Method - 1
int Solution::solve(int A) {
    
    int steps = 0, sum = 0, difference, i = 1;
    
    if(A == 0){
        return 0;
    }
    A = abs(A);
    while(1){
        sum = sum + i;
        steps++;
        if(sum > A){
            break;
        }
        else if(sum == A){
            return steps;
        }
        i++;
    }
    difference = sum - A;
    if(difference % 2 == 0){
        return steps;
    }
    else{
        if((steps+1)%2==0){
            return steps+2;
        }
        else{
            return steps+1;
        }
    }
}

//Method - 2
int Solution::solve(int A) {

    A = abs(A);
    
    int sum = 0, count = 0;

    while(sum < A){
        count++;
        sum += count;
    }

    int diff = sum - A;
    
    while(diff % 2 != 0){
        count++;
        diff += count;
    }
    return count;
}
