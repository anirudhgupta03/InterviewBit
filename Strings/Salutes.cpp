long Solution::countSalutes(string A) {

    long sum = 0, count = 0;

    for(int i = 0; i < A.size(); i++){
        if(A[i] == '<'){
            sum += count;
        }
        else{
            count++;
        }
    }
    return sum;
}
