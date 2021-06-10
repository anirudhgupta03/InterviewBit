//Brute Force Approach
//Start from every i, and check to see if every point is reachable with the gas available. Return the first i for which you can complete the trip without the gas reaching a negative number.
//This approach would however be quadratic.
//Time Complexity - O(N^2)
//Space Complexity - O(1)

//Ref: https://www.youtube.com/watch?v=nTKdYm_5-ZY
//Time Complexity - O(N)
//Space Complexity - O(1)
int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    
    int s = 0, d = 0, start = 0, n = A.size();
    
    for(int i = 0; i < n; i++){
        
        if(A[i] + s >= B[i]){
            s += A[i] - B[i];
        }
        else{
            start = (i + 1)%n;
            d += A[i] + s - B[i];
            s = 0;
        }
    }
    
    if(s + d >= 0){
        return start;
    }
    return -1;
}
