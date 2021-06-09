//Time Complexity - O(NlogN)
//Space Complexity - O(N)
int Solution::solve(vector<vector<int> > &A) {

    int n = A.size();
    
    if(n == 0){
        return 0;
    }
    int start[n], end[n];
    
    for(int i = 0; i < A.size(); i++){
        start[i] = A[i][0];
        end[i] = A[i][1];
    }
    sort(start,start+n);
    sort(end,end+n);
    
    int res = 1;
    
    int i = 1, j = 0;
    
    while(i < n && j < n){
        
        if(end[j] <= start[i]){
            i++;
            j++;
        }
        else{
            res++;
            i++;
        }
    }
    return res;
}
