int Solution::repeatedNumber(const vector<int> &A) {
    
    int hare = A[0] , tortoise = A[0];
    
    do{
       tortoise = A[tortoise];
       hare = A[A[hare]];
    }while(hare != tortoise);
    
    hare = A[0];
    
    while(hare != tortoise){
        hare = A[hare];
        tortoise = A[tortoise];
    }
    
    return hare;
}
