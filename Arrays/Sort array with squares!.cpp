vector<int> Solution::solve(vector<int> &A) {
    
    vector<int> ans(A.size());
    
    int i=0,j = A.size()-1 , k = A.size()-1;
    
    while(i<=j){
        
        if(abs(A[i])>abs(A[j])){
            ans[k] = A[i]*A[i];
            i++;
            k--;
        }
        else{
            ans[k] = A[j]*A[j];
            j--;
            k--;
        }
    }
    
    return ans;
}
