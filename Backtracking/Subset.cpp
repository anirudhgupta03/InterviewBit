void solve(vector<int> &s, vector<vector<int>> &v, vector<int> &A, int ind){
    
    if(ind == A.size()){
        v.push_back(s);
        return;
    }
    
    solve(s, v, A, ind+1);
    
    s.push_back(A[ind]);
    
    solve(s, v, A, ind+1);
    
    s.pop_back();
}
vector<vector<int> > Solution::subsets(vector<int> &A) {
    
    sort(A.begin(),A.end());
    
    vector<int> s;
    
    vector<vector<int>> v;
    
    solve(s,v,A,0);
    
    //sort(v.begin(),v.end());     Not Required    
    
    return v;
}
