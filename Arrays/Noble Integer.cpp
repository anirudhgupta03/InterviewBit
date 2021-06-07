//Time Complexity - O(NlogN)
//Space Complexity - O(N)
int Solution::solve(vector<int> &A) {
    
    sort(A.begin(),A.end());
    
    int n = A.size();
    
    int x = 0, y = 1, ele = A[n-1];
    
    int arr[n];
    
    arr[n-1] = 0;
    
    for(int i = n-2; i>=0; i--){
        if(A[i] < ele){
            arr[i] = y;
            x = y;
            y++;
        }
        else{
            arr[i] = x;
            y++;
        }
        ele = A[i];
    }
    
    for(int i = 0; i < n; i++){
        if(arr[i] == A[i]){
            return 1;
        }
    }
    
    return -1;
}
//Time Complexity - O(NlogN)
//Space Complexity - O(N)
//Using upper_bound function
int Solution::solve(vector<int> &A) {
    
    sort(A.begin(),A.end());
    
    unordered_set<int> s;
    
    for(auto x: A){
        s.insert(x);
    }
    
    int count = 0;

    for(auto x: s){
        
        int c = A.end() - upper_bound(A.begin(),A.end(),x);
        if(c == x){
            return 1;
        }
    }
    return -1;
}
//Time Complexity - O(NlogN)
//Space Complexity - O(1)
int Solution::solve(vector<int> &A) {
    
    sort(A.begin(),A.end());
    
    if(A[A.size()-1] == 0){         //if last element is zero then no issue
        return 1;
    }
    
    for(int i = 0; i < A.size(); i++){
        
        if(A[i] != A[i+1]){
            int count = A.size() - i - 1;
            if(count == A[i]){
                return 1;
            }
        }
    }
    return -1;
}
