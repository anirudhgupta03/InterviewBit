void solve(int ind, vector<int> &A, set<vector<int>> &s, vector<int> &p){
    
    if(ind == A.size()){
        s.insert(p);
        return;
    }
    
    solve(ind+1,A,s,p);
    
    p.push_back(A[ind]);
    
    solve(ind+1,A,s,p);
    
    p.pop_back();
    
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    
    sort(A.begin(),A.end());
    
    set<vector<int>> s;
    
    int ind = 0;
    
    vector<int> p;
    
    vector<vector<int>> v;
    
    solve(0,A,s,p);
    
    set<vector<int>> :: iterator it;
    
    for(it = s.begin(); it!= s.end(); it++){
        v.push_back(*it);
    }
    
    sort(v.begin(),v.end());
    
    return v;
}
