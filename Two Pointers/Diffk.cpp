//Similar Problem: https://www.interviewbit.com/problems/pair-with-given-difference/
//Method - 1
//Time Complexity - O(NlogN)
//Space Complexity - O(1)
int Solution::diffPossible(vector<int> &A, int B) {
    
    for(int i = 0; i < A.size(); i++){
        
        int count = upper_bound(A.begin(),A.end(),A[i]-B) - lower_bound(A.begin(),A.end(),A[i]-B);
        
        if(B == 0){
            if(count >= 2){
                return true;
            }
        }
        else if(count != 0){
            return true;
        }
    }
    return false;
}

//Method - 2
//Time Complexity - O(N)
//Space Complexity - O(1)
int Solution::diffPossible(vector<int> &A, int B) {
    
    int l = 0, r = 1;
    
    while(r < A.size()){
        
        if(l == r){
            r++;
        }
        
        if(A[r] - A[l] > B){
            l++;
        }
        else if(A[r] - A[l] == B){
            return 1;
        }
        else{
            r++;
        }
    }
    return 0;
}
