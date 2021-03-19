void solve(vector<vector<int>> &vec,vector<int> &v,int B,vector<int> &p, int ind){
    
    if(B == 0){
        vec.push_back(p);
        return;
    }
    for(int i = ind; i < v.size(); i++){
            p.push_back(v[i]);
            solve(vec,v,B-1,p,i+1);
            p.pop_back();
    }
}
vector<vector<int> > Solution::combine(int A, int B) {
    
    vector<int> v(A);
    
    for(int i = 0; i < A; i++){
        v[i] = i + 1;
    }
    
    vector<vector<int>> vec;
    
    vector<int> p;
    
    solve(vec,v,B,p,0);
    
    sort(vec.begin(),vec.end());
    
    return vec;
}
