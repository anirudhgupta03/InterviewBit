void solve(int ind, int B, vector<int> &num, vector<int> &p, vector<vector<int>> &v){
    
    if(p.size() == B){
        v.push_back(p);
        return;
    }
    
    p.push_back(num[ind]);
        
    solve(ind+1,B,num,p,v);
        
    p.pop_back();

    if(B - p.size() < num.size() - ind){
        solve(ind+1,B,num,p,v);
    }
}
vector<vector<int> > Solution::combine(int A, int B) {
    
    vector<int> num;
    
    for(int i = 1; i <= A; i++){
        num.push_back(i);
    }
    
    vector<int> p;
    vector<vector<int>> v;
    
    if(B > A){
        return v;
    }
    solve(0,B,num,p,v);
    
    return v;
}
