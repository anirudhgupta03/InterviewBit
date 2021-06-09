//Time Complexity - O(N)
//Space Complexity - O(1)
int Solution::bulbs(vector<int> &A) {
    
    int n = A.size();
    
    if(n == 0){
        return 0;
    }
    
    int count = 0;
    
    for(int i = 0; i < A.size(); i++){
        
        if(count % 2 == 0){
            if(A[i] == 0){
                count++;
            }
        }
        else{
            A[i] = 1 - A[i];
            if(A[i] == 0){
                count++;
            }
        }
    }
    return count;
}
