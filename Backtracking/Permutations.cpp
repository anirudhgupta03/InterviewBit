void solve(int index,vector<vector<int>> &v, vector<int> &A){
    
    if(index == A.size()){
        v.push_back(A);
        return;
    }
    
    for(int i = index; i < A.size(); i++){
        swap(A[index],A[i]);
        solve(index+1,v,A);
        swap(A[index],A[i]);
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    
    vector<vector<int>> v;
    
    solve(0,v,A);
    
    return v;
}
