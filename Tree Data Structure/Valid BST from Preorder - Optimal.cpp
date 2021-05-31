//Ref: https://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/
//Ref: https://www.youtube.com/watch?v=hPVDhNfO1Ng
//Ref: https://www.youtube.com/watch?v=GYdC4hQSo8A
//Time Complexity - O(N)
//Space Complexity - O(N)
int Solution::solve(vector<int> &A) {
    
    int root = INT_MIN;
    
    stack<int> s;
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] < root){
            return 0;
        }
        
        while(!s.empty() && A[i] > s.top()){
            root = s.top();
            s.pop();
        }
        
        s.push(A[i]);
    }
    
    return 1;
}
