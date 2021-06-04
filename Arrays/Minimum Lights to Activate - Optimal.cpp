//Time Complexity - O(N^2)
//Space Complexity - O(N)
//Greedy Approach
int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    vector<int> temp(n,-1);
    
    for(int i = 0; i < n; i++){
        
        if(A[i] == 1){
            int start = max(0,i-B+1);
            int end = min(i+B-1,n-1);
            
            for(int j = start; j <= end; j++){
                temp[j] = end;
            }
        }
    }
    
    int i = 0;
    int count = 0;
    
    while(i != n){
        i = temp[i];
        count++;
        if(i == -1){
            return -1;
        }
        i++;
    }
    return count;
}
