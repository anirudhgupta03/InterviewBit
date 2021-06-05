//Method - 1
//Time Complexity - O(N)
//Space Complexity - O(N)

int Solution::repeatedNumber(const vector<int> &A) {
    
    int arr[A.size()];
    
    for(int i = 0; i < A.size(); i++){
        arr[i] = A[i];
    }
    
    for(int i = 0; i < A.size(); i++){
        
        int j = abs(arr[i]);
        
        if(arr[j] < 0){
            return j;
        }
        
        arr[j] = -abs(arr[j]);
    }
    
    return -1;
}

//Method - 2
//Ref: https://www.youtube.com/watch?v=32Ll35mhWg0
//Time Complexity - O(N)
//Space Complexity - O(1)
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
