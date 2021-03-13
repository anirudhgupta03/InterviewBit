set<vector<int>> s;

void solve(vector<int> &A,vector<int> v, int B, int ind){
    
    if(ind == A.size()){
        if(B == 0){
            s.insert(v);
        }
        return;
    }
    else if(B == 0){
        s.insert(v);
        return;
    }
    
    if(A[ind] <= B){
        solve(A,v,B,ind+1);
        v.push_back(A[ind]);
        solve(A,v,B-A[ind],ind);
    }
    else{
        solve(A,v,B,ind+1);
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    sort(A.begin(),A.end());
    vector<int> v;
    
    vector<vector<int>> vec;
    
    int ind = 0;
    
    solve(A,v,B,ind);
    
    set<vector<int>> :: iterator it;
    
    for(it = s.begin(); it!=s.end(); it++){
        vec.push_back(*it);
    }
    s.clear();
    sort(vec.begin(),vec.end());
    return vec;
}
