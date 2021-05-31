//Ref: https://www.youtube.com/watch?v=hPVDhNfO1Ng
//Time Complexity - O(N*N)
//Space Complexity - O(1)

bool helper(vector<int> &A, int l, int r){
    
    if(l >= r){
        return true;
    }
    
    int i;
    for(i = l + 1; i < r; i++){
        if(A[i] > A[l]){
            break;
        }
    }
    
    for(int j = i + 1; j < r; j++){
        if(A[j] < A[l]){
            return false;
        }
    }
    
    bool left = helper(A,l+1,i-1);
    bool right = helper(A,i+1,r);
    return left && right;
}
int Solution::solve(vector<int> &A) {
    
    return helper(A,0,A.size() - 1);
}
