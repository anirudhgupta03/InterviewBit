//Time Complexity - O(N)
//Space Complexity - O(1)
vector<int> Solution::solve(vector<int> &A) {
    
    vector<int> res;
    int n = A.size();
    res.push_back(A[n-1]);
    
    int max_element = A[n-1];
    
    for(int i = n - 2; i >= 0; i--){
        
        if(A[i] > max_element){
            res.push_back(A[i]);
            max_element = A[i];
        }
    }
    return res;
}
