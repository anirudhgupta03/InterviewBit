//Method - 1
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

//Method - 2
vector<vector<int> > Solution::subsets(vector<int> &A) {

    sort(A.begin(), A.end());
    int n = A.size();

    vector<vector<int>> res;
    for(int i = 0; i < (1 << n); i++){ 
        vector<int> temp;
        for(int j = 0; j < n; j++){
            int mask = (i & (1 << j));
            if(mask != 0){
                temp.push_back(A[j]);
            }
        }
        res.push_back(temp);
    }
    sort(res.begin(), res.end());
    return res;
}
