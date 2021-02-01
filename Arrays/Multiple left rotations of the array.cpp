vector<vector<int> > Solution::solve(vector<int> &A, vector<int> &B) {
    
    vector<vector<int>> v;
    
    for(auto x : B){
        vector<int> p;
        for(int i = x%(A.size()); i < A.size(); i++){
            p.push_back(A[i]);
        }
        for(int i = 0; i < x%(A.size()); i++){
            p.push_back(A[i]);
        }
        
        v.push_back(p);
    }
    
    return v;
}
